 ///
 /// @file    point.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-09 20:58:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//explicit constructor call
	explicit Point(int ix = 0,int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "explicit constructor call" << endl;
	}
	//const function
	void print()const
	{
		cout << "const function" << endl;
	}

	void print()
	{
		cout << "print function" << endl;
	}

	void notConst()
	{
		cout << "not a const function" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt1(1,2);
	pt1.print();
	pt1.notConst();

	const Point pt2(1,2);
	pt2.print();
	//const object can't call function which not const
//	pt2.notConst();
	return 0;
}
