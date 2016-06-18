 ///
 /// @file    singleton.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-18 22:36:02
 ///
 
#include <stdio.h>
#include "singleton.h"

Singleton * Singleton::_pInstance = getInstance();
Singleton::AutoRelease Singleton::_autoRelease;

//in thread is not safety
Singleton * Singleton::getInstance()
{
	if(_pInstance == NULL)
	{
		_pInstance = new Singleton;
	}
	return _pInstance;
}

Singleton::Singleton()
{
	cout << "Singleton constructor" << endl;
}
Singleton::~Singleton()
{
	cout << "Singleton destructor" << endl;
}

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);

	cout << sizeof(Singleton) << endl;
	return 0;
}


