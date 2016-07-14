 ///
 /// @file    iterator.h
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-04 20:52:02
 ///
 
#ifndef __MY_ITERATOR_H__
#define __MY_ITERATOR_H__
#include <iostream>
using std::cout;
using std::endl;

typedef int Data;

class Iterator;

class Aggregate
{
public:
	virtual Iterator * createIterator() = 0;
	virtual int size() = 0;
	virtual Data & getItem(int idx) = 0;

	virtual Iterator * begin() = 0;
	virtual Iterator * end() = 0;

	virtual ~Aggregate(){}
};

class ConcreteAggregate : public Aggregate
{
public:
	ConcreteAggregate(int size);
	virtual Iterator * createIterator();
	virtual int size();
	virtual Data & getItem(int idx);

	virtual Iterator * begin();
	virtual Iterator * end();

	virtual ~ConcreteAggregate();
private:
	int _size;
	Data * _pData;
};

class Iterator
{
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() = 0;
	virtual Data & currentItem() = 0;

	virtual bool operator != (Iterator & rhs) = 0;
	virtual Data & operator *() = 0;
	virtual void operator++() = 0;
	virtual int index() = 0;

	virtual ~Iterator(){}
};

class ConcreteIterator : public Iterator
{
public:
	ConcreteIterator(Aggregate * pAggregate,int idx);
	virtual void first();
	virtual void next();
	virtual bool isDone();
	virtual Data & currentItem();

	virtual bool operator != (Iterator & rhs);
	virtual Data & operator *();
	virtual void operator ++();
	virtual int index();
private:
	Aggregate * _pAggregate;
	int idx;
};
#endif
