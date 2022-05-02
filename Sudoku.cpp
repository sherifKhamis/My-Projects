/*Sudoku Game in C++ with its own Sudoku Solver, 
 limited user input for letters and numbers and a 
 randomized Sudoku game generator*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h> //srand()
#include <time.h> //time()
#include <string.h> //strlen()
#include <cctype> //isdigit()
using namespace std;

#define N 9

void gameMenu (int game [N][N]);
void printGame (int game[N][N]);
void createGame (int game [N][N], int difficulty);
void letterInput (char *wanted, char *input, string errormessage, int wantedLength);
bool noRep (int value, int x, int y, int game[N][N]);
void playGame (int game [N][N]);
void solveGame (int game[N][N]);


int main ()
{
    //Finished Sudoku Game 
    int spielFeld [N][N] = 
    {
        {1,2,9,5,4,3,7,8,6},
        {7,3,5,8,6,9,4,2,1},
        {4,8,6,1,2,7,3,5,9},
        {2,1,3,4,9,8,6,7,5},
        {9,6,7,3,1,5,2,4,8},
        {8,5,4,2,7,6,1,9,3},
        {3,4,2,9,8,1,5,6,7},
        {6,9,1,7,5,4,8,3,2},
        {5,7,8,6,3,2,9,1,4}
    };

    gameMenu (spielFeld);
    return 0;
}

//Function to print the Sudoku Game
void printGame (int game[N][N])
{
    printf("  *****Sudoku GAME*****\n\n");
    for (int i = 0; i < N; i++)
    {
        i == 0 ? printf("-------------------------\n"):0;
        for (int j = 0; j < N; j++)
        {
            j == 0 ? printf("| "):0;
            printf("%d ", game[i][j]);
            j == 2 || j == 5 || j == 8 ? printf("| "):0;
        }
        printf("\n");
        i == 2 || i == 5 || i == 8 ? printf("-------------------------\n"):0;
    }
}

//Function to create a randomized Sudoku Game
void createGame (int game [N][N], int difficulty)
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int random = rand() % (2+difficulty) + 1;
            if (random == 1 || random == 2)
            {
                game[i][j] = 0;
            }
        }
    }
}
//Function to limit letter user Input to a certain range of letters
void letterInput (char *wanted, char *input, string errormessage, int wantedLength)
{   
    int len = strlen (wanted);
    int inputLen = strlen (input);
    int result = 3;
    if (inputLen > wantedLength)
    {
        result = 0;
    }
    if (result == 3)
    {
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < inputLen; j++)
            {
                if (wanted[i] == input[j])
                {
                    result = 1;
                }
            }
        }
    }

    if (result == 1)
    {
        return;
    }
    else 
    {
        cout << "\nWrong input, try again !\n";
        cout << errormessage;
        cin >> input;
        letterInput (wanted, input, errormessage, wantedLength);
    }
}

//Function for the game menu where difficulty and gamemode are chosen
void gameMenu (int game [N][N])
{
    
    //Header and difficutly menu 
    printf("*****WELCOME TO SUDOKU IN C++*****\n\n");
    printf("Which difficulty do you want to play ?\n");
    string difficultyMessage = "EASY (a)\tMEDIUM (b)\tHARD (c)\n";
    cout << difficultyMessage;
    char difficulty [100];
    char wanted [] = "abc";
    cin >> difficulty;
    letterInput (wanted, difficulty, difficultyMessage, 1);

    //Gamemode menu
    string choiceMessage = "\nSolve the Sudoku yourself (a) or let the AI solve it for you (b) ?\n";
    cout << choiceMessage;
    char solveChoice[100];
    char wantedChoice [] = "ab";
    cin >> solveChoice;
    letterInput (wantedChoice, solveChoice, choiceMessage, 1);
    
    switch (solveChoice[0])
    {
        case 'a':
        switch (difficulty[0])
        {
            case 'a':
            createGame (game, 3);
            printGame (game);
            playGame(game);
            break;

            case 'b':
            createGame (game, 2);
            printGame (game);
            playGame(game);
        	break;

            case 'c':
            createGame (game, 1);
            printGame (game);
            playGame(game);
            break;
        }
        break;

        case 'b':
        switch (difficulty[0])
        {
            case 'a':
            createGame (game, 50);
            solveGame (game);
            cout << "\n\nSUDOKU SOLVED";
            break;

            case 'b':
            createGame (game, 15);
            solveGame (game);
            cout << "\n\nSUDOKU SOLVED";
        	break;

            case 'c':
            createGame (game, 5);
            solveGame (game);
            cout << "\n\nSUDOKU SOLVED";
            break;
        }
    }

}

//Function for the actual game
void playGame (int game [N][N])
{
    printGame(game);
    cout << "\nROW: ";
    char row, column, value;
    cin >> row;
    if (!isdigit(row))
    {
        while (!(isdigit(row)) )
        {
            printf("\nWrong input, try again!\nROW: ");
            cin >> row;
        }
    }
    cout << "\nCOLUMN: ";
    cin >> column;
    if (!isdigit(column))
    {
        while (!(isdigit(column)) )
        {
            printf("\nWrong input, try again!\nCOLUMN: ");
            cin >> column;
        }
    }
    cout << "\nValue: ";
    cin >> value;
    if (!isdigit(value))
    {
        while (!(isdigit(value)) )
        {
            printf("\nWrong input, try again!\nVALUE: ");
            cin >> value;
        }
    }

    int value2, row2, column2;
    value2 = value - '0';
    row2 = row - '0';
    column2 = column - '0';
    if (noRep(value2, row2-1, column2-1, game))
    {
        game[row2-1][column2-1] = value2;
    }
    else 
    {
        cout << "\nWrong, input! Value already in row, column or square !";
    }
    string continueMessage = "\n\nDo you want to continue (c) or exit (q) ?\n";
    cout << continueMessage;
    char wantedInput [] = "cq";
    char input[119];
    cin >> input;
    letterInput (wantedInput,input, continueMessage, 1);
    if (input[0] == 'q')
    {
        return;
    }
    else 
    {
        playGame (game);
    }

    


}

//function that ensures that theres no repetition
bool noRep (int value, int x, int y, int game[N][N])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
           if (value != 0 && (value == game[x][j] || value == game [i][y] || x/3 == i/3 && y/3 == j/3 && value == game[i][j]))
           {
               return false;
           }
        }
    }
    return true;
}

//function that solves the sudoku game via backtracking
void solveGame (int game[N][N])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (game[i][j] == 0)
            {
                for (int x = 1; x < 10; x++)
                {
                    if (noRep(x, i, j, game))
                    {
                        game [i][j] = x;
                        solveGame (game);
                        game [i][j] = 0;
                    }
                }
                return;
            }
        }
    }
    printGame (game);
}