#include "Board.h"

void Board::handleCommands(const string& str)
{
    if (str == "BOARD_SIZE")
    {
        cout << size << endl<< endl;
    }
    else if (str == "PAWNS_NUMBER")
    {
        cout << blue_pawns_number + red_pawns_number << endl << endl;
    }
    else if (str == "IS_BOARD_CORRECT")
    {
        cout << isBoardCorrect() << endl << endl;
    }
    else if (str == "IS_GAME_OVER")
    {
        cout << isGameOver() << endl << endl;
    }
    else if (str == "IS_BOARD_POSSIBLE")
    {
        cout << isBoardPossible() << endl << endl;
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
    if (not readBoard())
    {
        return false;
    }
    
    readCommands();
    return true;
}

vector<string> Board::getCommands()
{
    return commands;
}

bool Board::doesPathExist(const pair<int, int> actual, const pair<int, int>& ending, map<pair<int, int>, bool>& visited, const char player)
{
    
    if (actual.first < 0 or actual.first == this->size or actual.second < 0 or actual.second == this->size)
    {
        return false;
    }
    if (visited[actual] == true)
    {
        return false;
    }
    visited[actual] = true;

    if (this->board[actual.first][actual.second] != player)
    {
        return false;
    }
    if (actual == ending)
    {
        return true;
    }
   
    return doesPathExist({ actual.first - 1, actual.second }, ending, visited, player) or
        doesPathExist({ actual.first + 1, actual.second }, ending, visited, player) or
        doesPathExist({ actual.first, actual.second - 1 }, ending, visited, player) or
        doesPathExist({ actual.first, actual.second + 1 }, ending, visited, player) or
        doesPathExist({ actual.first - 1, actual.second + 1 }, ending, visited, player) or
        doesPathExist({ actual.first + 1, actual.second - 1 }, ending, visited, player);
}

bool Board::isConnected(const char player)
{
    vector<pair<int, int>> starting_points;
    vector<pair<int, int>> ending_points;
    map<pair<int,int>,bool> visited;
    
    for (int i = 0; i < size; i++)
    {
        if(player == 'r')
        {
            if (this->board[0][i] == player)
            {
                starting_points.push_back({ 0,i });
            }
        }
        else
        {
            if (this->board[i][0] == player)
            {
                starting_points.push_back({ i,0 });
            }
        }

    }
    for (int i = 0; i < this->size; i++)
    {

        if (player == 'r')
        {
            if (this->board[size - 1][i] == player)
            {
                ending_points.push_back({ size - 1,i });
            }
        }
        else
        {
            if (this->board[i][size - 1] == player)
            {
                ending_points.push_back({ i,size - 1 });
            }
        }      
    }

    for (const pair<int, int>& start_element : starting_points)
    {
        for (const pair<int, int>& end_element : ending_points)
        {
            if (doesPathExist(start_element, end_element, visited, player))
            {
                return true;
            }

            for (pair<const pair<int, int>, bool>& pair : visited)
            {
                pair.second = false;
            }
        }
    }
    return false;
}

string Board::isBoardCorrect() //TODO: check the corresponding numbers of players' pawns
{
    if (red_pawns_number - blue_pawns_number == 1 or red_pawns_number - blue_pawns_number == 0)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

string Board::isGameOver() //TODO: who won
{
    if (isBoardCorrect() == "NO")
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
    if (isBoardCorrect() == "NO")
    {
        return "NO";
    }

    bool red_wins = isConnected('r');
    bool blue_wins = isConnected('b');

    if ((red_wins and blue_wins) or
        (red_wins and red_pawns_number == blue_pawns_number) or
        (blue_wins and red_pawns_number > blue_pawns_number) or
        (red_pawns_number + blue_pawns_number == this->size * this->size))
    {
        return "NO";
    }

    char player = red_wins ? 'r' : 'b';

    for (string& line : this->board)
    {
        for (char& c : line)
        {
            if (c == player)
            {
                c = ' ';
                if (isConnected(player))
                {
                    c = player;
                    return "NO";
                }

                c = player;
            }
        }
    }
    
    
    return "YES";
}

bool Board::readBoard()
{
    if (cin.get() == '\n' or cin.eof())
    {
        return false;
    }

    char c = ' ';
    int spaces = 0;

    while (c != '\n')
    {
        cin.get(c);
        if (c == ' ') spaces++;
    }

    this->size = (++spaces / 3) + 1;
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
        if (prev == 'r') this->red_pawns_number++;
        else if (prev == 'b') this->blue_pawns_number++;
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
            if (line.empty())
            {
                return;
            }
            if (line.size() > 0)
            {
                this->commands.push_back(line);
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
}

void Board::clear()
{
    board.clear();
    commands.clear();
}
