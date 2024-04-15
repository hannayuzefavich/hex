#include "CustomString.h"

CustomString::CustomString()
{
	this->head = nullptr;
	this->size = 0;
}

CustomString::CustomString(const CustomString& to_copy)
{
	this->head = nullptr;
	this->size = 0;
	
	if (&to_copy != nullptr)
	{
		for (int i = 0; i < to_copy.size; i++)
		{
			this->addCharacter(to_copy.getByIndex(i));
		}
	}
}

CustomString::CustomString(const char* characters)
{
	int i = 0;

	while (characters[i] != '\0')
	{
		this->addCharacter(characters[i]);
		i++;
	}
}

CustomString::~CustomString()
{
	CustomStringNode* current = this->head;

	while (current != nullptr)
	{
		CustomStringNode* next = current->getNext();
		delete current;
		current = next;
	}
}


void CustomString::addCharacter(char new_character)
{
	CustomStringNode* new_node = new CustomStringNode(new_character);
	if (this->head == nullptr)
	{
		this->head = new_node;
	}
	else
	{
		CustomStringNode* current = this->head;

		while (current->getNext() != nullptr)
		{
			current = current->getNext();
		}

		current->setNext(new_node);
	}
	
	this->size++;
}

void CustomString::addCharacter(int num)
{
	CustomString s_num;
	char digit;
	bool is_negative = false;

	if (num == 0) 
	{
		digit = '0';
		s_num.addCharacter(digit);
		this->merge(s_num);
		return;
	}

	if (num < 0) 
	{
		is_negative = true;	
		num *= -1;
	}

	while (num > 0)
	{
		digit = '0' + (num % 10);
		s_num.addCharacter(digit);
		num /= 10;
	}

	if (is_negative) 
	{
		s_num.addCharacter('-');
	}

	s_num.reverse();

	this->merge(s_num);
}

void CustomString::reverse()
{
	CustomStringNode* f_prev = nullptr, *current = this->head, *f_next = nullptr;

	while (current != nullptr) 
	{
		f_next = current->getNext();
		current->setNext(f_prev);
		f_prev = current;
		current = f_next;
		//cout << current->getCharacter();
	}
	this->head = f_prev;
}

void CustomString::merge(const CustomString& to_merge)
{
	for (int i = 0; i < to_merge.size; i++)
	{
		this->addCharacter(to_merge.getByIndex(i));
	}
}

int CustomString::getSize() const
{
	return this->size;
}

char CustomString::getByIndex(const int index) const
{
	int i = 0;
	CustomStringNode* current = this->head;

	while (i < index)
	{
		current = current->getNext();
		i++;
	}

	return current->getCharacter();
}

void CustomString::print() const
{
	CustomStringNode* current = this->head;

	while (current != nullptr)
	{
		cout << current->getCharacter();
		current = current->getNext();
	}
}

void CustomString::clear()
{
	this->~CustomString();
	this->size = 0;
	this->head = nullptr;
}