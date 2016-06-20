 ///
 /// @file    map.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-20 21:47:05
 ///
 
#include <iostream>
#include <string>
#include <map>
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::map;

int test1(void);

int main(void)
{
	map<string,string> mapss;
	mapss["11"] = "aa";
	mapss["22"] = "bb";
	mapss["33"] = "cc";
	mapss["44"] = "dd";

	for(auto & elem : mapss)
	{
		cout << elem.first << "-->"
			 << elem.second << endl;
	}
	cout << "test1" << endl;
	test1();
	return 0;
}

int test1(void)
{
	pair<string,string> t("600036","招商银行");
	cout << t.first << "-->" << t.second << endl;

	pair<string,string> pairArr[4] = 
	{
		pair<string, string>("1","beijing"),
		pair<string, string>("2","shenzhen"),
		pair<string, string>("3","guangzhou"),
		pair<string, string>("2","suzhou")
	};

	map<string, string> map2str(pairArr,pairArr + 4);
	map<string, string>::iterator mit;
	for(mit = map2str.begin();mit != map2str.end();++mit)
	{
		cout << mit->first << "-->" << mit->second << endl;
	}
	cout << endl;

	cout << "2-->" << map2str["2"] << endl;
	return 0;

} 

