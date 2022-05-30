def printBoard(board):
    print(" {} | {} | {}".format(board[0], board[1], board[2]))
    print("-----------")
    print(" {} | {} | {}".format(board[3], board[4], board[5]))
    print("-----------")
    print(" {} | {} | {}".format(board[6], board[7], board[8]))

emptyBoard = ["-", "-", "-", "-", "-", "-", "-", "-", "-"]

def playGame (board):
    printBoard(board)
    print("Which field do you want to play (1-9) ?")
    print("Player 1: ", end= "")
    field = int(input())
    while (correctPlay(board, field) == False):
        print("Field already occupied! \nTry another one")
        print("Player 1: ", end= "")
        field = int(input())
    board[field-1] = "X"
    if(xWin(board)):
        print("Player 1 won!")


    printBoard(board)
    print("Which field do you want to play (1-9) ?")
    print("Player 2: ", end= "")
    field = int(input())
    while (correctPlay(board, field) == False):
        print("Field already occupied! \nTry another one")
        print("Player 2: ", end= "")
        field = int(input())
    board[field-1] = "O"
    if(xWin(board)):
        print("Player 2 won!")

    playGame(board)

def correctPlay (board, number):
    if (board[number-1] != "-"):
        return False
    else:
        return True

def xWin (board):
    if (board[0] == "X" and board[1] == "X" and board[2] == "X"):
        return True
    elif (board[3] == "X" and board[4] == "X" and board[5] == "X"):
        return True 
    elif (board[6] == "X" and board[7] == "X" and board[8] == "X"):
        return True 
    elif (board[0] == "X" and board[3] == "X" and board[6] == "X"):
        return True
    elif (board[1] == "X" and board[4] == "X" and board[7] == "X"):
        return True
    elif (board[2] == "X" and board[5] == "X" and board[8] == "X"):
        return True
    elif (board[0] == "X" and board[4] == "X" and board[8] == "X"):
        return True
    elif (board[2] == "X" and board[4] == "X" and board[6] == "X"):
        return True
    else:
        return False

def oWin (board):
    if (board[0] == "O" and board[1] == "O" and board[2] == "O"):
        return True
    elif (board[3] == "O" and board[4] == "O" and board[5] == "O"):
        return True 
    elif (board[6] == "O" and board[7] == "O" and board[8] == "O"):
        return True 
    elif (board[0] == "O" and board[3] == "O" and board[6] == "O"):
        return True
    elif (board[1] == "O" and board[4] == "O" and board[7] == "O"):
        return True
    elif (board[2] == "O" and board[5] == "O" and board[8] == "O"):
        return True
    elif (board[0] == "O" and board[4] == "O" and board[8] == "O"):
        return True
    elif (board[2] == "O" and board[4] == "O" and board[6] == "O"):
        return True
    else:
        return False
