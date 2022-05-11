#include <iostream>
#ifndef Animal_h
#define Animal_h
using namespace std;

class Animal 
{
    public:
        string name = "Animal";
        string food = "Anything";
        int topSpeed = 0;
        void animalSound ();
        void running (string name, int topSpeed);
};

class Lion : public Animal
{
    public:
        string name = "Lion";
        string food = "Meat";
        int topSpeed = 81;
        
        void animalSound ();

};

class Tiger : public Animal
{
    public:
        string name = "Tiger";
        string food = "Meat";
        int topSpeed = 80;
        
        void animalSound ();

};

class Cheetah : public Animal
{
    public:
        string name = "Cheetah";
        string food = "Meat";
        int topSpeed = 93;
        
        void animalSound ();
};

class Elefant : public Animal
{
    public:
        string name = "Elefant";
        string food = "Vegetables";
        int topSpeed = 40;
        
        void animalSound ();

};

class Pinguin : public Animal
{
    public:
        string name = "Pinguin";
        string food = "Fish";
        int topSpeed = 6;
        
        void animalSound ();
};

#endif