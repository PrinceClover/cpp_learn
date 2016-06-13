 ///
 /// @file    stack.h
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-13 20:55:34
 ///
#ifndef __STACK_H__
#define __STACK_H__

#include<vector>
using std::vector;
#define MAX_STACK_SIZE 10		//max size of stack(vector)
class numberStack
{
public:
	//constructor and destructor
	numberStack();
	~numberStack();

	//push an element into stack
	void push(int);

	//pop an element from stack
	int pop();

	//read top element
	int top();

	//the stack is empty/full
	bool empty();
	bool full();
private:
	//int __stack_num[10];
	vector<int> __stack;
};


#endif
