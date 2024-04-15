#pragma once
#include "CustomStringNode.h"

class CustomString
{
private:
	CustomStringNode* head;
	int size;

public:
	CustomString();
	CustomString(const CustomString& to_copy);
	CustomString(const char* characters);
	~CustomString();

	void addCharacter(char new_character);
	void addCharacter(int num);
	void reverse();
	void merge(const CustomString& to_merge);

	int getSize() const;
	char getByIndex(const int index) const;

	void print() const;
	void clear();
};

