 ///
 /// @file    typecast.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-16 18:41:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class AnotherPoint 
{
	friend std::ostream & operator << (std::ostream & os,const AnotherPoint & rhs);
	friend class Point;
public:
	AnotherPoint(double dx,double dy)
	:_dx(dx)
	,_dy(dy)
	{
		cout << "AnotherPoint constructor" << endl;
	}
private:
	double _dx;
	double _dy;
};

std::ostream & operator << (std::ostream & os,const AnotherPoint &rhs)
{
	cout << "(" << rhs._dx
		 << "," << rhs._dy
		 << ")" ;
	return os;
}

class Point 
{
	friend std::ostream & operator << (std::ostream & os,const Point &rhs);
public:
	Point(){}
	//forbid impilcit conversion
	//expilcit
	Point(int ix,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point constructor: ix/iy" << endl;
	}

	//forbid implicit conversion
	//explicit
	Point(AnotherPoint & ap)
	: _ix(ap._dx)
	, _iy(ap._dy)
	{
		cout << "Point constructor: ap" << endl;
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
	//typecast from other class to custom class by constructor
	//using explicit can forbid implicit conversion(double -> int)
	
	Point p1;
	p1 = 5;
	cout << "5 to p1= " << p1 << endl;

	double dx = 1.5;
	p1 = dx;
	cout << "dx to p1 = " << p1 << endl;

	AnotherPoint ap(12.34,56.78);
	cout << "ap="  << ap << endl;
	p1 = ap;
	cout << "ap to p1= " << p1 << endl;
	return 0;
}
