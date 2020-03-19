#pragma once
#include "iostream"
#include <stdexcept>
using namespace std;
class indexer
{
private:
	double *array;
	int lengthar;
public:
	int begin;
	int length;
	indexer() {};
	indexer(double array[],int lengthar, int begin, int length)
	{
		if (begin < 0 || length <= 0 || lengthar < begin + length)
			throw invalid_argument("Неправельный аргумент");		
		this->array = array;
		this->begin = begin;
		this->length = length;
		this->lengthar = lengthar;
	}
	double & operator [] (unsigned int index)
	{
		if(index<length && index>=0)
			return array[begin + index];
		else
			throw out_of_range("Неправельный аргумент");

	}
	~indexer() {};
};

