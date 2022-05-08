#include <iostream>
#include <cstdio>
#include "Costumer.h"
using namespace std;


void menu ();

int main ()
{
    menu();
}

void menu ()
{
    cout << "*****Welcome to your virtual Zoo!*****\n";
    cout << "Please enter your full name: ";
    int age;
    string name, surname;
    cin >> name >> surname;
    cout << "Please enter your age: ";
    cin >> age;
    Costumer newCostumer (name, surname, age);
    newCostumer.costumerRegistration (name, surname,age);
    cout << "\nWelcome " << name << " " << surname << " you've been here " << newCostumer.costumerCount(name, surname, age) << " times before! ";
}

