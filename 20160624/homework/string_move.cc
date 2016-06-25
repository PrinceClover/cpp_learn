 ///
 /// @file    string_move.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-24 18:49:29
 ///

//complie with c++11

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class String
{
	friend std::ostream & operator << (std::ostream & os,const String & rhs);
public:
	String();
	~String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator = (const String & rhs);
	
	//move semantics constructor
	String(String && rhs);
	//move semantics operator overload
	String & operator = (String && rhs);

	//swap string (shallow copy)
	void swap(String & str);
private:
	char * _pstr;
};

std::ostream & operator << (std::ostream & os,const String & rhs)
{
	os << rhs._pstr;
	return os;
}


String::String()
:_pstr(new char[1])
{
	cout << "String()" << endl;
}

String::~String()
{
	delete [] _pstr;
	cout << "~String()" << endl;
}

String::String(const char * pstr)
:_pstr(new char[strlen(pstr) + 1])
{
	strcpy(_pstr, pstr);
	cout << "String(const char * )" << endl;
}

String::String(const String & rhs)
:_pstr(new char[strlen(rhs._pstr) + 1])
{
	strcpy(_pstr,rhs._pstr);
	cout << "String(String & )" << endl;
}

String::String(String && rhs)
:_pstr(rhs._pstr)
{
	rhs._pstr = NULL;
	cout << "String(String && )" << endl;
}

void String::swap(String & str)
{
	char * temp = _pstr;
	_pstr = str._pstr;
	str._pstr = temp;
}

String & String::operator = (const String & rhs)
{
	if(this != &rhs)
	{
		String tmp(rhs);
		swap(tmp);
	}
	cout << "operator = (const String & )" << endl;
	return *this;
}

String & String::operator = (String && rhs)
{
	delete [] _pstr;
	_pstr = rhs._pstr;
	rhs._pstr = NULL;
	cout << "operator = (String && rhs)" << endl;
	return *this;
}

int main(void)
{
	String s1 = "String 1";
	String s2 = "String 2";
	String s3 = String("String 3");
	cout << "s1 = " << s1 << endl
		 << "s2 = " << s2 << endl
		 << "s3 = " << s3 << endl;

	s3 = s2;
	cout << "s3 = " << s3 << endl;
	
	cout << "std::move(s1) = " << std::move(s1) << endl;
	cout <<	"s1 = " << s1 << endl;
	
	s2 = std::move(s1);
	cout << "s2 = " << s2 << endl;
	cout << "s1 = " << s1 << endl;	//exit

	cout << endl;	
	return 0;
}
