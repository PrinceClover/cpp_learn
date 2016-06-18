 ///
 /// @file    singleton.h
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-18 22:30:33
 ///
 
#ifndef __MY_SINGLETON_H__
#define __MY_SINGLETON_H__

#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
private:
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease constructor(do nothing)" << endl;
		}

		~AutoRelease()
		{
			cout << "~AutoRelease()" << endl;
			if(_pInstance != NULL)
				delete _pInstance;
		}
	};
public:
	static Singleton * getInstance();
private:
	Singleton();
	~Singleton();
private:
	static Singleton * _pInstance;
	static AutoRelease _autoRelease;
	int _ix;
};

#endif
