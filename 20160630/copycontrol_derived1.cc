 ///
 /// @file    copycontrol_derived1.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-01 11:16:13
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Base
{
public:
	Base(const char * pbuf)
	:_pbuf(new char[strlen(pbuf) + 1])
	{
		strcpy(_pbuf, pbuf);
		cout << "Base(const char *)" << endl;
	}

	Base(const Base & rhs)
	:_pbuf(new char[strlen(rhs._pbuf) + 1])
	{
		strcpy(_pbuf,rhs._pbuf);
		cout << "Base(const Base &)" << endl;
	}

	Base & operator = (const Base &rhs)
	{
		cout << "Base & operator = (const Base &)" << endl;
		if(this != &rhs)
		{
			delete [] _pbuf;
			_pbuf = new char[strlen(rhs._pbuf) + 1];
			strcpy(_pbuf, rhs._pbuf);
		}
		return * this;
	}

	void display()
	{
		cout << _pbuf << endl;
	}
private:
	char * _pbuf;
};

class Derived : public Base
{
public:
	Derived(const char * pbuf)
	: Base(pbuf)
	{
		cout << "Derived(const char*)" << endl;
	}
};

int main(void)
{
	Derived d1("hello");
	d1.display();

	Derived d2("world");
	d2.display();
	
	cout << endl;
	d1 = d2;
	d1.display();
	d2.display();

	cout << endl;
	Derived d3 = d1;
	d3.display();

	return 0;
}
