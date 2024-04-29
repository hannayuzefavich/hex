#include <iostream>
#include <vector>
#include <chrono>
#include "Board.h"

using namespace std;

int main() {
	auto start = std::chrono::high_resolution_clock::now();
	Board board;
	while (board.read())
	{
		for (int i = 0; i < board.getCommands().size(); i++)
		{
			board.handleCommands(board.getCommands()[i]);
		}
		board.clear();
	}
	auto end = std::chrono::high_resolution_clock::now();


	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	//std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;


	return 0;
}
