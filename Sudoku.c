/*Simple Sudoku Game in C with its own Sudoku Solver*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> //sleep ()


void printGame (int game[9][9]);
bool noRep (int value, int x, int y, int game[9][9]);
void solveGame (int game [9][9]);
bool endGame (int game [9][9]);
void gameMenu (int game [9][9]);
void playGame (int game [9][9]);


int main ()
{
    //Already generated Sudoku field
    int spielFeld [9][9] = 
    {
        {1,0,4,0,9,0,3,0,6},
        {9,0,6,0,1,0,8,0,5},
        {5,0,0,0,4,0,2,0,0},
        {0,0,0,1,0,0,6,0,0},
        {0,0,0,9,0,0,1,0,4},
        {8,0,1,0,6,0,9,0,7},
        {2,0,8,0,3,0,0,0,0},
        {0,6,0,4,0,9,0,1,0},
        {0,1,0,6,0,8,0,3,0}
    };

    gameMenu (spielFeld);
    return 0;
}

//Function to print the Sudoku Game
void printGame (int game[9][9])
{
    printf("  *****Sudoku GAME*****\n\n");
    for (int i = 0; i < 9; i++)
    {
        i == 0 ? printf("-------------------------\n"):0;
        for (int j = 0; j < 9; j++)
        {
            j == 0 ? printf("| "):0;
            printf("%d ", game[i][j]);
            j == 2 || j == 5 || j == 8 ? printf("| "):0;
        }
        printf("\n");
        i == 2 || i == 5 || i == 8 ? printf("-------------------------\n"):0;
    }
}

//Function to make sure there's no repetitions 
bool noRep (int value, int x, int y, int game[9][9])
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

//Function to solve the Sudoku Game
void solveGame (int game[9][9])
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
    printGame (game); //print the result
}

//Function to choose which game mode to run
//either solving it yourself or letting the sudoku solver solve it
void gameMenu (int game [9][9])
{
    printf("\t\t******Welcome to SUDOKU IN C******\n\n");
    printf("Solve it yourself (a)   Let the very smart AI solve it for you (b)\n");
    char key;
    scanf("%c", &key);
    switch (key)
    {
        case 'a':
        playGame(game);
        break;

        case 'b':
        printGame (game);
        sleep (5);
        solveGame (game);
        break;
    }
    return;
}

//Function to check if the game is already over
bool endGame (int game [9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (game[i][j] == 0)
            {
                return false;
            }
            
        }
    }
    return true;
}

//function that runs the actual game
void playGame (int game [9][9])
{
    printGame (game); 
    int x, y, value;
    printf("\nROW: ");
    scanf("%d", &x);
    printf("\nCOL: ");
    scanf("%d", &y);
    printf("\nValue: ");
    scanf("%d", &value);
    if (noRep(value, x-1, y-1, game))
    {
        game[x-1][y-1] = value;
    }
    else 
    {
        printf("\nDuplicate number, try again!\n");
        playGame (game);
    }
    
    if (endGame(game))
    {
        return;
    }
    else 
    {
        playGame(game);
    }
}