 ///
 /// @file    typecast2.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-16 20:22:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class AnotherPoint
{
	friend std::ostream & operator << (std::ostream & os,const AnotherPoint &rhs);
	friend class Point;
public:
	AnotherPoint(double dx = 0,double dy = 0)
	:_dx(dx)
	,_dy(dy)
	{
		cout << "AnotherPoint constructor: dx/dy" << endl;
	}
private:
	double _dx;
	double _dy;
};

std::ostream & operator << (std::ostream & os,const AnotherPoint & rhs)
{
	cout << "(" << rhs._dx
		 << "," << rhs._dy
		 << ")";
	return os;
}

class Point
{
	friend std::ostream & operator << (std::ostream & os,const Point &rhs);
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point constructor: ix/it" <<endl;
	}

	//type conversion function
	//1.must be a member function
	//2.no explicit return value,but you should return
	//  a object type value in function body
	//3.no parameter
	//4.do not use it often
	
	operator int()
	{
		return _ix;
	}

	operator double()
	{
		return _ix * _iy;
	}

	operator AnotherPoint()
	{
		return AnotherPoint(_ix,_iy);
	}
private:
	int _ix;
	int _iy;
};


std::ostream & operator << (std::ostream & os,const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}
int main(void)
{
	Point p2(4,5);
	int ix = p2;
	cout << "ix = " << ix << endl;

	double dy = p2;
	cout << "dy = " << dy << endl;

	AnotherPoint ap2;
	cout << "ap2 = " << ap2 << endl;
	ap2 = p2;
	cout << "ap2 = " << ap2 << endl;

	return 0;
}
