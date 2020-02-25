#include "pch.h"
#include "B.h"
#include "iostream"
using namespace std;

B::B()
{
	cout << " object of" << typeid(*this).name() << " was created\n";
}

B::B(int x)
{
	a = x;
}
B::~B()
{
	cout << " object of" << typeid(*this).name() << " was destroyed\n";
}
