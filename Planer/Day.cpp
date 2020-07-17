#include "Day.h"

Day::Day(time_t time)
{
	Date newDate(time);
	this->date = newDate;
}

void Day::ShowDay()
{
	cout << "Date: " << date.GetDate() << endl;
	events.Show();
}

void Day::AddEvent() 
{
	Event temp;
	events.PushBack(temp);
}

DayEvents& Day::GetEvents()
{
	return events;
}

