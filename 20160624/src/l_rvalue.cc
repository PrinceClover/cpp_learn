 ///
 /// @file    l_rvalue.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-24 14:55:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	int a = 1;
//	&(a++);
	a = std::move(a);
	cout << a << endl;
	return 0;
}
