 ///
 /// @file    point.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 20:32:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//constructor
	Point(int ix,int iy,double & dz)
	:_ix(ix)
	,_iy(iy)
	,_ref1(_ix)
	,_ref2(dz)
	{
		cout << "constructor" << endl;	
	}

	//copy constructor 
	Point(const Point & rhs)
	:_ix(rhs._ix)
	,_iy(rhs._iy)
	,_ref1(rhs._ref1)
	,_ref2(rhs._ref2)
	{
		cout << "copy constructor" << endl;
	}

	//print member variables
	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << "," << _ref1
			 << "," << _ref2
			 << ")" << endl;
	}
	void setX(int x)
	{
		_ix = x;
	}
private:
	int _ix;
	int _iy;
	int & _ref1;
	double & _ref2;
};

int main(void)
{
	double dx = 5.0;
	Point pt1(3,4,dx);
	pt1.print();

	Point pt2(pt1);
	pt2.print();

	cout << endl;

	pt1.setX(7);
	pt1.print();
	pt2.print();
	cout << endl;

	dx = 7.7;
	pt1.print();
	pt2.print();

	return 0;
}


