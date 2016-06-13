 ///
 /// @file    queue.h
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-13 22:19:18
 ///
 
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <vector>
using std::vector;

#define MAX_QUEUE_SIZE 10		//max size of queue

class numberQueue
{
public:
	//constructor and destructor
	numberQueue();
	~numberQueue();

	//enqueue and dequeue
	void enqueue(int);
	int dequeue();

	//read head/tail element of queue
	int front();
	int back();

	//the queue is empty/full
	bool empty();
	bool full();
private:
	//insert element from vactor tail
	vector<int> __queue;
};


#endif
