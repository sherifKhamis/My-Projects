#include <stdio.h>
#include <string.h>

int main ()
{
    printf("          Currency Converter          \n\n");
    printf("Which currency do you want to exchange ?\n");
    printf("     (a) EUR     (b) USD     (c) GBP     (d) CNY \n");
    char input, input2;
    char icurrency [3];
    char icurrency2 [3];
    char ocurrency [3];
    char ocurrency2 [3];
    scanf(" %c", &input);
    while (input != 'a' && input != 'b' && input != 'c' && input != 'd')
    {
        printf("\n\nWrong input, try again !\n\n");
        printf("     (a) EUR     (b) USD     (c) GBP     (d) CNY \n");
        scanf(" %c", &input);
    }
    input2 = input;
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
    printf("\n\nHow much %s do you have ? ", icurrency);
    float amount;
    scanf("%f", &amount);
    printf("\n\nWhich currency do you want instead ?\n");
    printf("     (a) EUR     (b) USD     (c) GBP     (d) CNY \n");
    char output;
    scanf(" %c", &output);
    float multiplyer;
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
    float result = amount * multiplyer;
    printf("\n\nYour %.2f %s are %.2f %s ", amount, icurrency, result, ocurrency);

    return 0;
}