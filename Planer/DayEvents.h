#pragma once
#include "Event.h"

struct Node
{
	Event data;
	Node* next;
};

class DayEvents
{
private:
	Node* first = nullptr;
	Node* last = nullptr;
	int size = 0;

public:
	DayEvents() = default;
	DayEvents(const DayEvents& planner);
	~DayEvents();
	bool IsEmpty();
	void Unshift(const Event& element);
	void PushBack(const Event& element);
	void Shift();
	void Pop();
	void DeleteAll();
	void Show();
};

inline DayEvents::DayEvents(const DayEvents& planner)
{
	if (planner.size > 1)
	{
		first = planner.first;
		last = planner.first;
		size = 1;

		Node* temp = planner.first->next;
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


inline DayEvents::~DayEvents()
{
	if (!IsEmpty())
	{
		delete first;
		delete last;
	}
}

inline bool DayEvents::IsEmpty()
{
	return first == nullptr;
}

inline void DayEvents::Unshift(const Event& element)
{
	Node* newNode = new Node{ element, nullptr };
	if (IsEmpty())
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		newNode->next = first;
		first = newNode;
	}
	size += 1;
}

inline void DayEvents::PushBack(const Event& element)
{
	Node* newNode = new Node{ element, nullptr };
	if (IsEmpty())
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}
	size += 1;
}

inline void DayEvents::Shift()
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
		Node* SecondNode = first->next;
		delete first;
		first = SecondNode;
		size -= 1;
	}
}

inline void DayEvents::Pop()
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
		Node* temp = first;
		while (temp->next != last)
			temp = temp->next;
		delete last;
		temp->next = nullptr;
		size -= 1;
	}
}

inline void DayEvents::DeleteAll()
{
	while (!IsEmpty())
		Shift();
}

inline void DayEvents::Show()
{
	Node* temp = first;
	cout << "List: \t";
	while (temp != nullptr)
		temp->data.ShowEvent();

	cout << endl;
}