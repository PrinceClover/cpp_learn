 ///
 /// @file    Singleton.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-20 19:10:39
 ///
 
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

template <typename T>
class Singleton
{
private:
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease constructor" << endl;
		}

		~AutoRelease()
		{
			cout << "~AutoRelease" << endl;
			if(_pInstance != NULL)
				delete _pInstance;
		}
	};

public:
	static T * getInstance()
	{
		if(_pInstance == NULL)
		{
			_autoRelease; //instantiation
			_pInstance = new T;
		}
		return _pInstance;
	}
private:
	Singleton(){}
	~Singleton(){}
private:
	static T * _pInstance;
	static AutoRelease _autoRelease;
};

template <typename T>
T * Singleton<T>::_pInstance = NULL;

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;

int main(void)
{
	int * p1 = Singleton<int>::getInstance();
	int * p2 = Singleton<int>::getInstance();

	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
	return 0;
}
