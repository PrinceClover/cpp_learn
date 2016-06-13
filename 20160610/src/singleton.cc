 ///
 /// @file    singleton.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-11 10:52:34
 ///
 
#include <iostream>
#include "singleton.h"

using std::cout;
using std::endl;

Singleton *Singleton::_pInstance = NULL;

Singleton *Singleton::getInstance()
{
	if(_pInstance == NULL)
	{
		_pInstance = new Singleton;
	}
	return _pInstance;
}

void Singleton::destroy()
{
	delete _pInstance;
	_pInstance = NULL;
}

Singleton::Singleton(){}
Singleton::~Singleton(){}


