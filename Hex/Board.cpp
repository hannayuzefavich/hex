#include "Board.h"


Board::Board()
{

}

void Board::handleCommands(const string& str)
{
    if (str == "BOARD_SIZE")
    {
        cout << this->getSize() << endl;
    }
    else if (str == "PAWNS_NUMBER")
    {
        cout << this->getPawnsNumber() << endl;
    }
    else if (str == "IS_BOARD_CORRECT")
    {
        cout << this->isBoardCorrect() << endl;
    }
    else if (str == "IS_GAME_OVER")
    {
        cout << this->isGameOver() << endl;
    }
    else if (str == "IS_BOARD_POSSIBLE")
    {
        cout << this->isBoardPossible() << endl;
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

bool Board::read()
{
    if (not readBoard()) return false;
    readCommands();
    return true;
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

bool Board::doesPathExist(pair<int, int> actual, pair<int, int> ending, map<pair<int, int>, bool>& visited, const char player)
{
    
    if (actual.first < 0 or actual.first == size or actual.second < 0 or actual.second == size)
    {
        return false;
    }
    //cout << actual.second << " " << actual.first << " " << board[actual.first][actual.second]<<" " << player << endl;
    if (visited[actual] == true)
    {
        return false;
    }
    if (board[actual.first][actual.second] != player)
    {
        return false;
    }
    if (actual == ending)
    {
        return true;
    }
    /*else
    {
        cout << actual.first << " " << actual.second << " " << ending.first << " " << ending.second << endl;
    }*/
    visited[actual] = true;
    return doesPathExist({ actual.first - 1, actual.second }, ending, visited, player) or
        doesPathExist({ actual.first + 1, actual.second }, ending, visited, player) or
        doesPathExist({ actual.first, actual.second - 1 }, ending, visited, player) or
        doesPathExist({ actual.first, actual.second + 1 }, ending, visited, player) or
        doesPathExist({ actual.first + 1, actual.second - 1 }, ending, visited, player) or
        doesPathExist({ actual.first - 1, actual.second + 1 }, ending, visited, player);
}

bool Board::isConnected(const char player)
{
    int size = this->getSize();
    vector<pair<int, int>> starting_points;
    vector<pair<int, int>> ending_points;
    map<pair<int,int>,bool> visited;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            pair<int, int> coords = { i,j };
            visited[coords] = false;
        }
    }
    for (int i = 0; i<size; i++)
    {
        if(player == 'r')
        {
            if (this->board[0][i] == player)
            {
                pair<int, int> coords = { 0,i };
                starting_points.push_back(coords);
            }
        }
        else
        {
            if (this->board[i][0] == player)
            {
                pair<int, int> coords = { i,0 };
                starting_points.push_back(coords);
            }
        }

    }
    for (int i = 0; i < size; i++)
    {

        if (player == 'r')
        {
            if (this->board[size - 1][i] == player)
            {
                pair<int, int> coords = { size - 1,i };
                ending_points.push_back(coords);
            }
        }
        else
        {
            if (this->board[i][size - 1] == player)
            {
                pair<int, int> coords = { i,size - 1 };
                ending_points.push_back(coords);
            }
        }      
    }

    /*for (int i = 0; i < ending_points.size(); i++)
    {
        cout << ending_points[i].first << " ";
        cout << ending_points[i].second << endl;;
    }*/

    for (pair<int, int> start_element : starting_points)
    {
        for (pair<int, int> end_element : ending_points)
        {
            if (doesPathExist(start_element, end_element, visited, player))
            {
                return true;
            }
        }
    }
    return false;




   /* for (int i = 0; i < starting_points.size(); i++)
    {
        cout << starting_points[i].first<<" ";
        cout << starting_points[i].second << endl;;
    }
    cout << endl;
    for (int i = 0; i < ending_points.size(); i++)
    {
        cout << ending_points[i].first << " ";
        cout << ending_points[i].second << endl;;
    }*/

    return false;
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
    string test = isBoardCorrect();
    if (test == "NO")
    {
        return "NO";
    }
    if (isConnected('r'))
    {
        return "YES RED";
    }
    else if (isConnected('b'))
    {
        return "YES BLUE";
    }
    else
    {
        return "NO";
    }
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

bool Board::readBoard()
{
    char c = ' ';
    int spaces = 0;

    if (not cin.get(c))
    {
        return false;
    }

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

    return true;
}

void Board::readCommands()
{
    string line;
    char c;

    while (cin.get(c))
    {   
        if (c == '\n')
        {
            if (line.size() > 0)
            {
                commands.push_back(line);
                line.clear();
            }
            else
            {
                break;
            }
            
        }
        else
        {
            line += c;
        }
    }

    if (not line.empty())
    {
        commands.push_back(line);
    }
}

int Board::abs(int num)
{
    return (num < 0) ? -num : num;
}

void Board::clear()
{
    board.clear();
    commands.clear();
}
