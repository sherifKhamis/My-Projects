/*Simple Currency Converter in C++, with 4 
 currencies: EURO, US Dollar, British Pound and Chinese Yen. 
 And a function to limit user input*/


#include <iostream>
using namespace std;

void letterInput(char want1, char want2, char want3, char want4, char &input);

int main ()
{
    
    //Header and menu asking for starting currency
    cout << "\t\tCurrency Converter \n\nWhich currency do you want to exchange ?";
    cout << "\nEUR (a)\t\tUSD (b)\t\tGBP (c)\t\tCNY (d)\n";                                             
    char input, output;
    string icurrency, ocurrency;
    cin >> input;                                                                               
    letterInput ('a','b','c','d', input); //Function to limt userinput to "abcd" ONLY
    
    //Switch statement to turn single letter user input into actual currency names
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

    //Menu for taking the currency amount and the target currency
    cout << "\nHow much " << icurrency << " do you have ?\n";                                  
    float multiplyer, result, amount;
    cin >> amount;
    cout << "\nWhich currency do you want instead ?\n";
    cout << "EUR (a)\t\tUSD (b)\t\tGBP (c)\t\tCNY (d)\n";
    cin >> output;
    letterInput ('a','b','c','d', output); //Function for limiting user input to "abcd" only

    //Switch statement for turning single letter input into actual currency names and setting 
    //the multiplyer to the needed exchange rate 
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
    result = amount * multiplyer; //Result = amount * exchange rate
    cout << "\nYour " << amount << " " << icurrency << " are " << result << " " << ocurrency; 

    return 0;
}

//Function that limits user input to 4 single letters 
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
