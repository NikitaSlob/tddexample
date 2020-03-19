#pragma once
#include "iostream"
#include <stdexcept>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <iomanip>
using namespace std;
class LinearEquation
{
public:
	double* indexes;
	int n;
	LinearEquation()
	{
		n = 0;
		indexes = new double[0];
	};
	LinearEquation(string s, int n)
	{
		istringstream ss(s);
		this->n = n;
		indexes = new double[n];
		for (int i = 0; i < n; i++)
		{
			ss >> indexes[i];
		}


	};
	LinearEquation(int n)
	{
		this->n = n;
		indexes = new double[n];
		for (int i = 0; i < n; i++)
		{
			indexes[i] = 0;
		}
	};
	LinearEquation(double* array, int n)
	{
		this->n = n;
		indexes = new double[n];
		for (int i = 0; i < n; i++)
		{
			indexes[i] = array[i];
		}
	};
	void SetIndexes(int x)
	{
		for (int i = 0; i < n; i++)
		{
			indexes[i] = x;
		}
	};
	void SetIndexesRandom()
	{
		srand(time(0));
		for (int i = 0; i < n; i++)
		{
			indexes[i] = rand() % 100;
		}
	};
	void ToMass(double d[])
	{
		if ((bool)this)
		{
			for (int i = 0; i < n; i++)
			{
				d[i] = indexes[i];
			}
		}
		else
			throw invalid_argument("Уравнение противоречивое");
	};
	LinearEquation operator+ (const LinearEquation& l2)
	{
		if (n == l2.n)
		{
			for (int i = 0; i < n; i++)
			{
				indexes[i] += l2.indexes[i];
			}
		}
		else
		{
			throw invalid_argument("Неправельный аргумент");
		}
	}
	LinearEquation operator- (const LinearEquation& l2)
	{
		if (n == l2.n)
		{
			for (int i = 0; i < n; i++)
			{
				indexes[i] -= l2.indexes[i];
			}
		}
		else
		{
			throw invalid_argument("Неправельный аргумент");
		}
	}
	friend const LinearEquation operator* (const LinearEquation& l1, const int x)
	{
		for (int i = 0; i < l1.n; i++)
		{
			l1.indexes[i] *= x;
		}
		return l1;
	}
	friend const LinearEquation operator* (const int x, const LinearEquation& l1)
	{
		for (int i = 0; i < l1.n; i++)
		{
			l1.indexes[i] *= x;
		}
		return l1;
	}
	friend const LinearEquation operator- (const LinearEquation& l1)
	{
		for (int i = 0; i < l1.n; i++)
		{
			l1.indexes[i] *= -1;
		}
		return l1;
	}
	friend const bool operator== (const LinearEquation& l1, const LinearEquation& l2)
	{
		bool b = true;
		if (l1.n == l2.n)
		{
			for (int i = 0; i < l1.n; i++)
			{
				if (l1.indexes[i] != l2.indexes[i])
					b = false;
			}
			return b;
		}
		else
		{
			throw invalid_argument("Неправельный аргумент");
		}
	}
	friend const bool operator!= (const LinearEquation& l1, const LinearEquation& l2)
	{
		bool b = true;
		if (l1.n == l2.n)
		{
			for (int i = 0; i < l1.n; i++)
			{
				if (l1.indexes[i] != l2.indexes[i])
					b = false;
			}
			return !b;
		}
		else
		{
			throw invalid_argument("Неправельный аргумент");
		}
	}
	operator bool() const
	{
		bool b = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (indexes[i] == 0 && !b)
				b = false;
			else
				b = true;
		}
		if (!b && indexes[n - 1] != 0)
			b = false;
		else
			b = true;
		return b;
	}
	void coutl()
	{
		for (int i = 0; i < n - 1; i++)
		{
			cout << setprecision(5) << indexes[i] << "*x" << i;
			if (i != n - 2)
				cout << '+';
		}
		cout << '=' << indexes[n - 1];
		cout << endl;
	}
	operator list<double>()
	{
		list<double> l1(n);
		for (int i = 0; i < n; i++)
		{
			auto iter = l1.begin();
			*iter = indexes[i];
			*iter++;
		}
		return l1;

	}
	~LinearEquation() {};

};

