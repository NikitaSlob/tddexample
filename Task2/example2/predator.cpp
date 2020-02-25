#pragma once
#include "animal.cpp"
#include <iostream>
#include "string"
class predator : virtual public animal
{
protected:
	predator() {}
public:
	~predator() {}
	// чисто виртуальная функция hunt будет определять
	// посредством производных классов,
	// удастся ли хищнику поохотиться на жертву (obj)
	virtual bool hunt(const animal& obj) = 0;
	// т.к. hunt чисто виртуальная, класс predator является абстрактным
};