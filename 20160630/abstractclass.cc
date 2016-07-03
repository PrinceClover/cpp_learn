 ///
 /// @file    virtual2.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-01 21:10:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
//abstract class
protected:
	Base(int x = 0)
	: _x(x)
	{}

public:
	void display()
	{
		cout << "Base::_x = " << _x << endl;
	}
private:
	int _x;
};

class Child : public Base
{
public:
	Child(int x) : Base(x)
	{}
};

int main(void)
{
	//Base base;
	Child child(10);
	child.display();
	return 0;
}
