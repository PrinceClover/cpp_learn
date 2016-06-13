 ///
 /// @file    io1.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-11 10:21:26
 ///
 
#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void printCin()
{
	cout << "badbit = " << cin.bad() << endl;
	cout << "failbit = " << cin.fail() << endl;
	cout << "eofbit = " << cin.eof() << endl;
	cout << "goodbit = " << cin.good() << endl;
}

int main(void)
{
	int inum;
	printCin();
	while(cin >> inum)
		cout << "inum = " << inum << endl;
	printCin();
	cin.clear();
	cout << endl;
	printCin();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	
	string s;
	cin >> s;
	cout << s << endl;
	return 0;
}
