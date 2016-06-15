 ///
 /// @file    operator[].cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-15 16:48:08
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class CharArr
{
public:
	CharArr(int size)
	:_size(size)
	{
		_pstr = new char[_size];
	}

	~CharArr()
	{
		delete _pstr;
	}

	int length()
	{
		return _size;
	}

	char & operator[](int idx)
	{
		static char nullchar = '\0';
		if(idx < _size && idx >= 0)
		{
			return _pstr[idx];
		}
		else
		{
			cout << "out of buonds" << endl;
			return nullchar;
		}
	}
private:
	int _size;
	char * _pstr;
};

int main(void)
{
	const char * p = "hello,world!";
	CharArr ca(strlen(p)+1);

	for(int idx = 0;idx != ca.length();idx++)
	{
		ca[idx] = p[idx];
	}

	for(int idx = 0;idx != ca.length();idx++)
	{
		cout << ca[idx];
	}
	cout << endl;
	return 0;
}
