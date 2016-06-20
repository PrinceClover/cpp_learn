 ///
 /// @file    template_int.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-19 14:17:45
 ///

//#include "func.h"
#include <iostream>
using std::cout;
using std::endl;

#define MAX 10;
const int a = 10;

//statement and definition of template must in same file
template <typename T,int num>
T func(T a)
{
	return a * num;
}

int main(void)
{
	cout << func<int ,4>(3) << endl;
	return 0;
}
