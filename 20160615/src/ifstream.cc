 ///
 /// @file    ifstream.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-15 21:12:50
 ///
 
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;

int main(void)
{
	ifstream ifs("A.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error " << endl;
		return -1;
	}

	//stream structuer can not be copy
//	ifstream ifs2(ifs);

	//don't forget to close^ ^
	ifs.close();
}
