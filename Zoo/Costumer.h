#include <iostream>
#include <cstdio>
#ifndef Costumer_h
#define Costumer_h
using namespace std;

class Costumer 
{
    public:
    	string name; 
        string surname;
        int age;
        
        Costumer (string x, string y, int z);

        void costumerRegistration (string name, string surname, int age);

        int costumerCount (string name, string surname, int age);
};

#endif