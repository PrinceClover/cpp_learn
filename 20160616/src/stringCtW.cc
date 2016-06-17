 ///
 /// @file    stringCtW.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-16 20:51:37
 ///
 
#include <iostream>
#include <stdio.h>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string s1 = "hello,world";
	string s2 = s1;
	string s3 = s1;
	string s4 = "hello,world";

	printf("s1's address: %p\n",s1.c_str());
	printf("s2's address: %p\n",s2.c_str());
	printf("s3's address: %p\n",s3.c_str());
	printf("s4's address: %p\n",s4.c_str());

	cout << endl;
	s3[0] = 'H';
	printf("s1's address: %p\n",s1.c_str());
	printf("s2's address: %p\n",s2.c_str());
	printf("s3's address: %p\n",s3.c_str());

	return 0;
}
