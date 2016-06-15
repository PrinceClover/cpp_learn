 ///
 /// @file    A.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-15 16:28:28
 ///

#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}

private:
	A(const A &);
	A& operator = (const A &);
};

int main(void)
{
	A a;
	A b;
	//can't do that
//	A c(a);
//	a = b;
	return 0;
}
