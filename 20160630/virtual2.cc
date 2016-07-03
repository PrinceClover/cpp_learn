 ///
 /// @file    virtual2.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-01 21:48:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual
	void display()
	{
		cout << "Base::display()" << endl;
	}
private:
	int _x;
};

class Child : public Base
{
public:
	virtual
	void display()
	{
		cout << "Child::display()" << endl;
	}
private:
	int _x;
};

int main(void)
{
	Base base;
	Base * pb = &base;
	pb->display();

	Child child;
	pb = & child;
	pb->display();

	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Child) = " << sizeof(Child) << endl;

	cout << endl;
	child.display();

	cout << endl;
	Child * pc = & child;
	pc->display();

	cout << endl;
	pc = (Child*)&base;
	pc->display();

	return 0;
}
