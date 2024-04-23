#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

int main() {
	Board board;
	for (int i = 0; i < board.getCommands().size(); i++)
	{
		board.handleCommands(board.getCommands()[i]);
	}
	/*for (size_t i = 0; i < board.getCommands().size(); i++)
	{
		cout << board.getCommands()[i]<<endl;
	}*/
	return 0;
}
