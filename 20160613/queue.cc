 ///
 /// @file    queue.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-13 22:27:19
 ///

#include "queue.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

numberQueue::numberQueue()
{
	__queue.reserve(MAX_QUEUE_SIZE);
}

numberQueue::~numberQueue(){}

void numberQueue::enqueue(int elem)
{
	if(full())
	{
		cout << "queue overflow!" << endl;
		exit(-1);
	}
	__queue.push_back(elem);
}

int numberQueue::dequeue()
{
	if(empty())
	{
		cout << "queue is empty" << endl;
		exit(-1);
	}
	int elem = __queue.front();
	__queue.erase(__queue.begin());
	return elem;
}

int numberQueue::front()
{
	return __queue.front();
}

int numberQueue::back()
{
	return __queue.at(__queue.size()-1);
}

bool numberQueue::empty()
{
	return __queue.empty();
}

bool numberQueue::full()
{
	if(__queue.size() == __queue.capacity())
		return true;
	else
		return false;
}
