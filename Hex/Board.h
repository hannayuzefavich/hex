#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
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
	bool read();
	void clear();
private:	
	int getPawnsNumber();
	bool doesPathExist(pair<int,int> actual, pair<int,int> ending, map<pair<int,int>,bool>& visited, const char player);
	bool isConnected(char player);
	string isBoardCorrect();
	string isGameOver();
	string isBoardPossible();
	string customGetLine();
	bool readBoard();
	void readCommands();
	int abs(int num);
	
	//void printBoard(); //??
};

