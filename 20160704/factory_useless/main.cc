 ///
 /// @file    main.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-04 19:58:10
 ///

#include "factory.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	Factory * pFactory = new ConcreteFactory();
	Product * pProduct = pFactory->create();

	delete pFactory;
	delete pProduct;
	return 0;
}
