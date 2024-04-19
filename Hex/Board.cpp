#include "Board.h"

Board::Board(vector<string> board, vector<string> commands)
{
    this->board = board;
    this->commands = commands;
}

void Board::handleCommands(const string& str)
{
    if (str == "BOARD_SIZE")
    {
        this->getSize();
    }
    else if (str == "PAWNS_NUMBER")
    {
        this->getPawnsNumber();
    }
    else if (str == "IS_BOARD_CORRECT")
    {
        this->isBoardCorrect();
    }
    else if (str == "IS_GAME_OVER")
    {
        this->isGameOver();
    }
    else if (str == "IS_BOARD_POSSIBLE")
    {
        this->isBoardPossible();
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

    }
    else {
        cout << "UNDEFINED";
    }
}

void Board::read()
{
    readBoard();
    readCommands();
}

int Board::getSize()
{
    return this->size;
}

int Board::getPawnsNumber()//TODO: count overall pawns number on the board
{
    int pawn_counter = 0;

    for (string row : this->board)
    {
        for (char c : row)
        {
            if (c == 'r' or c == 'b')
            {
                pawn_counter++;
            }
        }
    }
    return pawn_counter;
}

string Board::isBoardCorrect() //TODO: check the corresponding numbers of players' pawns
{    
    int red = 0;
    int blue = 0;
    string result;

    for (string row : this->board)
    {
        for (char c : row)
        {
            if (c == 'r')
            {
                red++;
            }
            if (c == 'b')
            {
                blue++;
            }
        }
    }
    int difference = abs(red - blue);
    if (difference == 1 or difference == 0) 
    {
        result = "YES";
    }
    else
    {
        result = "NO";
    }
    return result;
}

string Board::isGameOver() //TODO: who won
{
    string result;
    bool all_blue = true;
    bool all_red = true;
    for (string row : this->board)
    {
        for (char c : row)
        {
            if (c != 'b')
            {
                all_blue = false;
                break;
            }
        }     
    }

    for (int i = 0; i < this->getSize(); i++)
    {
        for (int j = 0; j < this->getSize(); j++)
        {
            if (this->board[i][j] != 'r')
            {
                all_red == false;
                break;
            }
        }
    }

    if (all_blue)
    {
        result = "YES BLUE";
    }
    else if (all_red)
    {
        result = "YES RED";
    }
    else
    {
        result = "NO";
    }

    return result;
}

string Board::isBoardPossible()
{
    //TODO: are the players' positions reasonable
}

string Board::customGetLine()
{
    char c;
    string line;
    while (cin.get(c))
    {
        if (c == '\n')
        {
            break;
        }
        else
        {
            line += c;
        }
    }
    return line;
}

void Board::readBoard()
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

void Board::readCommands()
{
    string line;
    char c;

    while (cin.get(c))
    {
        if (c == '\n')
        {
            commands.push_back(line);
            line.clear();
        }
        else
        {
            line += c;//append?
        }
    }

    if (!line.empty())
    {
        commands.push_back(line);
    }
    
    /*while (getline(cin, line))
    {
        commands.push_back(line);
    }*/
}

int Board::abs(int num)
{
    return (num < 0) ? -num : num;
}
