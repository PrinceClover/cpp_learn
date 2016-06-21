 ///
 /// @file    max_heap.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-21 21:22:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class MaxNumberHeap
{
public:
	//constructor and destructor
	MaxNumberHeap(int * array,int len)
	:_size(len)
	{
		_heap = new int[len];
		for(int i = 0;i < len;++i)
			_heap[i] = array[i];
	}

	~MaxNumberHeap(){}
	
	//swap two elements
	void swap(int &a,int &b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}

	//max heapify
	void max_heapify(int start,int end)
	{
		int dad = start;
		int son = dad * 2 + 1;
		while(son < end)
		{
			if(son + 1 < end && _heap[son] < _heap[son + 1])
				++son;
			if(_heap[dad] > _heap[son])
				return;
			else
			{
				swap(_heap[dad],_heap[son]);
				dad = son;
				son = dad * 2 + 1;
			}
		}
		//print_heap();
	}

	//build max heap
	void build_max_heap()
	{
		for(int i = _size/2 - 1;i >= 0; --i)
			max_heapify(i,_size);
	}

	//heapsort
	void heap_sort()
	{
		build_max_heap();
		for(int i = _size - 1;i > 0;--i)
		{
			swap(_heap[0],_heap[i]);
			max_heapify(0,i);
		}
	}

	//print heap
	void print_heap()
	{
		for(int i = 0;i < _size;++i)
		{
			cout << _heap[i] << " ";
		}
		cout << endl;
	}
private:
	int * _heap;
	int _size;
};


int main(void)
{
	int array[20] = {12,1,4,5,2,55,3,6,2,7,4,21,32,547,8,78,0,9,69,99};
	int len = (int)sizeof(array)/sizeof(*array);
	MaxNumberHeap mh(array,len);
	mh.heap_sort();
	mh.print_heap();
	return 0;
}
