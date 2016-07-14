 ///
 /// @file    factory.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-04 19:52:43
 ///

#include "factory.h"
#include <iostream>
using std::cout;
using std::endl;

ConcreteProduct::ConcreteProduct(PartA * pA,PartB * pB,PartC * pC)
: _pA(pA)
, _pB(pB)
, _pC(pC)
{
	cout << "ConcreteProduct()" << endl;
}

ConcreteProduct::~ConcreteProduct()
{
	cout << "~ConcreteProduct()" << endl;
}

Product * ConcreteFactory::create()
{
	PartA * pA = new PartA;
	PartB * pB = new PartB;
	PartC * pC = new PartC;
	return new ConcreteProduct(pA,pB,pC);
}

