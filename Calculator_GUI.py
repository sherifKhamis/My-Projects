import tkinter as tk
from tkinter import ttk
from tkinter import *

window = tk.Tk()
window.title("Calculator")
window_width = 300
window_height = 600

# get the screen dimension
screen_width = window.winfo_screenwidth()
screen_height = window.winfo_screenheight()

# find the center point
center_x = int(screen_width/2 - window_width / 2)
center_y = int(screen_height/2 - window_height / 2)

window.geometry(f'{window_width}x{window_height}+{center_x}+{center_y}')
window.resizable(False, False)
window.attributes('-topmost', 1)
window.configure(bg = "Grey")

text = tk.Text(window, height = 2, font = "Arial 30")
text.place(x=0, y=50)

button_1 = ttk.Button (window, text='1', style="small.TButton", command = lambda: text.insert(INSERT,"1"))
button_1.place (x=4, y = 200, width = 60, height = 60)

button_2 = ttk.Button (window, text='2', style="small.TButton", command = lambda: text.insert(INSERT,"2"))
button_2.place (x=80, y = 200, width = 60, height = 60)

button_3 = ttk.Button (window, text='3', style="small.TButton", command = lambda: text.insert(INSERT,"3"))
button_3.place (x=156, y = 200, width = 60, height = 60)

button_4 = ttk.Button (window, text='4', style="small.TButton", command = lambda: text.insert(INSERT,"4"))
button_4.place (x=4, y = 280, width = 60, height = 60)

button_5 = ttk.Button (window, text='5', style="small.TButton", command = lambda: text.insert(INSERT,"5"))
button_5.place (x=80, y = 280, width = 60, height = 60)

button_6 = ttk.Button (window, text='6', style="small.TButton", command = lambda: text.insert(INSERT,"6"))
button_6.place (x=156, y = 280, width = 60, height = 60)

button_7 = ttk.Button (window, text='7', style="small.TButton", command = lambda: text.insert(INSERT,"7"))
button_7.place (x=4, y = 360, width = 60, height = 60)

button_8 = ttk.Button (window, text='8', style="small.TButton", command = lambda: text.insert(INSERT,"8"))
button_8.place (x=80, y = 360, width = 60, height = 60)

button_9 = ttk.Button (window, text='9', style="small.TButton", command = lambda: text.insert(INSERT,"9"))
button_9.place (x=156, y = 360, width = 60, height = 60)

button_0 = ttk.Button (window, text='0', style="small.TButton", command = lambda: text.insert(INSERT,"0"))
button_0.place (x=80, y = 440, width = 60, height = 60)

button_plus = ttk.Button (window, text='+', style="small.TButton", command = lambda: get_number("+"))
button_plus.place (x=232, y =200, width = 60, height = 60)

button_minus = ttk.Button (window, text='-', style="small.TButton", command = lambda:  get_number("-"))
button_minus.place (x=232, y = 280, width = 60, height = 60)

button_multiply = ttk.Button (window, text='x', style="small.TButton", command = lambda:  get_number("x"))
button_multiply.place (x=232, y = 360, width = 60, height = 60)

button_divide = ttk.Button (window, text='/', style="small.TButton", command = lambda:  get_number("/"))
button_divide.place (x=232, y = 440, width = 60, height = 60)

button_result = ttk.Button (window, text='=', style="small.TButton", command = lambda: equal())
button_result.place (x=232, y = 520, width = 60, height = 60)

style = ttk.Style()
style.configure('small.TButton', font=(None, 15))

def get_number(sign):
    global number1
    number1 = text.get("1.0", "end-1c")
    text.delete("1.0", END)
    global sign2
    sign2 = sign

def equal ():
    number2 = text.get("1.0", "end-1c")
    text.delete("1.0", END)
    if sign2 == "+":
        result = int(number1) + int (number2)
        text.insert(INSERT, result)
    if sign2 == "-":
        result = int(number1) - int (number2)
        text.insert(INSERT, result)
    if sign2 == "x":
        result = int(number1) * int (number2)
        text.insert(INSERT, result)
    if sign2 == "/":
        result = int(number1) / int (number2)
        text.insert(INSERT, result)
    
    





window.mainloop()

