 ///
 /// @file    singleton.h
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-18 21:54:53
 ///
 
#ifndef __MY_SINGLETON_H__
#define __MY_SINGLETON_H__

#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance();
	static void init();
	static void destory();
private:
	Singleton();
	~Singleton();
private:
	static Singleton * _pInstance;
	static pthread_once_t _once;
};

#endif
