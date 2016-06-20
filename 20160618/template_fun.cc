 ///
 /// @file    template_fun.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-19 15:14:53
 ///
 
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T>
T add(const T & a,const T & b)
{
	cout << "template <> add() " << endl;
	return a + b;
}

//template specialization
template <>
char * add<char *> (char * const & a,char * const & b)
{
	char * ptmp = new char[strlen(a)+strlen(b)+1];
	sprintf(ptmp,"%s%s",a,b);
	return ptmp;
}

int main(void)
{
	cout << add(10,20) << endl;
//	char p1[10] = "hello";
//	char p2[10] = " world";
	char * p1  = new char[10];
	char * p2 = new char[10];
	strcpy(p1,"hello ");
	strcpy(p2,"world");
	char *p3 = add(p1,p2);
	cout << p3 << endl;

	return 0;
}








