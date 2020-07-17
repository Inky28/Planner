#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include "Date.h"

using namespace std;

Date::Date(time_t time)
{
	tm* gmtm = gmtime(&time);

	SetDay(gmtm->tm_mday);
	SetMonth(gmtm->tm_mon + 1);
	SetYear(1970 + time / 31536000);
}

void Date::SetDay(int day) 
{
	if (day > 0 && day <= 366)
		this->day = day;
}

void Date::SetMonth(int month)
{
	if (month > 0 && month <= 12)
		this->month = month;
}

void Date::SetYear(int year) 
{
	if (year >= 1970 && year <= 3000)
		this->year = year;
}

int Date::GetDay() 
{
	return day;
}

int Date::GetMonth() 
{
	return month;
}

int Date::GetYear() 
{
	return year;
}

string Date::GetDate() 
{
	string dayS = "";
	string monthS = "";
	if (day < 10)
		dayS += "0" + to_string(day);
	else
		dayS += to_string(day);

	if (month < 10)
		monthS += "0" + to_string(month);
	else
		monthS += to_string(month);

	return dayS + "." + monthS + "." + to_string(year);
}

void Date::PrintDate() 
{
	cout << GetDate();
}