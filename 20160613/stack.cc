 ///
 /// @file    stack.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-13 21:24:01
 ///

#include "stack.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::vector;

numberStack::numberStack()
{
	__stack.reserve(MAX_STACK_SIZE);
}

numberStack::~numberStack(){}

void numberStack::push(int elem)
{
	if(full())
	{
		cout << "stack overflow!" << endl;
		exit(-1);
	}
	__stack.push_back(elem);
}

int numberStack::pop()
{
	if(empty())
	{
		cout << "stack is empty!" << endl;
		exit(-1);
	}
	int elem = __stack.at(__stack.size()-1);
	__stack.pop_back();
	return elem;
}

int numberStack::top()
{
	return __stack.at(__stack.size()-1);
}

bool numberStack::empty()
{
	return __stack.empty();
}

bool numberStack::full()
{
	if(__stack.size() == __stack.capacity())
		return true;
	else
		return false;
}
