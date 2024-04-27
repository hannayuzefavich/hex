#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

int main() {
	Board board;
	while (board.read())
	{
		for (int i = 0; i < board.getCommands().size(); i++)
		{
			board.handleCommands(board.getCommands()[i]);
		}
		board.clear();
	}
	return 0;
}
