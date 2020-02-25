#pragma once
#include "animal.cpp"
#include <iostream>
#include "string"
using namespace std;
class fish : public animal
{
private:
	double maxdeep; //km
public:
	fish() : animal() {}
	fish(const fish& obj) : animal(obj), maxdeep(obj.maxdeep) {}
	fish(const string& _title, double _mass, double _speed, double _maxdeep): animal(_title, _mass, _speed), maxdeep(_maxdeep) {}
	~fish()
	{
		cout <<"fish deleted" << endl;
	}

protected:
	// виртуальная функция _print переопределяется в классе fish
	void _print() const
	{
		animal::_print();
		cout <<", maxdeep: " << maxdeep;
	}
};
