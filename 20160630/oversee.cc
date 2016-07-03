 ///
 /// @file    oversee.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-01 10:38:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	int func(int i)
	{
		return _ix;
	}
protected:
	int _ix;
};

class Derived : public Base
{
public:
	int func()
	{
		_ix = 9;
		Base::_ix = 22;
		return _ix;
	}

	void display()
	{
		cout << "Derived::_ix = " << this->_ix << endl;
		cout << "Base::_ix = " << Base::_ix << endl;
	}
public:
	int _ix;
};

int main(void)
{
	Derived d;
	cout << d.func() << endl;
	cout << d.Base::func(3) << endl;
	d.display();
}
