#include "pch.h"
#include "D4.h"
#include "iostream"
using namespace std;


	


D4::D4(int x, int y, int z, int i, int j):D1(y, z), D2(i, j)
{
	e = x;
	cout << " object of" << typeid(*this).name() << " was created\n";
}
D4::~D4()
{
	cout << " object of" << typeid(*this).name() << " was destroyed\n";
}
