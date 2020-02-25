#pragma once
#include <iostream>
#include "string"
#include "GameObj.cpp"
#include "Character.cpp"
using namespace std;
class Item : public GameObj
{
private:
	int id;
public:
	Item() : GameObj() {}
	Item(const Item& obj) : GameObj(obj), id(obj.id) {}
	Item(const string& _name, double _x, double _y, int _id) :GameObj(_name, _x, _y), id(_id) {}
	~Item() {}
	virtual int Draw(Character& obj)
	{
		obj.have(id);
		return id;
	}
};