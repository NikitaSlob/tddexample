#pragma once
#include "bird.cpp"
#include <iostream>
#include "string"
#include "predator.cpp"
class eagle : public bird, public predator
{
public:
	eagle() : bird() {}
	eagle(const eagle& obj) : bird(obj), animal(obj) {}
	eagle(double _mass, double _speed, double _topfly) : bird("", 0, 0, _topfly), animal("ќрел", _mass, _speed) {}
	// определение тела функции hunt
	// т.к. hunt определена, класс eagle Ц Ќ≈абстракный
	bool hunt(const animal& obj)
	{
		// функци€ get_mass может наследоватьс€ классом eagle из класса animal
		// и через класс bird, и через класс predator
		// нужно указать, что она наследуетс€ через bird
		return obj.get_mass() < get_mass() && obj.get_speed() < get_speed();

	}
};
