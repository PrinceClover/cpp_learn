 ///
 /// @file    str.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 22:18:12
 ///
 
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::cin;
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

	//equel operator function overload 1
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

	//equel operator function overload 2
	String & operator = (const char* pstr)
	{
		//equal itself
		if(!strcmp(_pstr,pstr))
			return *this;
		delete [] _pstr;
		_pstr = new char[strlen(pstr)+1];
		strcpy(_pstr,pstr);
		return *this;
	}

	//operator overload += 1
	String & operator += (const String & rhs)
	{
		char *temp = new char [strlen(_pstr)+1];
		strcpy(temp,_pstr);
		delete [] _pstr;
		_pstr = new char[strlen(temp)+strlen(rhs._pstr)+1];
		sprintf(_pstr,"%s%s",temp,rhs._pstr);
		delete [] temp;
		temp = NULL;
		return *this;
	}

	//operator overload += 2
	String & operator += (const char* pstr)
	{
		char *temp = new char[strlen(_pstr)+1];
		strcpy(temp,_pstr);
		delete [] _pstr;
		_pstr = new char[strlen(temp)+strlen(pstr)+1];
		sprintf(_pstr,"%s%s",temp,pstr);
		delete [] temp;
		temp = NULL;
		return *this;
	}

	//operator overload [] 
	char & operator [] (std::size_t index)
	{
		if((index < 0) || (index > strlen(_pstr)-1))
		{
			cout << "segmentation fault : String" << endl;
			exit(-1);
		}
		return _pstr[index];
	}

	//operator overload [] const
	const char & operator [] (std::size_t index) const
	{
		if((index < 0) || (index > strlen(_pstr) - 1))
		{
			cout << "segmentation fault : String" << endl;
			exit(-1);
		}
		return _pstr[index];
	}

	//String size
	std::size_t size() const
	{
		return strlen(_pstr);
	}

	//turn to string in c
	const char * c_str() const
	{
		return _pstr;
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

	//friend functions:operator overload == != < > <= >=
	//and stream << >>
	friend bool operator == (const String &lhs,const String &rhs)
	{
		return strcmp(lhs._pstr,rhs._pstr) == 0;
	}
	friend bool operator != (const String &lhs,const String &rhs)
	{
		return strcmp(lhs._pstr,rhs._pstr) != 0;
	}
	
	friend bool operator < (const String &lhs,const String &rhs)
	{
		return strcmp(lhs._pstr,rhs._pstr) < 0;
	}
	friend bool operator > (const String &lhs,const String &rhs)
	{
		return strcmp(lhs._pstr,rhs._pstr) > 0;
	}
	friend bool operator <= (const String &lhs,const String &rhs)
	{
		return strcmp(lhs._pstr,rhs._pstr) <= 0;
	}
	friend bool operator >= (const String &lhs,const String &rhs)
	{
		return strcmp(lhs._pstr,rhs._pstr) >= 0;
	}

	friend std::ostream & operator << (std::ostream &os,const String &s)
	{
		return os << s._pstr;
	}
	friend std::istream & operator >> (std::istream &is,String &s)
	{
		return is >> s._pstr;
	}
private:
	char *_pstr;
};

//operator overload +
String operator + (const String &lhs,const String &rhs)
{
	String t_s;
	t_s += lhs;
	t_s += rhs;
	return t_s;
}

String operator + (const String &lhs,const char *pstr)
{
	String t_s;
	t_s += lhs;
	t_s += pstr;
	return t_s;
}

String operator + (const char * pstr,const String &rhs)
{
	String t_s;
	t_s += pstr;
	t_s += rhs;
	return t_s;
}

int main(void)
{
	String str2 = "wangdao";
	String str3 = "wang";
	String str4 = str2 + str3;
	str4.print();
	str4 = str2 + "wang";
	str4.print();
	str4 = "wang" + str2;
	str4.print();
	str4 = str3 + "dao" + "c++";
	str4.print();
	cout << (str2 == str3) << endl;
	cin >> str2;
	return 0;
}
