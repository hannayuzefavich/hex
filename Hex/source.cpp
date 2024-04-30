#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

int main() {
	Board board;
	vector <string> commands;
	while (board.read())
	{
		commands = board.getCommands();
		for (const string& command : commands)
		{
			board.handleCommands(command);
		}
		// board.printBoard();
		board.clear();
	}

	return 0;
}
