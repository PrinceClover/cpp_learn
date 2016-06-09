 ///
 /// @file    com.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 21:14:48
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer
{
public:
	//constructor
	Computer(const char * brand,float fprice)
	//shallow copy
	//:_brand(brand)
	:_fprice(fprice)
	{
		cout << "constructor" << endl;
		//deep copy
		_brand = new char[strlen(brand)+1];
		strcpy(_brand,brand);
	}
	
	//destructor
	~Computer()
	{
		delete []_brand;
		cout << "destructor" << endl;
	}

	//print member variables
	void print()
	{
		cout << "brand" << _brand << endl;
		cout << "price" << _fprice << endl;
	}
private:
	char *_brand;
	float _fprice;
};

Computer pc("Mac",10000);

int main(void)
{
	cout << "Enter main()" << endl;
	int a = 3;
	{
		Computer com("Dell",7000);
		com.print();
	}
	static Computer pc2("IBM",5000);

	Computer *p = new Computer("Thinkpad",6000);
	delete p;

	return 0;
}
