#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Board
{
private:
	vector<string> board;
	vector<string> commands;
	int red_pawns_number;
	int blue_pawns_number;
	int size;
public:	
	Board();
	int getSize();
	vector<string> getCommands();
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

