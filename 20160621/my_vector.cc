 ///
 /// @file    my_vector.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-23 10:13:48
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::string;

template<typename T>
class Vector
{
public:
	//constructor and destructor
	Vector();
	~Vector();

	// pop/push back
	void push_back(const T &);
	void pop_back();
	// operator overload
	T & operator[](int idx);

	int size();
	int capacity();
	int new_capacity(int old_capa);

	void reallocate();

	//print size and capacity of vector
	void print_cs();

	//print all element of vecetor
	void print_elems();
private:
	T * _elems;			//the first element of vector
	T * _end;			//after last vector 
	T * _first_free;	//after last element of vector
};

template<typename T>
T & Vector<T>::operator[](int idx)
{
	if(idx >= 0 && idx < size())
		return _elems[idx];
	else
	{
		cout << "out of bounds" << endl;
		exit(-1); 
	}
}

template<typename T>
void Vector<T>::pop_back()
{
	if(size() == 0)
	{
		cout << "vector is empty!" << endl;
		return;
	}
	--_first_free;
}

template<typename T>
void Vector<T>::push_back(const T & elem)
{
	if(size() == capacity())
		reallocate();
	_elems[size()]= elem;
	++_first_free;
}


template<typename T>
int Vector<T>::new_capacity(int old_capa)
{
	if(old_capa == 0)
		return 1;
	else
	{
		return old_capa * 2;
	}
}

template<typename T>
void Vector<T>::reallocate()
{
	int old_size = size();
	int new_capa = new_capacity(capacity());
	T * temp = _elems;
	_elems = new T[new_capa];
	for(int i = 0;i < old_size;++i)
	{
		_elems[i] = temp[i];
	}
	_first_free = _elems + (old_size + 1);
	_end = _elems + (new_capa + 1);
	delete [] temp;
}

template<typename T>
int Vector<T>::size()
{
	return _first_free - _elems - 1;
}

template<typename T>
int Vector<T>::capacity()
{
	return _end - _elems - 1;
}

template<typename T>
Vector<T>::Vector()
{
	_elems = new T[1];
	_first_free = _elems + 1;
	_end = _elems + 1;
//	printf("_elem = %p\n_first_free = %p\n_end = %p\n",_elems,_first_free,_end);
}

template<typename T>
Vector<T>::~Vector()
{
	_end = NULL;
	_first_free = NULL;
	delete [] _elems;
}

template<typename T>
void Vector<T>::print_cs()
{
	printf("size|capacity\n");
	printf("%-4d|%-8d\n",size(),capacity());
	//cout << "size | capacity" << endl;
	//cout << size() << "\t|" << capacity() << endl; 
}

template<typename T>
void Vector<T>::print_elems()
{
	int tsize = size();
	for(int i = 0;i < tsize;++i)
	{
		cout << _elems[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	Vector<double> ve;
	ve.print_cs();

	ve.push_back(2.22);
	ve.push_back(1.11);
	ve.print_cs();
	ve.print_elems();

	ve.push_back(3.33);
	ve.print_cs();
	ve.print_elems();

	ve.pop_back();
	ve.print_cs();
	ve.print_elems();

	cout << ve[1] << endl;
	cout << ve[5] << endl;
	return 0;
}
