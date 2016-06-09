 ///
 /// @file    point.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 20:05:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//const initalization

class Point
{
public:
	//constructor
	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "constructor" << endl;
		//const variable can't be assignment
		//_ix = ix;
		//_iy = iy;
	}

	//print mamber variable
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

//const ---- read only 
#if 0
void setX(int ix)
{
	_ix = ix;
}
#endif

private:
	const int _ix;
	const int _iy;
};
int main(void)
{
	Point pt1(3,4);
	pt1.print();
}
