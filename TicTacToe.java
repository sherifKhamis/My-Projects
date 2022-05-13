import java.util.*;


public class TicTacToe 
{
   public static void printBoard (char [][] board)
   {
        System.out.println("\nBoard: ");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                System.out.print(board[i][j]);
            }

            System.out.println();
        }
   } 

   public static void main (String [] args)
   {
    char defaultBoard[][] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    playGame(defaultBoard);
   }

   public static void playGame (char [][] board)
   {
    
    System.out.println("\n*****Tic Tac Toe in JAVA*****");
    printBoard(board);
    System.out.print("Player 1: Which row do you want to choose ?: ");
    Scanner input = new Scanner (System.in);
    int row = input.nextInt();
    System.out.print("\nPlayer 1: Which column do you want to choose ?: ");
    int column = input.nextInt();
    while (!validPlay(board, row, column))
    {
        System.out.println("\nField already completed choose another one !");
        printBoard(board);
        System.out.print("Player 1: Which row do you want to choose ?: ");
        row = input.nextInt();
        System.out.print("\nPlayer 1: Which column do you want to choose ?: ");
        column = input.nextInt();
    }
    board [row-1][column-1] = 'x';
    printBoard(board);

    System.out.print("Player 2: Which row do you want to choose ?: ");
    int row2 = input.nextInt();
    System.out.print("\nPlayer 2: Which column do you want to choose ?: ");
    int column2 = input.nextInt();
    while (!validPlay(board, row2, column2))
    {
        System.out.println("\nField already completed choose another one !");
        printBoard(board);
        System.out.print("Player 2: Which row do you want to choose ?: ");
        row2 = input.nextInt();
        System.out.print("\nPlayer 2: Which column do you want to choose ?: ");
        column2 = input.nextInt();
    }
    board [row2-1][column2-1] = 'o';
    printBoard(board);
    
    playGame(board);


        
   }

   public static boolean validPlay (char [][] board, int row, int column)
   {
       if (board[row-1][column-1] == '-')
       {
            return true;
       }
       return false;
   }

   public static boolean Xwin (char [][] board)
   {
       if (board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x')
       {
           return true;
       }
       if (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x')
       {
           return true;
       }
       if (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x')
       {
           return true;
       }
       if (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x')
       {
           return true;
       }       
       if (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x')
       {
           return true;
       }       
       if (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x')
       {
           return true;
       }
       if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x')
       {
           return true;
       }
       if (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x')
       {
           return true;
       }
       return false;
    }

   
};


