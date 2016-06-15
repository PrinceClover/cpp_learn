 ///
 /// @file    operator().cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-15 19:54:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Demo
{
public:
	double operator()(double x,double y)
	{
		return x > y ? x : y;
	}

	double operator()(double x,double y,double z)
	{
		return (x + y) * z;
	}
};

int main(void)
{
	Demo demo;
	cout << "the bigger number in 3 and 4 is " << demo(3,4) << endl;
	cout << "(3 + 4) * 5 is " << demo(3,4,5) << endl;
	return 0;
}
