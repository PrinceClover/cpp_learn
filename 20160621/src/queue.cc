 ///
 /// @file    queue.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-24 21:28:53
 ///
 
#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;

int main(void)
{
	queue<int> queInt;
	for(int idx = 0; idx < 10; ++idx)
	{
		queInt.push(idx);
		cout << queInt.back() << " has enqueued" << endl;
	}

	cout << queInt.size() << " element(s) has enqueued" << endl;

	while(!queInt.empty())
	{
		cout << queInt.front() << " has dequeued" << endl;
		queInt.pop();
	}

	cout << queInt.size() << endl;
	return 0;
}
