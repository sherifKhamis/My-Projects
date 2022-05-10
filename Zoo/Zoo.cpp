#include <iostream>
#include <cstdio>
#include "Costumer.h"
#include "Animal.h"
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
    cout << "\nWelcome " << name << " " << surname << " you've been here " << newCostumer.costumerCount(name, surname, age) << " times before! ";
    newCostumer.costumerRegistration (name, surname,age);
    cout << "\nWhich animal do you want to visit ?\nLion (a)\nTiger (b)\nCheetah (c)\nElefant (d)\nPinguin (e)\nChoice: ";
    char animalChoice;
    cin >> animalChoice;
    while (animalChoice != 'a' && animalChoice != 'b' && animalChoice != 'c' && animalChoice != 'd' && animalChoice != 'e')
    {
        printf("\n\nWrong input, try again!\n\n");
        printf("Lion (a)\nTiger (b)\nCheetah (c)\nElefant (d)\nPinguin (e)\nChoice: ");
        cin >> animalChoice;
    }
    


}



