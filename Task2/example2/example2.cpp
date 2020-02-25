
#include <iostream>
#include "animal.cpp"
#include "fish.cpp"
#include "bird.cpp"
#include "eagle.cpp"
using namespace std;
int main()
{
	setlocale(0, "Rus");
	bird raven("Ворона" , 0.3, 10, 0.1);
	eagle eagle1(1,100,1);
	fish hammerhead("Рыба - молот" , 150, 5, 0.5);
	raven.print();
	hammerhead.print();
	cout <<"Eagle vs raven : "<< eagle1.hunt(raven) << endl;
	cout << " Eagle vs hammerhead : " << eagle1.hunt(hammerhead)<< endl;
	cout << endl;
	return 0;
}
