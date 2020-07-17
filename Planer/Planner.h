#pragma once
#include "Day.h"

struct NodeP
{
	Day data;
	NodeP* next;
};

class Planner
{
private:
	NodeP* first = nullptr;
	NodeP* last = nullptr;
	int size = 0;

public:
	Planner() = default;
	Planner(const Planner& planner);
	~Planner();
	bool IsEmpty();
	void Unshift(const Day& element);
	void PushBack(const Day& element);
	void Shift();
	void Pop();
	void DeleteAll();
	void Show();
	Day& GetLastData();

};

Planner::Planner(const Planner& planner)
{
	if (planner.size > 1)
	{
		first = planner.first;
		last = planner.first;
		size = 1;

		NodeP* temp = planner.first->next;
		while (temp != nullptr)
		{
			PushBack(temp->data);
			temp = temp->next;
		}
	}
	else
	{
		first = planner.first;
		last = planner.last;
		size = planner.size;
	}
}

Planner::~Planner()
{
	if (!IsEmpty())
	{
		delete first;
		delete last;
	}
}

bool Planner::IsEmpty()
{
	return first == nullptr;
}

void Planner::Unshift(const Day& element)
{
	NodeP* newNodeP = new NodeP{ element, nullptr };
	if (IsEmpty())
	{
		first = newNodeP;
		last = newNodeP;
	}
	else
	{
		newNodeP->next = first;
		first = newNodeP;
	}
	size += 1;
}

void Planner::PushBack(const Day& element)
{
	NodeP* newNodeP = new NodeP{ element, nullptr };
	if (IsEmpty())
	{
		first = newNodeP;
		last = newNodeP;
	}
	else
	{
		last->next = newNodeP;
		last = newNodeP;
	}
	size += 1;
}

void Planner::Shift()
{
	if (size == 1)
	{
		first = nullptr;
		last = nullptr;
		delete first;
		size -= 1;
	}
	else if (!IsEmpty())
	{
		NodeP* SecondNodeP = first->next;
		delete first;
		first = SecondNodeP;
		size -= 1;
	}
}

void Planner::Pop()
{
	if (size == 1)
	{
		first = nullptr;
		last = nullptr;
		delete first;
		size -= 1;
	}
	else if (!IsEmpty())
	{
		NodeP* temp = first;
		while (temp->next != last)
			temp = temp->next;
		delete last;
		temp->next = nullptr;
		size -= 1;
	}
}

void Planner::DeleteAll()
{
	while (!IsEmpty())
		Shift();
}

void Planner::Show()
{
	NodeP* temp = first;
	cout << "List: \t";
	while (temp != nullptr)
		temp->data.ShowDay();

	cout << endl;
}

inline Day& Planner::GetLastData()
{
	return last->data;
}
