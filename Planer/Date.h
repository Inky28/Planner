#pragma once
#include <string>
#include <ctime>

using namespace std;

class Date 
{
private:
	int day;
	int month;
	int year;

public:
	Date(time_t time = time(nullptr));
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);
	int GetDay();
	int GetMonth();
	int GetYear();
	string GetDate();
	void PrintDate();
};

