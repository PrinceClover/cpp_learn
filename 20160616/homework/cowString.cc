 ///
 /// @file    cowString.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-17 22:29:06
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::ostream;

class String
{
private:
	class CharProxy
	{
	//proxy pattern
	public:
		CharProxy(String & str,int idx);
		char & operator = (char ch);
		operator char()
		{
			return _str._pstr[_idx];
		}
	private:
		String & _str;
		int _idx;
	};
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator = (const String & rhs);
	~String();

	int useCount()
	{
		return _pstr[length()+1];
	}

	int length()
	{
		return strlen(_pstr);
	}
	
	CharProxy operator[](int idx);
	char & operator[](int idx) const;
private:
	void initRefcount()
	{
		_pstr[length()+1] = 1;
	}

	void increaseRefcount()
	{
		++_pstr[length()+1];
	}

	void decreaseRefcount()
	{
		--_pstr[length()+1];
	}
private:
	char * _pstr;
};

String::String()
:_pstr(new char[2])
{
	cout << "String constructor" << endl;
	initRefcount();
}

String::String(const char * pstr)
{
	int len = strlen(pstr);
	_pstr = new char[len + 2];
	strcpy(_pstr,pstr);
	initRefcount();
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
		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return * this;
}

String::~String()
{
	decreaseRefcount();
	if(useCount() == 0)
	{
		delete [] _pstr;
		cout << "~String" << endl;
	}
}

String::CharProxy String::operator[](int idx)
{
	return CharProxy(*this,idx);
}

String::CharProxy::CharProxy(String & str,int idx)
:_str(str)
,_idx(idx)
{}

char & String::CharProxy::operator = (char ch)
{
	if(_idx >= 0 && _idx < _str.length())
	{
		if(_str._pstr[_idx] == ch)
			return _str._pstr[_idx];
		if(_str.useCount()==1)
		{
			_str._pstr[_idx] = ch;
			return _str._pstr[_idx];
		}
		_str.decreaseRefcount();
		char * ptmp = new char[_str.length() + 2];
		strcpy(ptmp,_str._pstr);
		_str._pstr = ptmp;
		_str.initRefcount();
		_str._pstr[_idx] = ch;
		return _str._pstr[_idx];
	}
	else
	{
		static char nullchar = '\0';
		cout << "out of array bounds" << endl;
		return nullchar;
	}
}


int main(void)
{
	String s1 = "hello,world";
	String s2 = s1;
	String s3 = s2;

	cout << "s1' useCnt = " << s1.useCount() << endl;
	cout << "s2' useCnt = " << s2.useCount() << endl;
	cout << "s3' useCnt = " << s3.useCount() << endl;
	cout << endl;

	String s4 = "wangdao";
	cout << "s4' useCnt = " << s4.useCount() << endl;
	cout << endl;

	s4 = s2;
	cout << "s1' ustCnt = " << s1.useCount() << endl;
	cout << "s2' ustCnt = " << s2.useCount() << endl;
	cout << "s3' ustCnt = " << s3.useCount() << endl;
	cout << "s4' ustCnt = " << s4.useCount() << endl;
	cout << endl;

	s4[0] = 'w';
	cout << "s1' ustCnt = " << s1.useCount() << endl;
	cout << "s2' ustCnt = " << s2.useCount() << endl;
	cout << "s3' ustCnt = " << s3.useCount() << endl;
	cout << "s4' ustCnt = " << s4.useCount() << endl;
	cout << endl;


	cout << s3[0] << endl;
	cout << "s1' ustCnt = " << s1.useCount() << endl;
	cout << "s2' ustCnt = " << s2.useCount() << endl;
	cout << "s3' ustCnt = " << s3.useCount() << endl;
	cout << endl;

	return 0;
}
