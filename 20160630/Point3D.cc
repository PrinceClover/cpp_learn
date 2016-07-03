 ///
 /// @file    Point3D.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-01 11:03:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	int getx() const
	{
		return _ix;
	}

	int gety() const 
	{
		return _iy;
	}

	void display()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

class Point3D : public Point
{
public:
	Point3D(int ix,int iy,int iz)
	: Point(ix,iy)
	, _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	void display()
	{
		cout << "(" << getx()
			 << "," << gety()
			 << "," << _iz
			 << ")" << endl;
	}
private:
	int _iz;
};

int main(void)
{
	Point point(1,2);
	point.display();

	Point3D point3D(3,4,5);
	point3D.display();
	return 0;
}

