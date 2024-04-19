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
	Board(vector<string> board, vector<string> commands);
	int getSize();
	void handleCommands(const string& str);
	void read();
private:	
	int getPawnsNumber();
	string isBoardCorrect();
	string isGameOver();
	string isBoardPossible();
	string customGetLine();
	void readBoard();
	void readCommands();
	int abs(int num);
	//void printBoard(); //??
};

