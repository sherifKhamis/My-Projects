#include <iostream>
#include "Animal.h"

using namespace std;


void Animal::animalSound ()
{
    cout << "Generic animal sound";      
}
void Animal::running (string name, int topSpeed)
{
    cout << name << " is running at " << topSpeed << " km/h";
}

        
void Lion::animalSound ()
{
    cout << "Frightening Lion Sounds";
}


void Tiger::animalSound ()
{
    cout << "Frightening Tiger Sounds";
}


    
void Cheetah::animalSound ()
{
    cout << "Frightening Cheetah Sounds";
}



        
void Elefant::animalSound ()
{
    cout << "Peaceful elefant Sounds";
}



        
void Pinguin::animalSound ()
{
    cout << "Peaceful pinguin sounds";
}




        
    
