#pragma once
#include "animal.cpp"
#include <iostream>
#include "string"
using namespace std;
 class bird : virtual public animal
{
private:
	double topfly; //km
public:
	bird() : animal() {}
	bird(const bird& obj) : animal(obj), topfly(obj.topfly) {}
	bird(const string& _title, double _mass, double _speed, double _topfly): animal(_title, _mass, _speed), topfly(_topfly) {}
	~bird() 
	{ 
		cout << " bird deleted" << endl;
	}
protected:
	// виртуальная функция _print переопределяется в классе bird
	void _print() const
	{
		animal::_print();
		cout << ", topfly: " << topfly;
	}
};