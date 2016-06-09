 ///
 /// @file    2.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 21:54:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class pat
{
public:
	pat()
	{
		cout << "constructor" << endl;
	}
};

int main(void)
{
//	pat **ad = new pat*[4];
//	for(int i = 0;i<4;i++)
//	{
//		ad[i] = new pat[4];
//	}
//	cout << "line" << endl;
	pat(*ad)[3];
	return 0;
	//zero!!!
}
