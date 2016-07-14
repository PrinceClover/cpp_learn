 ///
 /// @file    factory.h
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-04 19:46:00
 ///
 
#ifndef __MY_FACTORY_H__
#define __MY_FACTORY_H__

#include <iostream>
using std::cout;
using std::endl;

class Product
{
public:
	Product(){}
	virtual ~Product(){}
};

class PartA
{};

class PartB
{};

class PartC
{};

class ConcreteProduct : public Product
{
public:
	ConcreteProduct(PartA * pA, PartB * pB, PartC * pC);
	virtual ~ConcreteProduct();
private:
	PartA * _pA;
	PartB * _pB;
	PartC * _pC;
};

class Factory
{
public:
	virtual Product * create() = 0;
	virtual ~Factory(){}
};

class ConcreteFactory : public Factory
{
public:
	Product * create();
	virtual ~ConcreteFactory(){}
};

#endif
