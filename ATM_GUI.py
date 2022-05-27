import tkinter as tk
from tkinter import ttk
from tkinter import *

window = tk.Tk()
window.title("ATM")
window_width = 600
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
window.configure(bg = "grey")

header = ttk.Label (window, text="Deutsche Bank ATM", foreground="white", font= "Arial 30", background="grey")
header.place(x = 120, y= 50)

text = tk.Text(window, height = 2, font = "Arial 30" ,width= 6)
text.place(x=230, y=160)

button_1 = ttk.Button (window, text='1', style="small.TButton", command = lambda: text.insert(INSERT,"1"))
button_1.place (x=190, y = 290, width = 60, height = 60)

button_2 = ttk.Button (window, text='2', style="small.TButton", command = lambda: text.insert(INSERT,"2"))
button_2.place (x=260, y = 290, width = 60, height = 60)

button_3 = ttk.Button (window, text='3', style="small.TButton", command = lambda: text.insert(INSERT,"3"))
button_3.place (x=330, y = 290, width = 60, height = 60)

button_4 = ttk.Button (window, text='4', style="small.TButton", command = lambda: text.insert(INSERT,"4"))
button_4.place (x=190, y = 360, width = 60, height = 60)

button_5 = ttk.Button (window, text='5', style="small.TButton", command = lambda: text.insert(INSERT,"5"))
button_5.place (x=260, y = 360, width = 60, height = 60)

button_6 = ttk.Button (window, text='6', style="small.TButton", command = lambda: text.insert(INSERT,"6"))
button_6.place (x=330, y = 360, width = 60, height = 60)

button_7 = ttk.Button (window, text='7', style="small.TButton", command = lambda: text.insert(INSERT,"7"))
button_7.place (x=190, y = 430, width = 60, height = 60)

button_8 = ttk.Button (window, text='8', style="small.TButton", command = lambda: text.insert(INSERT,"8"))
button_8.place (x=260, y = 430, width = 60, height = 60)

button_9 = ttk.Button (window, text='9', style="small.TButton", command = lambda: text.insert(INSERT,"9"))
button_9.place (x=330, y = 430, width = 60, height = 60)

button_0 = ttk.Button (window, text='0', style="small.TButton", command = lambda: text.insert(INSERT,"0"))
button_0.place (x=260, y = 500, width = 60, height = 60)

button_enter = ttk.Button (window, text='ENTER', style="small.TButton", command = lambda: get_pin())
button_enter.place (x=70, y = 360, width = 90, height = 60)

style = ttk.Style()
style.configure('small.TButton', font=(None, 15))

def get_pin():
    global pin
    pin = text.get("1.0","end-1c")
    print(pin)

window.mainloop()
