 ///
 /// @file    1.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-08 17:27:50
 ///
 
#include <iostream>
void func(const int & v1, const int & v2)
{
		std::cout << v1 << ' ';
		std::cout << v2 << ' ';
}

int main(void)
{
		int i = 0;
		func(++i, i++);
		return 0;
}
