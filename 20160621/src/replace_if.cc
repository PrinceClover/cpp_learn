 ///
 /// @file    replace_if.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-24 19:37:50
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> vecInt = {1,2,3,4,5,6};
	//BinaryPredicate 
	std::less<int> lt;
	//need a UnaryPreducate in replace_if,use bind1st function adapter
	replace_if(vecInt.begin(), vecInt.end(),bind1st(lt,3), 7);

	for(auto & elem : vecInt)
		cout << elem <<" ";
	cout << endl;
	return 0;
}

