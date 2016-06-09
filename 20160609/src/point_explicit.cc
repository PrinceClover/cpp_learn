 ///
 /// @file    point.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 19:27:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//explicit constructor call
	explicit Point(int ix,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "explicit constructor call" << endl;
	}
	
	//print member variable
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt(2,3);
	pt.print();

	//implicit conversion ---by constructor
	Point pt2 = 5;
	pt2.print();

	return 0;
}
