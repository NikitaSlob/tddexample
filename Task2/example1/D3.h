#pragma once
#include "D2.h"
#include "D1.h"
class D3 : private D1, public D2
{int d;
public:
	
	D3(int x,int y, int z, int i, int j);
	~D3();
};

