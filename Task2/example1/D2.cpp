#include "pch.h"
#include "D2.h"
#include "iostream"
#include "B.h"

using namespace std;





D2::D2(int x,int y):B(y)
{
	c = x;
	cout << " object of" << typeid(*this).name() << " was created\n";
}
D2::~D2()
{
	cout << " object of" << typeid(*this).name() << " was destroyed\n";
}
