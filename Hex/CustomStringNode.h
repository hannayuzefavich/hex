#pragma once
#include <iostream>

using namespace std;

class CustomStringNode
{
private:
	char character;
	CustomStringNode* next;
public:
	CustomStringNode(char new_character);

	void setNext(CustomStringNode* new_next);

	CustomStringNode* getNext();
	char getCharacter();
};

