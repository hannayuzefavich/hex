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

int main() {
    vector <string> board, commands;
    read(board, commands);

    for (string el : board)
    {
        cout << el << endl;
    }
    
    

	return 0;
}
