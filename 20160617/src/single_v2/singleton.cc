 ///
 /// @file    singleton.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-18 21:59:31
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include "singleton.h"

Singleton * Singleton::_pInstance = NULL;
pthread_once_t Singleton ::_once = PTHREAD_ONCE_INIT;

Singleton * Singleton::getInstance()
{
	pthread_once(&_once, &Singleton::init);
	return _pInstance;
}

void Singleton::init()
{
	::atexit(&Singleton::destory);
	if(_pInstance == NULL)
	{
		_pInstance = new Singleton;
	}
}

void Singleton::destory()
{
	if(_pInstance != NULL)
		delete _pInstance;
}

Singleton::Singleton()
{
	cout << "Singleton constructor" << endl;
}
Singleton::~Singleton()
{
	cout << "Singleton constructor" << endl;
}

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	return 0;
}
