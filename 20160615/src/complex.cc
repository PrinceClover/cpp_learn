 ///
 /// @file    complex.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-15 21:47:37
 ///
 
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;
using std::cin;
class Complex
{
	//the inputstream and outputstream structure must be overload by friend
	//return value must be a quote of stream object
	friend std::ostream & operator << (std::ostream &os,const Complex &rhs);
	friend std::istream & operator >> (std::istream &is,Complex &rhs);
	friend Complex operator + (const Complex &lhs, const Complex &rhs);
public:     
	Complex(double dreal = 0,double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		cout << "Complex constructor" << endl;
	}
private:
	double _dreal;
	double _dimag;
};

Complex operator + (const Complex &lhs,const Complex &rhs)
{
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimag + lhs._dimag);
}

std::ostream & operator << (std::ostream & os,const Complex &rhs)
{
	if(rhs._dreal > 0)
	{
		os << rhs._dreal;
		if(rhs._dimag > 0)
		{
			os << " + " << rhs._dimag << "i";
		}
		else if(rhs._dimag < 0)
		{
			os << " - " << rhs._dimag * (-1) << "i";
		}
	}
	else if(rhs._dreal < 0)
	{
		os << " - " << rhs._dreal << endl;
		if(rhs._dimag > 0)
		{
			os << " + " <<  rhs._dimag << "i";
		}
		else if(rhs._dimag < 0)  
		{
			os << " - " << rhs._dimag *(-1) << "i";
		}
	}
	else
	{	
		if(rhs._dimag > 0)
		{
			os << " + " <<  rhs._dimag << "i";
		}
		else if(rhs._dimag < 0)  
		{
			os << " - " << rhs._dimag *(-1) << "i";
		}
	}
	return os;
}

std::istream & operator >> (std::istream &is,Complex & rhs)
{
	is >> rhs._dreal;
	while(is.get() != '*'); //'*' means end of dreal
	is >> rhs._dimag;
	return is;
}

int main(void)
{
	Complex c1(1,-2);
	Complex c2(0,-4);

	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;

	Complex c3 = c1 + c2;
	cout << "c3 = " << c3 << endl;

	Complex c4(1,2);
	cin >> c4;
	cout << "c4 = " << c4 << endl;

	return 0;
}
