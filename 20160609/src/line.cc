 ///
 /// @file    line.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 21:32:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point()
	{
		cout << "no parameter constructor" <<endl;
	}

	Point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "constructor" << endl;
	}

	Point(const Point & rhs)
	:_ix(rhs._ix)
	,_iy(rhs._iy)
	{
		cout << "copy constructor" << endl;
	}

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

class Line
{
public:
	Line(int x1,int y1,int x2,int y2)
	:_pt1(x1,y1)
	,_pt2(x2,y2)
//values are uncertainty
//	:_pt1()
//	,_pt2()
	{
		cout << "constructor line" <<endl;
	}

	void draw()
	{
		_pt1.print();
		cout << "to" << endl;
		_pt2.print();
	}
private:
	Point _pt1;
	Point _pt2;
};


int main(void)
{
	Line line(1,2,3,4);
	line.draw();
	return 0;
}
