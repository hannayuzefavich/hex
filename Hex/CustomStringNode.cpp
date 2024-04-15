#include "CustomStringNode.h"

CustomStringNode::CustomStringNode(char new_character)
{
	this->character = new_character;
	this->next = nullptr;
}

void CustomStringNode::setNext(CustomStringNode* new_next)
{
	this->next = new_next;
}

CustomStringNode* CustomStringNode::getNext()
{
	return this->next;
}

char CustomStringNode::getCharacter()
{
	return this->character;
}