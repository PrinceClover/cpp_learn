 ///
 /// @file    6.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-08 16:57:15
 ///
 
#include <iostream>
#include <stdio.h>
#pragma pack(2)
class BU
{
	public:
	int number;
	union UBffer
	{
		char buffer[13];
		int number;
	}ubuf;
	void foo(){}
	typedef char *(*f)(void*);
	enum{hdd,ssd,blueray}disk;
}bu;

int main(void)
{
	printf("sizeof number:%d\n",(int)sizeof(bu.number));
	printf("sizeof ubuf:%d\n",(int)sizeof(bu.ubuf));
//	printf("sizeof foo:%d\n",(int)sizeof(bu.foo));
	printf("sizeof enum:%d\n",(int)sizeof(bu.disk));
	return 0;
}
