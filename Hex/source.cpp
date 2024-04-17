#include <iostream>
#include <string>
#include <vector>

using namespace std;

void readBoard(vector<string>& board)
{
    string line;

    getline(cin, line);
    int board_size = (count(line.begin(), line.end(), ' ') / 3) + 1;
    board.insert(board.end(), board_size, "");

    bool after_middle = false;
    int j, k = 0;
    
    while (getline(cin, line))
    {
        if (line[0] == '<')
        {
            after_middle = true;
        }

        line.erase(0, line.find_first_not_of(' '));
        line.erase(remove(line.begin(), line.end(), '<'), line.end());
        line.erase(remove(line.begin(), line.end(), '>'), line.end());
        line.erase(remove(line.begin(), line.end(), '-'), line.end());

        if (line.size() == 0) break;

        j = 0;
        if (after_middle)
        {
            j = k;
            k++;
        }

        for (int i = 1; i < line.size(); i += 3, j++)
        {
            board[j] = line[i] + board[j];
        }
    }
}

void readCommands(vector<string>& commands)
{
    string line;

    while (getline(cin, line))
    {
        commands.push_back(line);
    }
}

void read(vector<string>& board, vector<string>& commands)
{
    readBoard(board);
    readCommands(commands);
}

int getBoardSize(vector<string>& board) {
    return board.size();
}

void handleCommands(const string& str)
{
    if (str == "BOARD_SIZE")
    {
        
    }
    else if (str == "PAWNS_NUMBER")
    {

    }
    else if (str == "IS_BOARD_CORRECT")
    {

    }
    else if (str == "IS_GAME_OVER")
    {

    }
    else if (str == "IS_BOARD_POSSIBLE")
    {

    }
    else if (str == "CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT")
    {

    }
    else if (str == "CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT")
    {

    }
    else if (str == "CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT")
    {

    }
    else if (str == "CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT")
    {

    }
    else if (str == "CAN_RED_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT")
    {

    }
    else if (str == "CAN_BLUE_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT")
    {

    }
    else if (str == "CAN_RED_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT")
    {

    }
    else if (str == "CAN_BLUE_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT")
    {

    }else {
        cout << "UNDEFINED";
    }
        
}

int main() {
    vector <string> board, commands;
    read(board, commands);

    for (string el : board)
    {
        cout << el << endl;
    }
    for (string com : commands)
    {
        cout << com << endl;
    }
	return 0;
}
