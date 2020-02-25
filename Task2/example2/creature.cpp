#pragma once
#include <iostream>
#include "string"
using namespace std;
class  creature
{
private:
	string title;
	double mass; //kg
protected:
	creature() : mass(0.0) {}
	creature(const creature& obj) : title(obj.title), mass(obj.mass) {}
	creature(const string& _title, double _mass) : title(_title), mass(_mass) {}
	// деструктор (объявлен как виртуальный)
	virtual ~creature()
	{
		cout << " creature deleted" << endl << endl;
	}
	// виртуальная функция для вывода информации об объекте
	virtual void _print() const
	{
		cout << "title: " << title << ", mass: " << mass;
	}

public:

	// открытая функция для вывода информации об объекте
	void print() const
	{
		cout << typeid(*this).name() << ": (";
		// вызов виртуальной функции
		// т.к. функция _print виртуальная, вызываться она будет
		// не только из текущего класса, но и из производных,
		// в зависимости от того, для какого объекта осуществляется вызов
		_print();
		cout << ")" << endl;

	}
	double get_mass() const
	{
		return mass;
	}
};