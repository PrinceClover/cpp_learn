 ///
 /// @file    String.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-16 21:49:21
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator = (const String & rhs);
	~String();

	int useCount()
	{
		return _pstr[length() + 1];
	}

	int length()
	{
		return strlen(_pstr);
	}
	
	void increaseRefcount();
	void decreaseRefcount();

	char & operator[](int idx);
	char & operator[](int idx) const;
private:
	char * _pstr;
};

String::String()
:_pstr(new char[2])
{
	//quote count
	_pstr[1] = 1;
	cout << "String constructor" << endl;
}

String::String(const char * pstr)
{
	int len = strlen(pstr);
	_pstr = new char[len + 2];
	strcpy(_pstr,pstr);
	//set qoute count to 1
	_pstr[len + 1] = 1;
	cout << "String constructor: pstr" << endl;
}

String::String(const String & rhs)
:_pstr(rhs._pstr)
{
	increaseRefcount();
	cout << "String constructor: String" << endl;
}

String & String::operator = (const String & rhs)
{
	if(this != &rhs)
	{
		decreaseRefcount();
		if(useCount() == 0)
		{
			delete [] _pstr;
		}
		//shallow copy
		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return *this;
}

String::~String()
{
	decreaseRefcount();
	if(useCount() == 0)
	{
		delete [] _pstr;
		cout << "~String " << endl;
	}
}

char & String::operator[](int idx) const
{
	cout << "[] operator const" << endl;
	return _pstr[idx];
}

char & String::operator[](int idx)
{
	if(idx >= 0 && idx < length())
	{
		if(useCount() == 1)
		{
			return _pstr[idx];
		}
		else
		{
			if(1)
			{
				decreaseRefcount();
				char * ptmp = new char[length() + 2];
				strcpy(ptmp,_pstr);
				_pstr = ptmp;
				_pstr[length() + 1] = 1;
				return _pstr[idx];
			}
			else
			{
				return _pstr[idx];
			}
		}
	}
	else
	{
		static char nullchar = '\0';
		cout << "array out of bounds" << endl;
		return nullchar;
	}
}

void String::increaseRefcount()
{
	++_pstr[length() + 1];
}

void String::decreaseRefcount()
{
	--_pstr[length() + 1];
}

int main(void)
{
	String s1 = "hello,world";
	String s2 = s1;
	String s3 = s2;

	cout << "s1's useCnt = " << s1.useCount() << endl;
	cout << "s2's useCnt = " << s2.useCount() << endl;
	cout << "s3's useCnt = " << s3.useCount() << endl;
	cout << endl;

	String s4 = "wangdao";
	cout << "s4's useCnt = " << s4.useCount() << endl;
	cout << endl;
	s4 = s2;
	cout << "s1's useCnt = " << s1.useCount() << endl;
	cout << "s2's useCnt = " << s2.useCount() << endl;
	cout << "s3's useCnt = " << s3.useCount() << endl;
	cout << "s4's useCnt = " << s4.useCount() << endl;
	cout << endl;

	s4[0] = 'H';
	cout << "s1's useCnt = " << s1.useCount() << endl;
	cout << "s2's useCnt = " << s2.useCount() << endl;
	cout << "s3's useCnt = " << s3.useCount() << endl;
	cout << "s4's useCnt = " << s4.useCount() << endl;
	cout << endl;

	cout << s3[0] << endl;
	cout << "s1's useCnt = " << s1.useCount() << endl;
	cout << "s2's useCnt = " << s2.useCount() << endl;
	cout << "s3's useCnt = " << s3.useCount() << endl;
	cout << endl;

	return 0;
}
