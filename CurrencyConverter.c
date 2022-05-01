/*Very simple Currency Converter in C with 
 4 currencies: EURO, US Dollar, British Pound and Chinese Yen*/ 

#include <stdio.h>
#include <string.h> //for strypy()

int main ()
{
    //Header and starting currency menu
    printf("          Currency Converter          \n\n");
    printf("Which currency do you want to exchange ?\n");
    printf("     (a) EUR     (b) USD     (c) GBP     (d) CNY \n");
    char input, input2, icurrency [3], ocurrency [3], output;
    scanf(" %c", &input);

    //While loop to limit user input to "abcd" only for starting currency input
    while (input != 'a' && input != 'b' && input != 'c' && input != 'd')
    {
        printf("\n\nWrong input, try again !\n\n");
        printf("     (a) EUR     (b) USD     (c) GBP     (d) CNY \n");
        scanf(" %c", &input);
    }
    input2 = input; //Since "input" gets unassigned after being used in the following switch statement
                    //the value of "input" has to be saved in "input2" for later use

    /* Switch statement to assign a real currency name to the single letter user input*/
    switch (input)
    {
        case 'a':
        strcpy(icurrency, "EUR");
        break;

        case 'b':
        strcpy(icurrency, "USD");
        break;

        case 'c':
        strcpy(icurrency, "GBP");
        break;

        case 'd':
        strcpy(icurrency, "CNY");
        break;
    }
    
    //Menu for starting currency amount and target currency 
    printf("\n\nHow much %s do you have ? ", icurrency);
    float amount, multiplyer;
    scanf("%f", &amount);
    printf("\n\nWhich currency do you want instead ?\n");
    printf("     (a) EUR     (b) USD     (c) GBP     (d) CNY \n");
    scanf(" %c", &output);

    /* Switch statement to assign a real currency name to the single letter user input and set
       "multiplyer" to the needed exchange rate*/
    switch (output)
    {
        case 'a':
        strcpy(ocurrency, "EUR");
        switch (input2)
        {
            case 'a':
            multiplyer = 1.0;
            break;
            case 'b':
            multiplyer = 0.91;
            break;
            case 'c':
            multiplyer = 1.19;
            break;
            case 'd':
            multiplyer = 0.14;
            break;  
        }
        break;

        case 'b':
        strcpy(ocurrency, "USD");
        switch (input2)
        {
            case 'a':
            multiplyer = 1.1;
            break;
            case 'b':
            multiplyer = 1;
            break;
            case 'c':
            multiplyer = 1.32;
            break;
            case 'd':
            multiplyer = 0.16;
            break;
        }
        break;

        case 'c':
        strcpy(ocurrency, "GBP");
        switch (input2)
        {
            case 'a':
            multiplyer = 0.84;
            break;
            case 'b':
            multiplyer = 0.76;
            break;
            case 'c':
            multiplyer = 1;
            break;
            case 'd':
            multiplyer = 0.12;
            break; 
        }
        break;

        case 'd':
        strcpy(ocurrency, "CNY");
        switch (input2)
        {
            case 'a':
            multiplyer = 7.01;
            break;
            case 'b':
            multiplyer = 6.35;
            break;
            case 'c':
            multiplyer = 8.38;
            break;
            case 'd':
            multiplyer = 1;
            break;
        }
        break;
    }
    float result = amount * multiplyer; //result = starting currency amount * exchange rate

    //Output result 
    printf("\n\nYour %.2f %s are %.2f %s ", amount, icurrency, result, ocurrency);

    return 0;
}