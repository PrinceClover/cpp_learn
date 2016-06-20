 ///
 /// @file    sequential_insert.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-20 19:34:30
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template <typename Container>
void display(Container & c)
{
	//tell compiler iterator is a class type
	typename Container::iterator cit;
	for(cit = c.begin();cit != c.end();++cit)
	{
		cout << * cit << " ";
	}
	cout << endl;
}

int main(void)
{
	vector<int> vecInt(5,0);
	display(vecInt);

	vector<int>::iterator it = vecInt.end();
	it = vecInt.insert(it, 1);
	display(vecInt);
	cout << "*it = " << *it << endl;

	vecInt.insert(it,2,3);
	display(vecInt);

	it = vecInt.begin();
	int arr[3] = {7,8,9};

	vecInt.insert(it, arr, arr + 3);
	display(vecInt);
	cout << endl;

	//new speciality in c++11
	vector<int> vecInt2 = {1,2,3,4,5,6,7,8,9};
	display(vecInt2);

	return 0;
	
}
	

