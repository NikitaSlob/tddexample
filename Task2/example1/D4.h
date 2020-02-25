#pragma once
#include "D2.h"
#include "D1.h"
class D4 : private D1, public D2
{int e;
public:
	
	D4(int x, int y, int z, int i, int j);
	~D4();
};

