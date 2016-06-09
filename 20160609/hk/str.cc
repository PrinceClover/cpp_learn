 ///
 /// @file    str.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 22:18:12
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class String
{
public:
	//constructor
	String()
	{
		_pstr = new char[1];
		_pstr[0] = '\0';
	}
	//constructor 2
	String(const char* pstr)
	{
		_pstr = new char[strlen(pstr)+1];
		strcpy(_pstr,pstr);
	}
	//copy constructor
	String(const String & rhs)
	{
		_pstr = new char[strlen(rhs._pstr)+1];
		strcpy(_pstr,rhs._pstr);
	}
	//equel operator function overload
	String & operator = (const String & rhs)
	{
		//equal itself
		if(this == &rhs)
			return *this;
		delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr)+1];
		strcpy(_pstr,rhs._pstr);
		return *this;
	}
	//destructor
	~String()
	{
		delete [] _pstr;
	}
	//print str
	void print()
	{
		cout << _pstr << endl;
	}
private:
	char *_pstr;
};

int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3 = "wangdao";

	str2.print();
	str3.print();
	str2 = str3;
	str2.print();

	String str4 = str3;
	str4.print();
	return 0;
}
