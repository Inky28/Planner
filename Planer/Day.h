#pragma once
#include <ctime>
#include "Date.h"
#include "DayEvents.h"
#include "Event.h"

class Day 
{
private:
	Date date;
	DayEvents events;

public:
	Day(time_t time);
	void ShowDay();
	void AddEvent();
	DayEvents& GetEvents();
};

