#pragma once
#include <iostream>
#include "string"
using namespace std;
class GameObj
{
private:
	string name;
	double x;
	double y;
protected:
	GameObj() : x(0.0),y(0.0) {}
	GameObj(const GameObj& obj) : name(obj.name), x(obj.x), y(obj.y) {}
	GameObj(const string& _name, double _x, double _y) : name(_name), x(_x) {}
	virtual ~GameObj()
	{
		cout << " Object deleted" << endl << endl;
	}
	virtual void _print() const
	{
		cout << "Name: " << name << ", x: " << x<<", y:"<<y;
	}

public:


	void print() const
	{
		cout << typeid(*this).name() << ": (";
		_print();
		cout << ")" << endl;

	}
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
};