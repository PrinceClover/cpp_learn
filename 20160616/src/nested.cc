 ///
 /// @file    nested.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-16 21:20:28
 ///
 
#include <iostream>
#include "nested.h"
using std::cout;
using std::endl;

class Line::LineImpl
{
private:
	//class Point only can be use in class Line
	class Point
	{
	public:
		Point(int ix = 0,int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Line::Point(int,int)" << endl;
		}
		void printPoint();
	private:
		int _ix;
		int _iy;
	};
public:
	LineImpl(int x1,int y1,int x2,int y2)
	:_p1(x1,y1)
	,_p2(x2,y2)
	{
		cout << "Line constructor" << endl;
	}

	void printLine()
	{
		_p1.printPoint();
		cout << " ---> " ;
		_p2.printPoint();
		cout << endl;
	}
private:
	Point _p1;
	Point _p2;
};

void Line::LineImpl::Point::printPoint()
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")";
}

Line::Line(int x1,int y1,int x2,int y2)
: _pImpl(new LineImpl(x1,y1,x2,y2))
{
}

Line::~Line()
{
	delete _pImpl;
}

void Line::printLine()
{
	_pImpl->printLine();
}

int main(void)
{
	Line line(1,2,3,4);
	line.printLine();
	return 0;
}
