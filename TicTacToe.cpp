#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void printGame (vector <vector <char>> field);
bool validPlay (int row, int column, vector <vector <char>> field);
void playGame (vector <vector <char>> field);
bool Owin (vector <vector<char>> board);
bool Xwin (vector <vector<char>> board);
void gameMenu (vector <vector<char>> board);
void playAI (vector <vector<char>> field);


int main ()
{
    vector <vector <char>> defaultField = 
    {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'},
    };

    gameMenu(defaultField);


}

void printGame (vector <vector <char>> field)
{
    for (int i=0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " | ";
            cout << field[i][j];
        }
        cout << " | ";
        cout << endl;
        cout << "---------------" << endl;
    }
}

void playGame (vector <vector <char>> field)
{
    cout << "Welcome to TicTacToe in C++"<<endl;
    printGame(field);
    cout << "\nPlayer 1: Which ROW do you want to play ?:  ";
    int row, column;
    cin >> row;
    cout << "\nPlayer 1: Which COLUMN do you want to play ?:  ";
    cin >> column;
    while (!validPlay(row, column, field))
    {
        cout << "\nField already completed choose another one !\n";
        printGame(field);
        cout << "\nPlayer 1: Which row do you want to choose ?: ";
        cin >> row;
        cout << "\nPlayer 1: Which column do you want to choose ?: ";
        cin >> column;
    }
    field[row-1][column-1] = 'X';
    printGame(field);
    if (Xwin(field))
    {
        cout << "\nPlayer 1 won!";
        return;
    }

    cout << "\nPlayer 2: Which ROW do you want to play ?:  ";
    int row2, column2;
    cin >> row2;
    cout << "\nPlayer 2: Which COLUMN do you want to play ?:  ";
    cin >> column2;
    while (!validPlay(row2, column2, field))
    {
        cout << "\nField already completed choose another one !\n";
        printGame(field);
        cout << "\nPlayer 1: Which row do you want to choose ?: ";
        cin >> row2;
        cout << "\nPlayer 1: Which column do you want to choose ?: ";
        cin >> column2;
    }
    field[row2-1][column2-1] = 'O';
    printGame(field);
    if (Xwin(field))
    {
        cout << "\nPlayer 2 won!";
        return;
    }
    playGame(field);

}

bool validPlay (int row, int column, vector <vector <char>> field)
{
    if (field[row-1][column-1] != '-')
        return false;
    return true;
}

bool Xwin (vector <vector<char>> board)
{
       if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
       {
           return true;
       }
       if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
       {
           return true;
       }
       if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
       {
           return true;
       }
       if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
       {
           return true;
       }       
       if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
       {
           return true;
       }       
       if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
       {
           return true;
       }
       if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
       {
           return true;
       }
       if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
       {
           return true;
       }
       return false;
}

bool Owin (vector <vector<char>> board)
{
       if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
       {
           return true;
       }
       if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
       {
           return true;
       }
       if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
       {
           return true;
       }
       if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
       {
           return true;
       }       
       if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
       {
           return true;
       }       
       if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
       {
           return true;
       }
       if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
       {
           return true;
       }
       if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
       {
           return true;
       }
       return false;
}

void gameMenu (vector <vector<char>> board)
{
    cout << "\nWelcome to Tic Tac Toe in C++ !";
    cout << "\nDo you want to play against an AI (a) or a real player (b)?: ";
    char choice;
    cin >> choice;
    if (choice == 'a')
    {
        playAI(board);
    }
    else 
    {
        playGame(board);
    }

}

void playAI (vector <vector<char>> field)
{
    cout << "\nWelcome to Tic Tac Toe in C++ !" << endl;
    printGame(field);
    cout << "\nPlayer 1: Which ROW do you want to play ?:  ";
    int row, column;
    cin >> row;
    cout << "\nPlayer 1: Which COLUMN do you want to play ?:  ";
    cin >> column;
    while (!validPlay(row, column, field))
    {
        cout << "\nField already completed choose another one !\n";
        printGame(field);
        cout << "\nPlayer 1: Which row do you want to choose ?: ";
        cin >> row;
        cout << "\nPlayer 1: Which column do you want to choose ?: ";
        cin >> column;
    }
    field[row-1][column-1] = 'X';
    printGame(field);
    if (Xwin(field))
    {
        cout << "\nPlayer 1 won!";
        return;
    }

    srand(time(0)); 
    int row2, column2;
    row2 = (rand() % 3)+1;
    column2 = (rand() % 3)+1;
    while (!validPlay(row2, column2, field))
    {
        row2 = (rand() % 3)+1;
        column2 = (rand() % 3)+1;
    }
    field[row2-1][column2-1] = 'O';
    cout << "\n";
    if (Owin(field))
    {
        
        cout << "\nThe AI won!";
        return;
    }
    playAI(field);

}


