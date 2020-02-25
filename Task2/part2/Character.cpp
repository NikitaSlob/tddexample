#pragma once
#include <iostream>
#include "string"
#include "GameObj.cpp"
#include "MovObj.cpp"
using namespace std;
class Character :virtual public GameObj, virtual public MovObj
{
private:
	int id;
	bool mov = false;
	int hand;
public:
	Character() : GameObj() {}
	Character(const Character& obj) : GameObj(obj), id(obj.id) {}
	Character(const string& _name, double _x, double _y, int _id, bool _mov) :GameObj(_name, _x, _y), id(_id), mov(_mov) {}
	~Character() {}
	bool Move()
	{
		return !mov;
	}
	void have(int id)
	{
		hand = id;
	}
protected:
	// виртуальная функция _print переопределяется в классе fish
	void _print() const
	{
		Character::_print();
		cout << ", id: " << id;
	}
};