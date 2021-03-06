#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void generateDatabase();
int checkBalance(int pin);
void atmMenu();

int main ()
{
    generateDatabase();
    atmMenu();
}

//Function to generate database 
void generateDatabase()
{
    //Create database file 
    ofstream database("database.txt");
    string database_Content = "\n\n\nPIN: 1234\nBalance = 500$\n\n\nPIN: 4321\nBalance = 1000$"
                              "\n\n\nPIN: 9212\nBalance = 800$\n\n\nPIN: 3032\nBalance = 549$\n\n\nPIN: 9311\nBalance = 1040$"
                              "\n\n\nPIN: 4320\nBalance = 2000$\n\n\nPIN: 6666\nBalance = 5403$\n\n\nPIN: 4032\nBalance = 50$"
                              "\n\n\nPIN: 9542\nBalance = 1000$";
    database << database_Content;
    database.close();
}

int checkBalance(int pin)
{
    ifstream database ("database.txt");
    int balance, pin2;
    string skip;
    while (database >> skip >> pin2 >> skip >> skip >> balance >> skip)
    {
        if (pin2 == pin)
        {
            return balance;
        }
    }
}

void atmMenu()
{
    cout << "Welcome to Deutsche Bank ATM\n\n";
    cout << "Whats your PIN ?\nPIN: ";
    int pin, balance;
    cin >> pin;
    cout << "What do you want to do ?\n";
    cout << "(a) Check balance\n(b) Deposit\n(c) Withdraw\n(d) Choice: ";
    char choice;
    cin >> choice;
    switch (choice)
    {
        case 'a':
        balance = checkBalance(pin);
        cout << "\nYour Balance is " << balance << "$\n\n";
        atmMenu();
        break;
    }
}