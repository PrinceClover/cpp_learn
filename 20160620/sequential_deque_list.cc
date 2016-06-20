 ///
 /// @file    sequential_deque.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-20 20:14:30
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;

int testDeque(void)
{
	double arr1[5] = {1,2,3,4,5};
	deque<double> dequeDbl(arr1,arr1 + 5);

	//direct access
	for(int idx = 0;idx != dequeDbl.size();++idx)
	{
		cout << dequeDbl[idx] << " ";
	}
	cout << endl;

	//iterator
	deque<double>::iterator dit = dequeDbl.begin();
	for(;dit != dequeDbl.end();++dit)
	{
		cout << *dit << " ";
	}
	cout << endl;

	dit = dequeDbl.end();
	--dit;
	for(; dit != dequeDbl.begin() - 1;--dit)
	{
		cout << *dit << " ";
	}
	cout << endl;

	//new speciality in c++11
	for (auto & elem : dequeDbl)
	{
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}

int testList()
{
	list<float> listFlt(3,5);

	list<float>::iterator lit;
	for(lit = listFlt.begin();lit != listFlt.end();++lit)
	{
		(*lit) += 5;
		cout << *lit << " ";
	}
	cout << endl;

	list<float> listFlt2(4,9);
	//change listFlt ande listFlt2,just change the pointer
	listFlt.swap(listFlt2);
	for(lit = listFlt.begin();lit != listFlt.end();++lit)
	{
		cout << *lit << " ";
	}
	cout << endl;
	return 0;
}
int main(void)
{
	testDeque();
	testList();

	return 0;
}
