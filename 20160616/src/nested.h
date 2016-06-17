 ///
 /// @file    nested.h
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-16 20:58:17
 ///

#ifndef __NESTED_H__
#define __NESTED_H__
#include <iostream>
using std::cout;
using std::endl;

class Line
{
//using PIMPL mode
private:
	//forward declarations
	class LineImpl;
public:
	Line(int x1,int y1,int x2,int y2);
	~Line();

	void printLine();
private:
	LineImpl * _pImpl;
};

#endif
