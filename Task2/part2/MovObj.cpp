#pragma once
#include <iostream>
#include "string"
#include "GameObj.cpp"
using namespace std;
class MovObj : virtual public GameObj
{
protected:
	MovObj(){}
public:
	~MovObj(){}
	virtual bool Move() = 0;
};
