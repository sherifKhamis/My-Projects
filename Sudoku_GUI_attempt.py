#Sudoku Game in Python with a real GUI 

import tkinter as tk 
from tkinter import ttk 
from tkinter import *
import random

#Frontend 
#
#
# 
game = tk.Tk()
game.title("Sudoku Game")
window_width = 900
window_height = 600

# get the screen dimension
screen_width = game.winfo_screenwidth()
screen_height = game.winfo_screenheight()

# find the center point
center_x = int(screen_width/2 - window_width / 2)
center_y = int(screen_height/2 - window_height / 2)

game.geometry(f'{window_width}x{window_height}+{center_x}+{center_y}')
game.resizable(False, False)
game.attributes('-topmost', 1)
game.configure(bg = "Grey")

def Page_3 (element_1, element_2, array):
    element_1.destroy()
    element_2.destroy()
    text = Text(game, width= 27, height = 9)
    text.place(relx = 0.37,  rely = 0.25)
    strings = [str(x) for x in array]
    string = ("\n".join(strings))
    text.insert("3.0", string)
    text['state'] = 'disabled'

def createGame (difficulty, element_1, element_2, element_3):
    array = [[1,2,9,5,4,3,7,8,6],
             [7,3,5,8,6,9,4,2,1],
             [4,8,6,1,2,7,3,5,9],
             [2,1,3,4,9,8,6,7,5],
             [9,6,7,3,1,5,2,4,8],
             [8,5,4,2,7,6,1,9,3],
             [3,4,2,9,8,1,5,6,7],
             [6,9,1,7,5,4,8,3,2],
             [5,7,8,6,3,2,9,1,4]]
    for i in range(8):
        for j in range(8):
            if random.random () < difficulty:
                array[i][j] = 0
    Page_2(element_1, element_2, element_3, array)

def Page_2 (element_1, element_2, element_3, array):
    element_1.destroy()
    element_2.destroy()
    element_3.destroy()
    solveYourself_Button = ttk.Button(
    game,
    text='Solve it yourself',
    style= "small.TButton",
    command = lambda: Page_3 (solveYourself_Button, letAIsolve_button, array))
    solveYourself_Button.place (relx= 0.3, rely = 0.5, anchor = "center")
    letAIsolve_button = ttk.Button(
    game,
    text='Let the AI solve it for you',
    style= "small.TButton",
    command = lambda: Page_3 (solveYourself_Button, letAIsolve_button, array))
    letAIsolve_button.place (relx= 0.7, rely = 0.5, anchor = "center")


def Page_1 (element_1, element_2):
    element_1.destroy()
    element_2.destroy()
    header = ttk.Label(game, text='Sudoku Game', font=("Arial", 30), foreground = 'White', background= "Grey")
    header.place(relx= 0.35, rely = 0.05)
    difficulty_Button_1 = ttk.Button(
    game,
    text='EASY',
    style= "small.TButton",
    command = lambda: createGame (0.3, difficulty_Button_1, difficulty_Button_2, difficulty_Button_3))
    difficulty_Button_1.place (relx= 0.2, rely = 0.5, anchor = "center")
    difficulty_Button_2 = ttk.Button(
    game,
    text='MEDIUM',
    style= "small.TButton",
    command = lambda: createGame (0.5, difficulty_Button_1, difficulty_Button_2, difficulty_Button_3))
    difficulty_Button_2.place (relx= 0.5, rely = 0.5, anchor = "center")
    difficulty_Button_3 = ttk.Button(
    game,
    text='HARD',
    style= "small.TButton",
    command = lambda: createGame (0.7, difficulty_Button_1, difficulty_Button_2, difficulty_Button_3))
    difficulty_Button_3.place (relx= 0.8, rely = 0.5, anchor = "center")


header = ttk.Label(game, text='Sudoku Game', font=("Arial", 50), foreground = 'White', background= "Grey")
header.place(relx= 0.25, rely = 0.15)
style = ttk.Style()
start_button = ttk.Button(
    game,
    text='START',
    style= "medium.TButton",
    command= lambda: Page_1 (header, start_button)
)
exit_button = ttk.Button(
    game,
    text='EXIT',
    style= "medium.TButton",
    command= lambda: game.quit()
)
style.configure("medium.TButton", font=("Arial", 30))
style.configure("small.TButton", font=("Arial", 20))
style.map('medium.TButton',
                foreground=[('!active', 'grey'),
                            ('active', 'white')],
                background = [('!active', 'white'), ('active', 'Grey')])
style.map('small.TButton',
                foreground=[('!active', 'grey'),
                            ('active', 'white')],
                background = [('!active', 'white'), ('active', 'Grey')])
start_button.place (relx= 0.5, rely = 0.7, anchor = "center")
exit_button.place (relx= 0.5, rely = 0.85, anchor = "center")


game.mainloop()


