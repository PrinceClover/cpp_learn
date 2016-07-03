 ///
 /// @file    head_inherit.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-01 10:45:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;

struct Eye
{
	void look()
	{
		cout << "Eye::look()" << endl;
	}
};

struct Nose
{
	void smell()
	{
		cout << "Nose::smell()" << endl;
	}
};

struct Mouth
{
	void eat()
	{
		cout << "Mouth::eat()" << endl;
	}
};

struct Ear
{
	void listen()
	{
		cout << "Ear::listen()" << endl;
	}
};

struct Head
:public Eye
,public Nose
,public Mouth
,public Ear
{};

int main(void)
{
	Head head;
	head.look();
	head.smell();
	head.eat();
	head.listen();

	return 0;
}
