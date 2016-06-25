 ///
 /// @file    priority_queue.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-24 21:34:21
 ///
 
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
using std::priority_queue;
using std::pair;
using std::vector;

int test0(void)
{
	int arr[10] = {1,2,3,4,5,6,7,8,9};
}

struct MyCompare
{
	bool operator()(const pair<int,bool> & lhs,
					const pair<int,bool> & rhs)
	{
		return lhs.first > rhs.first;
	}
};

int main(void)
{
	priority_queue<pair<int, bool>, 
						vector<pair<int, bool> >,
						MyCompare> quePair;
	quePair.push(std::make_pair(5,true));
	quePair.push(std::make_pair(3,false));
	quePair.push(std::make_pair(7,true));

	while(!quePair.empty())
	{
		const pair<int, bool> & elem = quePair.top();
		cout << elem.first << "-->" << elem.second << endl;
		quePair.pop();
	}

	cout << endl;
	return 0;
}
