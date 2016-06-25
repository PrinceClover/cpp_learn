 ///
 /// @file    istream_iterator.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-24 09:59:29
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::vector;

int main(void)
{
	vector<int> vecInt;
	istream_iterator<int> isi(cin);

	copy(isi,istream_iterator<int>(),back_inserter(vecInt));

	for(auto & elem : vecInt)
		cout << elem << " " ;
	cout << endl;

	return 0;
}
