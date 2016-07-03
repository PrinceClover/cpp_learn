 ///
 /// @file    copycontrol_derived2.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-01 11:28:19
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
	Derived(const char * pbuf,const char * pbuf2)
	: Base(pbuf)
	,_pbuf2(new char[strlen(pbuf2) + 1])
	{
		cout << "Derived(const char *,const char *)" << endl;
		strcpy(_pbuf2,pbuf2);
	}

	Derived(const Derived & rhs)
	:Base(rhs)
	,_pbuf2(new char[strlen(rhs._pbuf2) + 1])
	{
		strcpy(_pbuf2,rhs._pbuf2);
		cout << "Derived(cosnt Derived &)" << endl;
	}

	Derived & operator = (const Derived & rhs)
	{
		if(this != &rhs)
		{
			Base::operator=(rhs);
			delete [] _pbuf2;
			_pbuf2 = new char[strlen(rhs._pbuf2) + 1];
			strcpy(_pbuf2,rhs._pbuf2);
		}
		return * this;
	}

	~Derived()
	{
		delete [] _pbuf2;
		cout << "~Derived()" << endl;
	}

	void display()
	{
		Base::display();
		cout << _pbuf2 << endl;
	}
private:
	char * _pbuf2;
};

int main(void)
{
	Derived d1("hello",",world");
	d1.display();

	Derived d2("shenzhen",",wangdao");
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
