#include "ListNodeCustomString.h"

ListNodeCustomString::ListNodeCustomString(const CustomString& new_value)
{
	this->next = nullptr;
	this->prev = nullptr;
	this->value.merge(new_value);
}

ListNodeCustomString* ListNodeCustomString::getNext()
{
	return this->next;
}

ListNodeCustomString* ListNodeCustomString::getPrev() {
	return this->prev;
}

CustomString ListNodeCustomString::getValue()
{
	return this->value;
}

void ListNodeCustomString::setNext(ListNodeCustomString* new_next)
{
	this->next = new_next;
}

void ListNodeCustomString::setPrev(ListNodeCustomString* new_prev) 
{
	this->prev = new_prev;
}

