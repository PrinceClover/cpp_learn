 ///
 /// @file    5.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-08 16:50:34
 ///
 
#include <iostream>

int main(void)
{
	const char *p1 = "hello";
	char *const p2 = "world";
	p1++;
	p1[2] = 'w';
//	p2++;
	p2[2] = 'L';
	return 0;

}
