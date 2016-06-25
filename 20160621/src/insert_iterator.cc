 ///
 /// @file    insert_iterator.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-25 10:13:16
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::list;

template <typename Container>
void printElements(Container C)
{
	typename Container::iterator it;
	for(it = C.begin();it != C.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vecInt = {1,2,3};
	list<int> listDest;

	//insert from tail
	copy(vecInt.begin(), vecInt.end(),
		 std::back_insert_iterator<list<int> >(listDest));
	printElements(listDest);

	//insert from head
	copy(vecInt.begin(),vecInt.end(),
		 std::front_insert_iterator<list<int> >(listDest));
	printElements(listDest);

	return 0;
}
