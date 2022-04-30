#This is a Sudoku Game in Python with 3 difficulties, 
#and its own Sudoku Solver 

import random
from tkinter import Grid

print ("SUDOKU IN PYTHON\n\nWhich difficulty do you want to play ?\nEASY (a)\tMEDIUM (b)\tHARD (c)")
difficultyMessage = "EASY (a)\tMEDIUM (b)\tHARD (c)"
difficultyWanted = "abc"
def limitLetter (wanted, errormessage):
    userInput = input()
    for x in wanted:
        if x == userInput:
            return userInput
    print("\n## Wrong input, try again! ##")
    print(errormessage)
    return limitLetter(wanted,errormessage)
difficultyKey = limitLetter (difficultyWanted, difficultyMessage)
def createGame (difficulty):
    array = [[1,2,9,5,4,3,7,8,6],
             [7,3,5,8,6,9,4,2,1],
             [4,8,6,1,2,7,3,5,9],
             [2,1,3,4,9,8,6,7,5],
             [9,6,7,3,1,5,2,4,8],
             [8,5,4,2,7,6,1,9,3],
             [3,4,2,9,8,1,5,6,7],
             [6,9,1,7,5,4,8,3,2],
             [5,7,8,6,3,2,9,1,4]]
    for i in range(9):
        for j in range(9):
            if random.random () < difficulty:
                array[i][j] = 0
    return array
def printGame (array):
    print()
    for i in range(9):
        for j in range(9):
            print(array[i][j],end = " ")
            if j == 2 or j == 5:
                print ("|", end = " ")
        print()
        if i == 2 or i == 5:
            print("----------------------")     
difficulties = {"a" : 0.3, "b" : 0.4, "c" : 0.6}
array = createGame (difficulties[difficultyKey])
printGame (array)
solveMessage = "\nSolve it yourself (a) OR let the AI solve it for you (b)"
print (solveMessage)
solveWanted = "ab"
solveKey = limitLetter (solveWanted, solveMessage)
def noRep (value, x, y, game):
    for i in range (9):
        for j in range (9):
            if value != 0 and (value == game[x][j] or value == game[i][y] or x/3 == i/3 and y/3 == j/3 and value == game [i][j]):
                return False
    return True
def solve (array):
    for i in range (9):
        for j in range (9):
            if array[i][j] == 0:
                for n in range (1,10):
                    if noRep (n, i, j, array):
                        array [i][j] = n
                        solve(array)
                        array [i][j] = 0
                return 
    printGame (array)
def limitNumber (errormssg):
    numberInput = input()
    length = len (numberInput)
    counter = 0
    for x in numberInput:
        if ord(x) < 48 or ord(x) > 57 or length > 1:
            break
        else:
            counter += 1
    if counter == len(numberInput):
        return numberInput
    else:
        print("Wrong input, try again!")
        print(errormssg, end = "")
        numberInput = limitNumber(errormssg)
    return numberInput
def playGame (game):
    printGame (game)
    rowMessage = "ROW: "
    print(rowMessage, end = "")
    row = int (limitNumber (rowMessage))
    columnMessage = "COLUMN: "
    print(columnMessage, end = "")
    column = int (limitNumber (columnMessage))
    valueMessage = "VALUE: "
    print(valueMessage, end = "")
    value = int (limitNumber (valueMessage))
    while noRep(value, row-1, column-1, array) == False:
        print ("\nWrong input try again\n")
        playGame (game)
    game[row-1][column-1] = value
    playGame (game)

if solveKey == 'a':
    playGame (array)
if solveKey == 'b':
    solve(array)
