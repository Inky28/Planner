/*
Зробити програму планнер

В планнера буде змога додавати події на конкретний день (День користувач вводить з клавіатури)

При додаванні має бути задаватись приорітет (Важливі або рутина)

Якщо ВАЖЛИВІ подія на цей день додається на початок спику цього дня, якщо подія рутинна додається в кінець списку (якщо ВАЖЛИВА то відображається чеврним кольором, якщо рутинна то зеленим)

Реалізувати це все через однозв'язні списки

Мають бути обєкти Planner(Однозв'язний список), Day (Має дату і список своїх подій), Date(День, Місяць, Рік), Event(Заголовок, Опис події)

Реалізувати меню через яке можна буде користуватись планером
*/

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Event.h"
#include "Day.h"
#include "Planner.h"

using namespace std;

int main()
{
	Planner planner;
	char key, key1;
	do
	{
		cout << "1. Add new day\n";
		cout << "2. Add events\n";
		cout << "3. Show day\n";
		cout << "4. Show events\n";
		cout << "0. Exit\n";
		cin >> key;

		system("cls");
		char key1;
		cout << "1. Today\n";
		cout << "2. Tomorrow\n";
		cin >> key1;

		switch (key)
		{
		case '1':
		{
			if (key1 == '1')
			{
				Day newDay(time(nullptr));
				planner.PushBack(newDay);
			}
			else if (key1 == '2')
			{
				Day newDay(time(nullptr) + 86400);
				planner.PushBack(newDay);
			}
			break;
		}
		case '2':
		{
			if (key1 == '1')
			{
				Day newDay(time(nullptr));
				planner.PushBack(newDay);
			}
			else if (key1 == '2')
			{
				Day newDay(time(nullptr) + 86400);
				planner.PushBack(newDay);
			}
			break;
		}
		case '3':
		{
			planner.GetLastData().ShowDay();
			break;
		}
		case '4':
		{
			planner.GetLastData().GetEvents().Show();
			break;
		}
		}
		system("cls");
	} while (key != '0');

	return 0;
}