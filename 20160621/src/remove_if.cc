 ///
 /// @file    remove_if.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-24 20:15:25
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int test(void)
{
	vector<string> vecStr;
	vecStr.push_back("hello");
	int i = 0;

	auto it = vecStr.begin();
	for(;it != vecStr.end(); ++it)
	{
		cout << "vecStr.capacity is " << vecStr.capacity() << endl;
		cout << *it << endl;
		if(0 == i)
		{
			//vector capacity has changed,iterator lost it's efficacy
			//than program crash =v=
			vecStr.push_back("world");
			cout << "vecStr.push !" << endl;
			i = 1;
		}
	}
}

int main(void) 
{
	//test();
	vector<int> vecInt;
	vecInt.reserve(10);
	cout << vecInt.size() << endl;
	cout << vecInt.capacity() << endl;

	for(int idx = 1;idx <= 10;++idx)
	{
		vecInt.push_back(idx);
	}

	vecInt[3] = vecInt[5] = vecInt[9] = 99;
	for(auto & elem : vecInt)
		cout << elem << " ";
	cout << endl;
	
	//erase/remove usage
	cout << "after delete 99" << endl;
	vecInt.erase(std::remove(vecInt.begin(), vecInt.end(), 99), vecInt.end());

	for(auto & elem : vecInt)
	{
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}
