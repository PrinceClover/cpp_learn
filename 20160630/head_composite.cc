 ///
 /// @file    head_composite.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-01 10:50:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

struct Eye
{
	void look()
	{
		cout << "Eye::look" << endl;
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
{
public:
	void look()
	{
		_eye.look();
	}
	void smell()
	{
		_nose.smell();
	}
	void eat()
	{
		_mouth.eat();
	}
	void listen()
	{
		_ear.listen();
	}
private:
	Eye _eye;
	Nose _nose;
	Mouth _mouth;
	Ear _ear;
};

int main(void)
{
	Head head;
	head.look();
	head.smell();
	head.eat();
	head.listen();

	return 0;

}
