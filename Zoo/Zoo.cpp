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

    Lion lion;
    Tiger tiger;
    Cheetah cheetah;
    Elefant elefant;
    Pinguin pinguin;
    switch (animalChoice)
    {
        case 'a':
        cout << "\nWhat do you want to do ? Make it run (a) or Make it do a sound (b):  ";
        char input;
        cin >> input;
        switch (input)
        {
            case 'a': 
            lion.running(lion.name, lion.topSpeed);
            break;

            case 'b':
            lion.animalSound();
            break;
        }
        break;

        case 'b':
        cout << "\nWhat do you want to do ? Make it run (a) or Make it do a sound (b):  ";
        char input1;
        cin >> input1;
        switch (input1)
        {
            case 'a': 
            tiger.running(tiger.name, tiger.topSpeed);
            break;

            case 'b':
            tiger.animalSound();
            break;
        }
        break;

        case 'c':
        cout << "\nWhat do you want to do ? Make it run (a) or Make it do a sound (b):  ";
        char input2;
        cin >> input2;
        switch (input2)
        {
            case 'a': 
            cheetah.running(cheetah.name, cheetah.topSpeed);
            break;

            case 'b':
            cheetah.animalSound();
            break;
        }
        break;

        case 'd':
        cout << "\nWhat do you want to do ? Make it run (a) or Make it do a sound (b):  ";
        char input3;
        cin >> input3;
        switch (input3)
        {
            case 'a': 
            elefant.running(elefant.name, elefant.topSpeed);
            break;

            case 'b':
            elefant.animalSound();
            break;
        }
        break;

        case 'e':
        cout << "\nWhat do you want to do ? Make it run (a) or Make it do a sound (b):  ";
        char input4;
        cin >> input4;
        switch (input4)
        {
            case 'a': 
            pinguin.running(pinguin.name, pinguin.topSpeed);
            break;

            case 'b':
            pinguin.animalSound();
            break;
        }
        break;
    }

}



