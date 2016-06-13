 ///
 /// @file    io2.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-11 16:48:10
 ///
 
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int ival;
	while(cin >> ival,!cin.eof())
	{
		if(cin.bad())
		{
			cout << "error" << endl;
			return -1;
		}
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << "try again" << endl;
			continue;
		}
		cout << "ival = " << ival << endl;
	}
	return 0;
}
