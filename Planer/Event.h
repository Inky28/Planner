#pragma once
#include <iostream>
#include <string>

using namespace std;

class Event 
{
private:
	string header;
	string body;
	bool isImportant;
public:
	Event();
	void SetHeader(string header);
	void SetBody(string body);
	void SetIsImportant(bool isImportant = false);
	string GetHeader();
	string GetBody();
	bool GetIsImportant();
	void ShowEvent();
};

