import tkinter as tk
from tkinter import ttk
from tkinter import *
from tkinter.messagebox import showerror

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

button_enter = ttk.Button (window, text='ENTER', style="small.TButton", command = lambda: correctPin())
button_enter.place (x=70, y = 360, width = 90, height = 60)

style = ttk.Style()
style.configure('small.TButton', font=(None, 15))

def get_pin():
    global pin
    pin = text.get("1.0","end-1c")
    return pin

def createDB():
    f = open("database.txt", "w")
    f.write("\n\nPIN: 1234\nBalance: 5000$")
    f.write("\n\nPIN: 1224\nBalance: 4780$")
    f.write("\n\nPIN: 1784\nBalance: 9422$")
    f.write("\n\nPIN: 9644\nBalance: 7853$")
    f.write("\n\nPIN: 7946\nBalance: 8421$")
    f.close()

createDB()

def correctPin ():
    f = open("database.txt", "r")
    content = f.readlines()
    for word in content:
        if word == "PIN: " + get_pin() + "\n":
            f.close()
            page_2()
            return True
    text.delete("1.0", END)
    showerror("Error", "Wrong PIN")


def page_2():

    text.destroy()
    button_0.destroy()
    button_1.destroy()
    button_2.destroy()
    button_3.destroy()
    button_4.destroy()
    button_5.destroy()
    button_6.destroy()
    button_7.destroy()
    button_8.destroy()
    button_9.destroy()
    button_enter.destroy()

    button_checkBalance = ttk.Button (window, text='Check Balance', style="small.TButton", command = lambda: checkBalance(button_deposit, button_withdraw))
    button_checkBalance.place (x=210, y = 200, width = 180, height = 60)

    button_deposit = ttk.Button (window, text='Deposit Cash', style="small.TButton")
    button_deposit.place (x=210, y = 300, width = 180, height = 60)

    button_withdraw = ttk.Button (window, text='Withdraw', style="small.TButton")
    button_withdraw.place (x=210, y = 400, width = 180, height = 60)

def checkBalance(element_1, element_2):
    element_1.destroy()
    element_2.destroy()
    f = open("database.txt", "r")
    content = f.readlines()
    for word in content:
        if word == "PIN: " + pin + "\n":
            index = content.index(word)
            text = tk.Text(window, height = 4, font = "Arial 15" ,width= 20)
            text.place(x=190, y=350)
            text.insert(INSERT, content[index+1])



window.mainloop()



