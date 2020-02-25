#pragma once
#include "creature.cpp"
#include <iostream>
#include "string"
using namespace std;
class animal : public creature
{
private:
	double speed; //m/s
public:
	animal() : creature() {}
	animal(const animal& obj) : creature(obj), speed(obj.speed) {}
	animal(const string& _title, double _mass, double _speed): creature(_title, _mass), speed(_speed) {}
	~animal()
	{
		cout <<"animal deleted" << endl; 
	}
	double get_speed() const
	{
		return speed;
	}
protected:
	// виртуальная функция _print переопределяется в производном //классе
	void _print() const
	{
		creature::_print();
		cout<<", speed: "<< speed;
	}
};
