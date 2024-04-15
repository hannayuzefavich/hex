#pragma once
#include "CustomString.h"

class ListNodeCustomString
{
private:
	ListNodeCustomString* next;
	ListNodeCustomString* prev;
	CustomString value;

public:
	ListNodeCustomString(const CustomString& new_value);

	ListNodeCustomString* getNext();
	ListNodeCustomString* getPrev();
	CustomString getValue();

	void setNext(ListNodeCustomString* new_next);
	void setPrev(ListNodeCustomString* new_prev);
};

