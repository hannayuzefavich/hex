#include "Board.h"

Board::Board()
{
    read();
}

void Board::handleCommands(const string& str)
{
    if (str == "BOARD_SIZE")
    {
        cout<<this->getSize();
    }
    else if (str == "PAWNS_NUMBER")
    {
        cout<<this->getPawnsNumber();
    }
    else if (str == "IS_BOARD_CORRECT")
    {
        cout<<this->isBoardCorrect();
    }
    else if (str == "IS_GAME_OVER")
    {
        cout<<this->isGameOver();
    }
    else if (str == "IS_BOARD_POSSIBLE")
    {
        cout<<this->isBoardPossible();
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

vector<string> Board::getCommands()
{
    return this->commands;
}

int Board::getPawnsNumber()//TODO: count overall pawns number on the board
{
    return this->red_pawns_number + this->blue_pawns_number;
}

string Board::isBoardCorrect() //TODO: check the corresponding numbers of players' pawns
{
    string result;

    if (this->blue_pawns_number == 1 and this->red_pawns_number == 0)
    {
        result = "NO";
    }
    int difference = abs(this->red_pawns_number - this->blue_pawns_number);

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
            if (this->board[i][j] != 'r')//Iterate by columns in vector of strings?
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

string Board::isBoardPossible() //TODO: are the players' positions reasonable
{   
    string result;
    string winner = this->isGameOver();
   
    if ((this->red_pawns_number == 0 and this->blue_pawns_number == 1) 
            or (abs(this->blue_pawns_number - this->red_pawns_number) > 1) 
            or (winner == "YES BLUE" and (this->red_pawns_number > this->blue_pawns_number))
            or (winner == "YES RED" and (this->red_pawns_number == this->blue_pawns_number)))
    {
        result = "NO";
    }
    else
    {
        result = "YES";
    }
    
    return result;
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
    char c = ' ';
    int spaces = 0;

    while (c != '\n')
    {
        cin.get(c);
        if (c == ' ') spaces++;
    }

    this->size = (spaces / 3) + 1;
    bool middle = false, finish = true;

    this->board.insert(board.end(), size, "");

    char prev;
    int i = 0, k = 0;
    this->red_pawns_number = 0;
    this->blue_pawns_number = 0;

    cin.get(prev);
    if (prev == '<')
    {
        cin.get(prev);
        cin.get(prev);
        board[i] = prev;
        finish = false;
    }

    while (cin.get(c))
    {
        if (prev == '\n' and c == '<')
        {
            middle = true;
        }

        if (c == '<')
        {
            cin.get(c);
            cin.get(c);
            board[i] = c + board[i];
            if (c == 'r') this->red_pawns_number++;
            else if (c == 'b') this->blue_pawns_number++;
            i++;
            finish = false;
        }
        else if (c == '\n')
        {
            if (finish) break;
            else finish = true;

            if (middle) k++;
            i = k;
        }
        prev = c;
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
            line += c;
        }
    }

    if (!line.empty())
    {
        commands.push_back(line);
    }
}

int Board::abs(int num)
{
    return (num < 0) ? -num : num;
}
