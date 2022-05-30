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
    board[field-1] = "X"

    printBoard(board)
    print("Which field do you want to play (1-9) ?")
    print("Player 2: ", end= "")
    field = int(input())
    board[field-1] = "O"

    playGame(board)

playGame(emptyBoard)

    