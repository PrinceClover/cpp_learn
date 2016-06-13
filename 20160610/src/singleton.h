 ///
 /// @file    singleton.c
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-11 10:43:13
 ///
 
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

//each class can create only one object in memory
//1.the object do not in stack or global
//2.take the constructor into private area
//3.create a static member function in private area
//4.create a static variable

class Singleton
{
public:
		static Singleton * getInstance();
		static void destroy();
private:
		Singleton();
		~Singleton();
private:
		static Singleton *_pInstance;
};

#endif
