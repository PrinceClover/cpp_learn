 ///
 /// @file    set.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-20 20:56:41
 ///
 
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

int test0(void);

class Point
{
	friend std::ostream & operator << (std::ostream & os,const Point & rhs);
public:
	Point(int ix,int iy)
	: _ix(ix)
	, _iy(iy)
	{}

	int product() const
	{
		return _ix * _iy;
	}
private:
	int _ix;
	int _iy;
};

std::ostream & operator << (std::ostream & os,const Point & rhs)
{
	cout << "(" << rhs._ix
		 << "," << rhs._iy
		 << ")";
}

bool operator > (const Point & lhs,const Point & rhs)
{
	return lhs.product() > rhs.product();
}

int main(void)
{
	Point arr[4] = {
		Point(1,2),
		Point(3,4),
		Point(-1,2),
		Point(4,5)
	};

	//compare function 
	set<Point,std::greater<Point> > setPoint(arr,arr+4);
	set<Point,std::greater<Point> >::iterator sit;
	for(sit = setPoint.begin();sit != setPoint.end();++sit)
	{
		cout << *sit << endl;
	}
	test0();
	return 0;
}

int test0(void)
{
	int arr[9] = {2,1,3,5,4,6,2,3,5};
	set <int,std::greater<int> > setInt(arr,arr+9);
	cout << "setInt's size: " << setInt.size() << endl;
	//the set will drop repeat elements
	//in the default situation,set call std::less function
	//sort the elements with '<' (from the Min to the Max)
	set<int>::iterator sit;
	for(sit = setInt.begin();sit != setInt.end();++sit)
		cout << *sit << " ";
	cout << endl;
	return 0;
}
