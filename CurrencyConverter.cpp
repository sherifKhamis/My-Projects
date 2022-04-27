#include <iostream>
#include <string.h>
using namespace std;

void letterInput(char want1, char want2, char want3, char want4, char &input);         
int main ()
{
    cout << "\t\tCurrency Converter \n\nWhich currency do you want to exchange ?";
    cout << "\nEUR (a)\t\tUSD (b)\t\tGBP (c)\t\tCNY (d)\n";                                             
    char input, output;
    string icurrency, ocurrency;
    cin >> input;                                                                               
    letterInput ('a','b','c','d', input);
    switch (input)
    {
        case 'a':
        icurrency = "EUR";
        break;

        case 'b':
        icurrency = "USD";
        break;

        case 'c':
        icurrency = "GBP";
        break;

        case 'd':
        icurrency = "CNY";
        break;
    }
    cout << "\nHow much " << icurrency << " do you have ?\n";                                  
    float multiplyer, result, amount;
    cin >> amount;
    cout << "\nWhich currency do you want instead ?\n";
    cout << "EUR (a)\t\tUSD (b)\t\tGBP (c)\t\tCNY (d)\n";
    cin >> output;
    letterInput ('a','b','c','d', output);
    switch (output)
    {
        case 'a':
        ocurrency = "EUR";
        switch (input)
        {
            case 'a':
            multiplyer = 1;
            break;

            case 'b':
            multiplyer = 1.1;
            break;

            case 'c':
            multiplyer = 0.83;
            break;

            case 'd':
            multiplyer = 7;
            break;
        }
        break;

        case 'b':
        ocurrency = "USD";
        switch (input)
        {
            case 'a':
            multiplyer = 0.91;
            break;

            case 'b':
            multiplyer = 1;
            break;

            case 'c':
            multiplyer = 0.76;
            break;

            case 'd':
            multiplyer = 6.37;
            break;
        }
        
        break;

        case 'c':
        ocurrency = "GBP";
        switch (input)
        {
            case 'a':
            multiplyer = 1.2;
            break;

            case 'b':
            multiplyer = 1.32;
            break;

            case 'c':
            multiplyer = 1;
            break;

            case 'd':
            multiplyer = 8.39;
            break;
        }
        break;

        case 'd':
        ocurrency = "CNY";
        switch (input)
        {
            case 'a':
            multiplyer = 0.143;
            break;

            case 'b':
            multiplyer = 0.157;
            break;

            case 'c':
            multiplyer = 0.12;
            break;

            case 'd': 
            multiplyer = 1;
            break;

        }
        break;

    }
    result = amount * multiplyer;
    cout << "\nYour " << amount << " " << icurrency << " are " << result << " " << ocurrency; 

    return 0;
}
void letterInput(char want1, char want2, char want3, char want4, char &input)
{
    if (input == want1 || input == want2 || input == want3 || input == want4)
    {
        return;
    }
    else 
    {
        printf("\nWrong input, try again !");
        printf("\nEUR (a)\t\tUSD (b)\t\tGBP (c)\t\tCNY (d)\n");
        cin >> input;    
        letterInput (want1, want2, want3, want4, input);
    }
}
