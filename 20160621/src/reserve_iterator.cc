 ///
 /// @file    reserve_iterator.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-25 10:07:06
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main(void)
{
	vector<int> vecInt = {1,2,3,4,5};
	ostream_iterator<int> osi(cout," ");
	
	vector<int>::reverse_iterator rit = vecInt.rbegin();

	copy(rit, vecInt.rend(), osi);
	cout << endl;
	
	return 0;
}
