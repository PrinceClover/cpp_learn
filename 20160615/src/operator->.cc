 ///
 /// @file    operator->.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-15 20:05:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
	int size()
	{
		return 5;
	}
};

class DataPtr
{
public:
	DataPtr()
	: _pData(new Data)
	{
		cout << "constructor" << endl;
	}

	~DataPtr()
	{
		delete _pData;
	}

	Data * operator->()
	{
		return _pData;
	}
private:
	Data * _pData;
};

int main(void)
{
	DataPtr p;
	cout << p->size() << endl;//equal to nextline
	cout << (p.operator->())->size() << endl;
	return 0;
}
