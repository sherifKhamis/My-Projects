#include <iostream>
#include <cstdio>
#include "Costumer.h"
#include <string.h>
using namespace std;

void Costumer::costumerRegistration (string name, string surname, int age)
{
    FILE *fp;
    fp = fopen("zooBook.txt", "a");
    fprintf(fp, "\n\nName: %s\nSurname: %s\nAge: %d", name.c_str(), surname.c_str(), age);
    fclose(fp);
}

int Costumer::costumerCount (string name, string surname, int age)
{
    FILE *fp;
    fp = fopen ("zooBook.txt", "r");
    int count = 0, age2;
    string name2, surname2;
    while (fscanf(fp, "\n\nName: %s\nSurname: %s\nAge: %d", name2.c_str(), surname2.c_str(), &age2)== 3)
    {
        if (!(strcmp(name.c_str(), name2.c_str())) && !(strcmp(surname.c_str(), surname2.c_str())) && age == age2)
        {
            count++;
        }

    }    
    return count;
}

Costumer::Costumer (string x, string y, int z)
{
    name = x;
    surname = y;
    age = z;
}
