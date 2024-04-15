#pragma once
#include "ListNodeCustomString.h"

class ListCustomString
{
private:
	ListNodeCustomString* head;
	ListNodeCustomString* tail;
	int size;

public:
	ListCustomString();
	ListCustomString(const ListCustomString& to_copy);
	~ListCustomString();

	void addElement(const CustomString& new_value);

	CustomString getByIndex(int index) const;
	ListNodeCustomString* getNodeByIndex(int index) const;
	int getSize() const;

	void print() const;
	void printPart(int index) const;
	void pop(int index);
	void insert(int index, const CustomString& newElement);

	void clear();
};

