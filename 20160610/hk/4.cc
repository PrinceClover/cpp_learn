 ///
 /// @file    4.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-10 18:49:55
 ///
 
#include <iostream>
#include <unistd.h>
#include <pthread.h>
using std::cout;
using std::endl;

class MutexLock
{
public:
		MutexLock()
		:l(1){};

		~MutexLock(){}
		
		void lock()
		{
			while(!l)
			{
				usleep(1);	
			}
			--l;
		}
		void unlock()
		{
			++l;
		}
		void lockstatus()
		{
			if(l)
			{
				cout << "status unlock" << endl;
			}
			else
			{
				cout << "status locked" << endl;
			}
		}
private:
	int l;
};

/*
void* child(MutexLock *ml)
{
	cout << "child will locked" << endl;
	ml->lock();
	cout << "child will lock 3s" << endl;
	sleep(3);
	cout << "child will unlock" <<endl;
	ml->unlock();
}
*/

int main(void)
{
/*	MutexLock ml;
	pthread_t pt;
	int ret = pthread_create(&pt,NULL,child,&ml);
	cout << "parent will locked" << endl;
	ml.lock();
	cout << "parent will lock 3s" << endl;
	sleep(3);
	cout << "parent will unlock" <<endl;
	ml.unlock();	
*/	return 0;
}
