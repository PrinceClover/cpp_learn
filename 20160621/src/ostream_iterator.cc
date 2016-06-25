 ///
 /// @file    ostream_iterator.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-24 09:53:56
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main(void)
{
	vector<int> vecInt = {1,2,3,4,5,6};

	ostream_iterator<int> osi(cout," ");
	copy(vecInt.begin(),vecInt.end(),osi);

	cout << endl;
	return 0;
}
