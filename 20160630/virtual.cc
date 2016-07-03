 ///
 /// @file    virtual.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-01 17:22:55
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual int func(int x)
	{
		cout << "Base::func(int)" << endl;
		return x;
	}
};

class Derived : public Base
{
public:
	int func(int x)
	{
		cout << "Derived::func(int)" << endl;
		return x;
	}
};

void test(Base & base)
{
	cout << "x = " << base.func(5) << endl;
}

int main(void)
{
	Base base;
	Derived derived;
	test(base);
	test(derived);

	cout << endl;
	derived.func(6);

	Base & ref = derived;
	ref.func(7);
	cout << endl;

	Base * pbase = &derived;
	pbase->func(10);

	return 0;
}
