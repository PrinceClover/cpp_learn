 ///
 /// @file    teeplate_class.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-19 15:51:51
 ///
 
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

template <typename T,int num>
class Stack
{
public:
	Stack();
	~Stack();

	bool full();
	bool empty();
	bool push(T elem);
	bool pop(T &);
	int & getPos()
	{
		return _top;
	}
private:
	int _top;
	T _parr[num];
};

template <typename T,int num>
Stack<T,num>::Stack()
: _top(-1){}

template <typename T,int num>
Stack<T,num>::~Stack(){}

template <typename T,int num>
bool Stack<T,num>::full()
{
	return _top == (num -1);
}

template <typename T,int num>
bool Stack<T,num>::empty()
{
	return _top == -1;
}

template <typename T,int num>
bool Stack<T,num>::push(T elem)
{
	if(!full())
	{
		_parr[++_top] = elem;
		return true;
	}
	return false;
}

template <typename T,int num>
bool Stack<T,num>::pop(T &t)
{
	if(!empty())
	{
		t = _parr[_top--];
		return true;
	}
	else 
		return false;
}

int main(void)
{
	Stack<string,10> stackString;
	cout << "empty = " << stackString.empty() << endl;
	stackString.push("aa");
	cout << "empty = " << stackString.empty() << endl;

	for(int i = 0;i != 10;++i)
	{
		string s(2,'a'+i);
		stackString.push(s);
	}

	cout << "full = " << stackString.full() << endl;

	for(int i = 0;i != 10;++i)
	{
		string elem;
		stackString.pop(elem);
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}
