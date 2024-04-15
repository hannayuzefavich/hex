#include "ListCustomString.h"

ListCustomString::ListCustomString()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

ListCustomString::ListCustomString(const ListCustomString& to_copy)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;

	if (&to_copy != nullptr)
	{
		for (int i = 0; i < to_copy.size; i++)
		{
			this->addElement(to_copy.getByIndex(i));
		}
	}
}

ListCustomString::~ListCustomString()
{
	ListNodeCustomString* current = this->head;

	while (current != nullptr)
	{
		ListNodeCustomString* next = current->getNext();
		delete current;
		current = next;
	}
}

void ListCustomString::addElement(const CustomString& new_value)
{
	ListNodeCustomString* new_element = new ListNodeCustomString(new_value);
	if (this->head == nullptr)
	{		
		this->head = new_element;
		this->tail = new_element;
	}
	else
	{
		this->tail->setNext(new_element);
		new_element->setPrev(tail);
		this->tail = new_element;		
	}
	this->size++;
}

CustomString ListCustomString::getByIndex(int index) const
{
	int i = 0;
	ListNodeCustomString* current = this->head;

	while (i < index)
	{
		current = current->getNext();
		i++;
	}

	return current->getValue();
}

ListNodeCustomString* ListCustomString::getNodeByIndex(int index) const 
{
	int i = 0;
	ListNodeCustomString* current = this->head;

	while (i < index)
	{
		current = current->getNext();
		i++;
	}

	return current;
}

int ListCustomString::getSize() const
{
	return this->size;
}

void ListCustomString::print() const
{
	ListNodeCustomString* current = this->head;
	while (current != nullptr)
	{
		current->getValue().print();
		if (current->getNext() != nullptr)
		{
			cout << ' ';
		}
		current = current->getNext();
	}
}

void ListCustomString::printPart(int index) const
{
	int i = this->getSize() - 1;
	ListNodeCustomString* current = this->tail;
	while (i > index) 
	{
		current = current->getPrev();
		i--;
	}
	while (current != nullptr) 
	{
		current->getValue().print();
		cout<<" ";
		current = current->getPrev();
	}
}

void ListCustomString::pop(int index) 
{
	if (index == 0) 
	{
		ListNodeCustomString* newHead = this->head->getNext();
		delete this->head;
		this->head = newHead;
		this->head->setPrev(nullptr);
		if (this->head == nullptr) 
		{
			this->tail = nullptr;
		}
		this->size--;
		return;
	}
	ListNodeCustomString* current = this->head;
	int i = 0;
	while (i < index) 
	{
		current = current->getNext();
		i++;
	}
	if (current == this->tail)
	{
		this->tail = this->tail->getPrev();
		this->tail->setNext(nullptr);
	}
	else 
	{
		current->getPrev()->setNext(current->getNext());
		current->getNext()->setPrev(current->getPrev());
	}

	delete current;
	this->size--;
}

void ListCustomString::insert(int index, const CustomString& newElement)
{
	ListNodeCustomString* newNode = new ListNodeCustomString(newElement);
	ListNodeCustomString* current = this->head;
	int i = 0;

	while (i < index - 1)
	{
		current = current->getNext();
		i++;
	}
	newNode->setNext(current->getNext());
	newNode->setPrev(current);
	if (current->getNext())
	{
		current->getNext()->setPrev(newNode);
	}
	current->setNext(newNode);
	if (current == tail)
	{
		tail = newNode;
	}
	this->size++;
}


void ListCustomString::clear() 
{
	this->~ListCustomString();
	this->size = 0;
	this->head = nullptr;
	this->tail = nullptr;
}