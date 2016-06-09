 ///
 /// @file    point.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 19:48:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//explicit constructor 
	explicit Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "expilcit constructor" << endl;
	}
	//equal operator function overload
	Point & operator = (const Point & rhs)
	{
		_ix = rhs._ix;
		_iy = rhs._iy;
		cout << "equal operator function overload" << endl;
	}

	//copy constructor
	Point (const Point & rhs)
	:_ix(rhs._ix)
	,_iy(rhs._iy)
	{
		cout << "copy constructor" << endl;
	}

	//print member variable
	void print()
	{
		cout << "(" << _ix;
		cout << "," << _iy;
		cout << ")" << endl;
	}
	
	//member variable 
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt1(1,2);
	//call copy constructor in initialization
	Point pt2 = pt1;
	Point pt3(pt1);

	Point pt4(3,4);
	//use equal operator function overload
	pt1 = pt4;
	pt1.print();
	pt2.print();
	pt3.print();
	pt4.print();
	return 0;
}
