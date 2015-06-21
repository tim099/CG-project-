#ifndef STRING_H_
#define STRING_H_
#include <iostream>
#include <string>
#include <vector>
namespace Tim {
class String {
public:
	String();
	virtual ~String();
	static bool getline(std::istream &is,char* line,int size,bool skip_blankline=true,bool skip_blankspace=true);
	static bool within(char c,const std::string& str);
	static void gen_array_num(char *str,int num);
	static std::string substring(std::string str,int start,int end);
	static int skip(char *str,std::string skip);
	static std::vector<std::string> split(std::string str,std::string delimiter);

};
}
#endif /* STRING_H_ */
