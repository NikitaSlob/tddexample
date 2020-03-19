#pragma once
#pragma once
#include "iostream"
#include <stdexcept>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <iomanip>
#include "LinearEquation.cpp"
using namespace std;
class SystemOfLinearEquation
{
public:
	LinearEquation* SLAU;
	int n;
	SystemOfLinearEquation(int n)
	{
		this->n = n;
		SLAU = new LinearEquation[n];
	}
	LinearEquation & operator [] (unsigned int index)
	{
		if (index < n && index >= 0)
			return SLAU[index];
		else
			throw out_of_range("Неправельный аргумент");
	}
	double *gauss()
	{
		double **a = new double*[n];
		double **b = new double*[n];
		double *y = new double[n];
		for (int i = 0; i < n; i++)
		{
			b[i] = new double[n + 1];
			SLAU[i].ToMass(b[i]);
		}
		for (int i = 0; i < n; i++)
		{
			y[i] = b[i][n];
		}
		for (int i = 0; i < n; i++)
		{
			a[i] = new double[n];
			for (int j = 0; j < n; j++)
				a[i][j] = b[i][j];
		}
		double *x, max;
		int k, index;
		const double eps = 0.00001;  // точность
		x = new double[n];
		k = 0;
		while (k < n)
		{
			// Поиск строки с максимальным a[i][k]
			max = abs(a[k][k]);
			index = k;
			for (int i = k + 1; i < n; i++)
			{
				if (abs(a[i][k]) > max)
				{
					max = abs(a[i][k]);
					index = i;
				}
			}
			// Перестановка строк
			if (max < eps)
			{
				// нет ненулевых диагональных элементов
				throw invalid_argument("Нет решения");
			}
			for (int j = 0; j < n; j++)
			{
				double temp = a[k][j];
				a[k][j] = a[index][j];
				a[index][j] = temp;
			}
			double temp = y[k];
			y[k] = y[index];
			y[index] = temp;
			// Нормализация уравнений
			for (int i = k; i < n; i++)
			{
				double temp = a[i][k];
				if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
				for (int j = 0; j < n; j++)
					a[i][j] = a[i][j] / temp;
				y[i] = y[i] / temp;
				if (i == k)  continue; // уравнение не вычитать само из себя
				for (int j = 0; j < n; j++)
					a[i][j] = a[i][j] - a[k][j];
				y[i] = y[i] - y[k];
			}
			k++;
		}
		// обратная подстановка
		for (k = n - 1; k >= 0; k--)
		{
			x[k] = y[k];
			for (int i = 0; i < k; i++)
				y[i] = y[i] - a[i][k] * x[k];
		}
		return x;
	}
	~SystemOfLinearEquation() {};
};

