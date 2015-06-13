#include "class/texture/Image.h"
#include <cstdio>
#include <cmath>
#include <iostream>
Image::Image() {
	format=GL_RGB;
	width=0,height=0;
	imageSize=0;   // = width*height*3
	data=0;// Actual RGB data
}
Image::Image(unsigned int _width,unsigned int _height,GLenum _format){
	initialize(_width,_height,_format);
}
Image::~Image() {
	if(data)delete[] data;
}
void Image::initialize(unsigned int _width,unsigned int _height,GLenum _format){
	format=_format;
	width=_width;
	height=_height;
	switch(format){
		case GL_RGB:
		case GL_BGR:
			imageSize=((width)*(height)*3+(width%2)*(height));
			break;
		case GL_RGBA:
			imageSize=((width)*(height)*4+(width%2)*(height));
			break;
		default:
			std::cout<<"unknow image format:"<<format<<std::endl;
	}

	data=new unsigned char [imageSize];
}
void Image::loadBMP(const char * imagepath){
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	FILE * file = fopen(imagepath,"rb");// Open the file
	if (!file){printf("Image could not be opened:%s\n",imagepath);}
	if (fread(header,1,54,file)!=54){ // If not 54 bytes read : problem
	    printf("Not a correct BMP file:%s\n",imagepath);
	}
	if (header[0]!='B'||header[1]!='M'){
	    printf("Not a correct BMP file:%s\n",imagepath);
	}
	initialize(*(int*)&(header[0x12]),*(int*)&(header[0x16]),GL_BGR);
	fread(data,sizeof(char),imageSize,file);
	format=GL_BGR;
	fclose(file);
}
void Image::convert_to_sobel(Image* image,glm::vec2 dv){
	int col;
	for(unsigned i=0;i<image->imageSize/3;i++){// convert to grey
		col=(((int)image->data[3*i]+(int)image->data[3*i+1]+(int)image->data[3*i+2])/3);
		image->data[3*i]=(unsigned char)col;
		image->data[3*i+1]=(unsigned char)col;
		image->data[3*i+2]=(unsigned char)col;
	}
	unsigned char arr[3][3];
	for(unsigned i=0;i<image->height;i++){
		for(unsigned j=0;j<image->width;j++){
			for(int l=0;l<3;l++){
				for(int m=0;m<3;m++){
					int x=j+m-1,y=i+l-1;
					if(x<0||y<0||x>=(int)image->width||y>=(int)image->height){
						arr[l][m]=0;
					}else{
						arr[l][m]=image->data[(x+y*image->width)*3];
					}
				}
			}
			int GX=-dv.y*arr[0][0]+arr[0][2]-dv.x*arr[1][0]+dv.x*arr[1][2]-dv.y*arr[2][0]+dv.y*arr[2][2];
			int GY=-dv.y*arr[0][0]+arr[2][0]-dv.x*arr[0][1]+dv.x*arr[2][1]-dv.y*arr[0][2]+dv.y*arr[2][2];
			int value=sqrt(GX*GX+GY*GY);

			image->data[3*(j+i*image->width)+2]=(unsigned char)(value<255?value:255);
		}
	}
	for(unsigned i=0;i<image->imageSize/3;i++){//convert to BMP
		image->data[3*i]=image->data[3*i+2];
		image->data[3*i+1]=image->data[3*i+2];
	}
}
