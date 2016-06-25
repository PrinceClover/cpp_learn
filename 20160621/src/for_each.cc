 ///
 /// @file    for_each.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-24 10:12:45
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

void print(vector<int>::value_type & v)
{
	v += 7;
	cout << v << " ";
}

int main(void)
{
	vector<int> vecInt = {1,2,3,4,5,6};
	for_each(vecInt.begin(), vecInt.end(), print);
	cout << endl;

	for(auto & elem:vecInt)
		cout << elem << " ";
	cout << endl;
	return 0;
}
