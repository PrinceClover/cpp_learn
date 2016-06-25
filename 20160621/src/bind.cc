 ///
 /// @file    bind.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-25 10:25:50
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

int func(int x,int y)
{
	return x + y;
}

struct A
{
	A()
	{
		cout << "A()" << endl;
	}

	A(const A & rhs)
	{
		cout << "A(const A&)" << endl;
	}

	int func(int x,int y)
	{
		cout << "A::func(int,int)" << endl;
		cout << " x = " << x << endl;
		cout << " y = " << y << endl;
		return x + y;
	}
};

void f(int n1,int n2,int n3,const int & n4,int n5)
{
	cout << "(" << n1
		 << "," << n2
		 << "," << n3
		 << "," << n4
		 << "," << n5
		 << ")" << endl;
}

int test0(void)
{
	using namespace std::placeholders;
	auto f1 = std::bind(func, 10, _1);
	cout << f1(20) << endl;

	A a;
	auto f2 = std::bind(&A::func,&a,_1,_2);
	cout << f2(1,2) << endl;
	return 0;
}

struct Foo
{
	int data = 10;
};

int main(void)
{
	using namespace std::placeholders;
	int n = 7;

	auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
	n = 10;

	f1(1,2,1001,1002,1003);

	Foo foo;
	foo.data = 12;
	auto f3 = std::bind(&Foo::data, _1);
	cout << f3(foo) << endl;

	return 0;
}
