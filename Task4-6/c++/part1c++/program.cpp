#include "indexer.cpp"
#include <iostream>
using namespace std;
int main()
{
	double* array = new double[4]{ 1, 2, 3, 4 };
	indexer a = indexer(array,4, 1, 2);
}

