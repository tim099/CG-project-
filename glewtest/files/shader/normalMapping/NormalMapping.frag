#version 400 core
#define MAX_POINTLIGHT 100 
#define MAX_PARALLELLIGHT 10 

in vec2 UV;
in vec3 Normal;
in vec4 position;
in vec4 MVP_pos;

layout(location = 0)out vec4 color;

uniform sampler2D myTextureSampler;
uniform sampler2D NormalTexture;
uniform sampler2D depthMap[MAX_PARALLELLIGHT];
uniform sampler2D pointdepthMap[6];
//uniform samplerCube cubemap;


uniform vec3 camera_pos;

uniform int parallellight_num;
uniform vec3 parallellight_vec[MAX_PARALLELLIGHT];
uniform vec3 parallellight_color[MAX_PARALLELLIGHT];

uniform int pointlight_num;
uniform vec3 pointlight_pos[MAX_POINTLIGHT];
uniform vec3 pointlight_color[MAX_POINTLIGHT];

uniform mat4 pointLVP[6];
uniform mat4 parallelLVP[MAX_PARALLELLIGHT];

uniform vec4 mat;
uniform mat4 VP;
uniform mat4 biasMat;

vec3 PD[9] = vec3[](
  	vec3(0,0,0.4),
  	vec3(0,0.0006,0.1),
  	vec3(0,-0.0006,0.1),
  	vec3(0.0006,0,0.1),
  	vec3(-0.0006,0,0.1),
  	vec3(0.0006,0.0006,0.05),
  	vec3(0.0006,-0.0006,0.05),
  	vec3(-0.0006,0.0006,0.05),
  	vec3(-0.0006,-0.0006,0.05)
);
vec3 toon(vec3 col,float val){	
	float toncolval=(1.0/val)*floor(val*length(col.xyz)+0.5);
	return toncolval*col;
}
int check_vec(vec3 v){
	if(abs(v.x)>=abs(v.z)){
		if(abs(v.x)>=abs(v.y)){//x=max
			if(v.x>=0.0f)return 0;
			else return 1;
		}else{//y=max
			if(v.y>=0.0f)return 2;
			else return 3;
		}
	}else if(abs(v.y)>=abs(v.z)){//y==max
		if(v.y>=0.0f)return 2;
		else return 3;
	}else{//z==max
		if(v.z>=0.0f)return 4;
		else return 5;
	}
	return 0;
}
vec3 point_light(vec3 N,vec4 pos){
	vec3 total_light=vec3(0,0,0);
    vec3 light_v,reflect_v;
    vec3 pos_cam_v=normalize(pos.xyz-camera_pos);
    float light_dis,light_val,specular_val,w,z_val,bias,del;
    vec4 LVP_pos;
	float visibility;
    for(int i=0;i<pointlight_num;i++){
    	//diffuse
        light_v=pointlight_pos[i]-pos.xyz;
    	light_dis=length(light_v);
    	light_val=mat.x*dot(N,normalize(light_v));
    	//specular
		reflect_v=light_v-(2*dot(Normal,light_v))*N;		
		specular_val=dot(pos_cam_v,normalize(reflect_v));
		if(specular_val>0.0f){
			light_val+=mat.y*pow(specular_val,mat.w);			
		}
		light_val/=(light_dis*light_dis);
		if(light_val<0.0)light_val=0.0;	
		
		if(i==0){//only do for light 0
			int n=check_vec(light_v);
			LVP_pos=biasMat*pointLVP[n]*pos;	
			w=LVP_pos.w;
			LVP_pos/=w;		
			visibility=0.0;

   	 		z_val=(texture2D(pointdepthMap[n],LVP_pos.xy).x);//shadowMapDepth/LVP_pos.w
			del=z_val-LVP_pos.z;	
			bias=0.0002*tan(acos(dot(N,light_v)));
			bias=-clamp(bias,0.0,0.0002)/w;
			if((del>=bias)){
				visibility=1.0; 	
			}

			total_light+=visibility*light_val*pointlight_color[i];	     		
		}else{
			total_light+=light_val*pointlight_color[i];	
		}	
			
    }
	return total_light;
}
vec3 parallel_light(vec3 N,vec4 pos){
	vec3 total_light=vec3(0,0,0);
    vec3 light_v;
    vec3 reflect_v;
    vec3 pos_cam_v=normalize(pos.xyz-camera_pos);

    float light_val;
    float specular_val;
    
    vec4 LVP_pos;
    vec2 t;	
    float z_val;
	float bias,del;
	float visibility;
    for(int i=0;i<parallellight_num;i++){   	 	
		//diffuse
		light_v=normalize(-parallellight_vec[i]);//reverse	
		light_val=mat.x*dot(N,light_v);
		//specular
		reflect_v=light_v-(2*dot(Normal,light_v))*N;
		specular_val=dot(pos_cam_v,normalize(reflect_v));
		if(specular_val>0.0f){
			light_val+=mat.y*pow(specular_val,mat.w);			
		}
		if(light_val<0.0)light_val=0.0;
		
		LVP_pos=biasMat*parallelLVP[i]*pos;
   		LVP_pos/=LVP_pos.w;
   		visibility=0.0;
   		for(int j=0;j<9;j++){
   	 		t=LVP_pos.xy+PD[j].xy;//LVP_pos.w 	
   	 		z_val=(texture2D(depthMap[i],t).x);//shadowMapDepth/LVP_pos.w
			del=z_val-LVP_pos.z;	
			bias=0.0002*tan(acos(dot(N,light_v)));
			bias=-clamp(bias,0.0,0.0002);
		
			if((t.x<=1.0&&t.y<=1.0&&t.x>=0.0&&t.y>=0.0)){//in depth map
				if((del>bias)){				
				 	  visibility+=PD[j].z; 	   	
    			}
			}		
		}
		total_light+=visibility*light_val*parallellight_color[i];
    }
    return total_light;
}
void main(){ 
	vec3 T,B;
	if(Normal!=vec3(0.3,0.3,0.3))T=normalize(cross(Normal,vec3(0.3,0.3,0.3)));
	else T=normalize(cross(Normal,vec3(0.31,0.29,0.31)));
	B=normalize(cross(Normal,T));
	
	mat3 TBN=mat3(T,B,Normal);
	
	vec3 tex_color=(texture(myTextureSampler,UV).rgb);	
	vec3 tex_normal=(2*(texture(NormalTexture,UV).rgb))-1;
	
    vec3 total_light=parallel_light(normalize(TBN*tex_normal),position)
    	+point_light(normalize(TBN*tex_normal),position);
    //vec3 total_light=parallel_light(Normal,position)
    	//+point_light(Normal,position); 	
    	
    vec4 o_pos=gl_FragCoord;//vec4(position,1);//inverse(VP)*MVP_pos;
    
    color = vec4((total_light+mat.z)*tex_color,1.0);
    //color = vec4(toon((total_light+mat.z),5.0)*tex_color,1.0);//

}