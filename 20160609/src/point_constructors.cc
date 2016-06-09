 ///
 /// @file    point.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 19:06:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point
{
public :
	//constructor
	Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "constructor" << endl;
	}
	//copy constructor
	Point(const Point & rhs)
	:_ix(rhs._ix)
	,_iy(rhs._iy)
	{
		cout << "copy constructor" << endl;
	}
	
	//print function
	void print()
	{
		cout << "(" <<_ix
			 << "," <<_iy
			 << ")" <<endl;
	}
private:
	int _ix;
	int _iy;
};

void func(Point pt)
{
	cout << "func" << endl;
	pt.print();
}

Point func2()
{
	cout << "func2()" << endl;
	Point pt(5,6);
	pt.print();
	return pt;
}

int main(void)
{
	const int a =3;
	const Point pt3(3,4);

	Point pt1(1,2);
	Point pt2 = pt1;
	pt1.print();
	pt2.print();
	cout << endl;
	func(pt2);
	cout << endl;
	func2();

	return 0;

}
