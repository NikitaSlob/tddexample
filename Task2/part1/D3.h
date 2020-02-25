#pragma once
#include "D2.h"
#include "B2.h"
class D3 : private B2 , public D2
{
	int e;
public:

	D3(int x, int y, int z,int i,int j);
	~D3();
};