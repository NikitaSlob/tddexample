#include "pch.h"
#include "D1.h"
#include "B.h"
#include "iostream"
using namespace std;

D1::D1(int x,int y):B(y)
{
	b = x;
	cout << " object of" << typeid(*this).name() << " was created\n";
}
D1::~D1()
{
	cout << " object of" << typeid(*this).name() << " was destroyed\n";
}
