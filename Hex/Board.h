#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Board
{
private:
	vector<string> board;
	vector<string> commands;
	int size;
public:	
	void handleCommands();
	void read();
private:
	int getSize();
	void getBoard();
	void getCommands();


};

