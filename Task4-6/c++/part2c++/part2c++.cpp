#include <iostream>
#include <string>
#include "LinearEquation.cpp"
#include "SystemOfLinearEquation.cpp"
using namespace std;
int main()
{
	double* array = new double[4]{ 1, 2, 3, 4 };
	LinearEquation l1 = LinearEquation("2 4 1 36",4);
	LinearEquation l2 = LinearEquation("5 2 1 47", 4);
	LinearEquation l3 = LinearEquation(4);
	l3.SetIndexesRandom();
	SystemOfLinearEquation slu=SystemOfLinearEquation(3);
	slu[0] = l1;
	slu[1] = l2;
	slu[2] = l3;
	slu[0].coutl();
	slu[1].coutl();
	slu[2].coutl();
	double *x = slu.gauss();
	for (int i = 0; i < 3; i++)
		cout << x[i] << ' ';
}
