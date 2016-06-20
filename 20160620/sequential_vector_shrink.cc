 ///
 /// @file    sequential_vector_shrink.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-20 19:54:36
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> vecInt = {1,2,3};
	cout << "vecInt's capacity: " << vecInt.capacity() << endl;
	vecInt.resize(10);
	for(auto & elem : vecInt)
		cout << elem << " ";
	cout << endl << "vecInt's capacity: " << vecInt.capacity() << endl;
	vecInt.resize(100);
	cout << "vecInt's capacity: " << vecInt.capacity() << endl;
	vecInt.clear();

	cout << "vecInt's capacity: " << vecInt.capacity() << endl;
	vecInt.push_back(1);
	vecInt.push_back(2);
	vecInt.push_back(3);
	cout << "vecInt's size: " << vecInt.size() << endl;
	cout << "vecInt's capacity: " << vecInt.capacity() << endl;

	//vector<int>(vecInt).swap(vecInt);
	//equal to
	vecInt.shrink_to_fit();

	for(auto & elem : vecInt) cout << elem <<" ";
	cout << endl;
	cout << "vecInt's capacity: " << vecInt.capacity() << endl;
	return 0;
}
