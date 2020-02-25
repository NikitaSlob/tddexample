
#include <iostream>
#include "GameObj.cpp"
#include "MovObj.cpp"
#include "Item.cpp"
#include "Character.cpp"
int main()
{
	setlocale(0, "rus");
	Character hero("Герой",1,1,1,false);
	if (hero.Move())
	{
		cout << "Теперь персонаж движется"<<endl;
	}
	else
	{
		cout << "Теперь персонаж не движется"<<endl;
	}
	Item item("Еда",4,1,2);
	cout << "Вы подняли обЪект с номером "<<item.Draw(hero)<<endl;
}

