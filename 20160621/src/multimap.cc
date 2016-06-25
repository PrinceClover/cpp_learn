 ///
 /// @file    multimap.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-23 22:43:48
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::multimap;
using std::pair;
using std::string;

int main(void)
{
	pair<int,string> t(9,"Asia");
	cout << t.first << "-->" << t.second << endl;

	pair<int,string> pairArr[4] = 
	{
	
		pair<int, string>(5,"Asia"),
		pair<int, string>(4,"Africa"),
		pair<int, string>(1,"Euro"),
		pair<int, string>(4,"America")
	};

	multimap<int, string> mmapi2str(pairArr,pairArr + 4);
	cout << mmapi2str.size() << endl;
	for(auto & elem: mmapi2str)
	{
		cout << elem.first << "-->" << elem.second << endl;
	}

	return 0;

}
