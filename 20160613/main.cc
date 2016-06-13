 ///
 /// @file    main.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-13 22:08:29
 ///
 
#include <iostream>
#include "stack.h"
#include "queue.h"
using std::cout;
using std::endl;

int main(void)
{
	//stack
/*
//	numberStack ns;
	ns.pop();
//	for(int i = 0;i < MAX_STACK_SIZE;i++)
//	{
//		ns.push(i);
//	}
	ns.push(10);
	ns.push(12);
	ns.push(14);
	cout << "top element is " << ns.top() <<endl;
	ns.pop();
	cout << "top element is " << ns.top() <<endl;
*/

	//queue

	numberQueue nq;
	for(int i = 0;i < MAX_QUEUE_SIZE;i++)
		nq.enqueue(i);
//	nq.enqueue(1);
//	nq.enqueue(2);
//	nq.enqueue(3);
//	nq.dequeue();
	cout << "front element is " << nq.front() << endl;
	cout << "back element is " << nq.back() << endl;
	return 0;
}
