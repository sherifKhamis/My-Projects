/* ATM Program in C with a DEPOSIT, WITHDRAW and a CHECK BALANCE function 
   that saves everything into a text file.*/


#include <stdio.h>
#include <stdbool.h> 
#include <string.h> //strlen()
#include <stdlib.h> //atoi()

void generateDatabase ();
void deposit (int pin, int amount);
bool correctPin (int pin);
void atmMenu ();
void withdraw (int pin, int amount);
void seek_to_next_line();
int checkBalance (int pin);
bool limitNumber (char *input);

int main ()
{
    generateDatabase();
    atmMenu ();

    return 0;
}

//function to generate a pre defined database into a text file 
void generateDatabase ()
{
    //create file 
    FILE *fp = fopen ("database.txt", "w");
    
    //print the database into the text file
    fprintf(fp, "\n\n\nPIN: 1234\nBalance = 500$   ");
    fprintf(fp, "\n\n\nPIN: 4321\nBalance = 1000$   ");
    fprintf(fp, "\n\n\nPIN: 9212\nBalance = 800$   ");
    fprintf(fp, "\n\n\nPIN: 3032\nBalance = 549$   ");
    fprintf(fp, "\n\n\nPIN: 9311\nBalance = 1040$   ");
    fprintf(fp, "\n\n\nPIN: 4320\nBalance = 2000$   ");
    fprintf(fp, "\n\n\nPIN: 6666\nBalance = 5403$   ");
    fprintf(fp, "\n\n\nPIN: 4032\nBalance = 50$   ");
    fprintf(fp, "\n\n\nPIN: 9542\nBalance = 1000$   ");

    //close file
    fclose(fp);

}

void atmMenu ()
{
    //PIN request menu
    printf("\n\n*****ATM of Deutsche Bank*****\n\n");
    printf("Please enter your PIN Number: ");
    
    int pin, amount, balance;
    char pin2[100], amount2[100];
    scanf("%s", &pin2);

    
    //Function to make sure theres no letter input
    while (!limitNumber(pin2))
    {
        printf("\nWrong input, no letters, try again!");
        printf("\nPlease enter your PIN Number:");
        scanf("%s", &pin2);
    }

    //If only number input, save in PIN
    pin = atoi(pin2);

    //while loop to check if PIN number exists in database
    while (!(correctPin(pin)))
    {
        printf("\nWrong PIN Number, try again!");
        printf("\nPlease enter your PIN Number: ");
        scanf("%s", &pin2);
        while (!limitNumber(pin2))
        {
            printf("\nWrong input, no letters, try again!");
            printf("\nPlease enter your PIN Number:");
            scanf("%s", &pin2);
        }
        pin = atoi(pin2);
    }

    //User action menu 
    printf("\nWhat do you want to do ?");
    printf("\nDEPOSIT (a)\nWITHDRAW (b)\nCHECK BALANCE (c)\nChoice: ");
    char choice;
    scanf(" %c", &choice);

    //While loop to limit user input to "abc" only for choice
    while (choice != 'a' && choice != 'b' && choice != 'c')
    {
        printf("\n\nWrong input, try again !\n\n");
        printf("\nWhat do you want to do ?");
        printf("\nDEPOSIT (a)\nWITHDRAW (b)\nCHECK BALANCE (c)\nChoice: ");
        scanf(" %c", &choice);
    }

    seek_to_next_line(); //to clear out buffer for next scanf

    switch (choice)
    {
        case 'a':
        printf("\nWhich amount ?: ");
        scanf("%s",&amount2);

        //Limit user input to numbers only 
        while (!limitNumber(amount2))
        {
            printf("\nWrong input, no letters, try again!");
            printf("\nWhich amount do you want to deposit ?:");
            scanf("%s", &amount2);
        }
        amount = atoi(amount2);
        deposit (pin, amount);
        printf("\n%d$ have been deposited to your account!", amount);
        atmMenu();
        break;

        case 'b':
        printf("\nWhich amount ?: ");
        scanf("%s",&amount2);

        //limit user input to numbers only
        while (!limitNumber(amount2))
        {
            printf("\nWrong input, no letters, try again!");
            printf("\nWhich amount do you want to withdraw ?:");
            scanf("%s", &amount2);
        }
        amount = atoi(amount2);

        //Checking if theres enough balance for withdrawal
        balance = checkBalance(pin);
        while (balance < amount)
        {
            printf("\nInsufficient funds, try withdrawing less");
            printf("\nWhich amount ?: ");
            scanf("%s",&amount2);
            while (!limitNumber(amount2))
            {
                printf("\nWrong input, no letters, try again!");
                printf("\nWhich amount do you want to withdraw ?:");
                scanf("%s", &amount2);
            }
            amount = atoi(amount2);
        }

        //if yes withdraw 
        withdraw (pin, amount);
        printf("\n%d$ have been withdrawed from your account!", amount);
        atmMenu();
        break;

        case 'c':
        checkBalance (pin);
        atmMenu();
        break;
    }

}


//function to determine if input PIN is available in database
bool correctPin (int pin)
{
    int balance;
    int pin2;
    FILE *database = fopen ("database.txt", "r");

    //Iterate through all PINs in database, if input PIN matches one, return true
    while (fscanf(database, "\n\n\nPIN: %d\nBalance = %*d$", &pin2)== 1)
    {    
        if (pin2 == pin)
        {
            fclose(database);
            return true;
        }
    }
    fclose(database);

    return false;
}

//function to deposit cash into the right account from the database
void deposit (int pin, int amount)
{
    int pin2, startingAmount;
        
    FILE *database = fopen ("database.txt", "r+"); //open file in edit mode

    //Iterate through database looking for PIN 
    while (fscanf(database, "\n\n\nPIN: %d\nBalance = %d$   ", &pin2,&startingAmount)== 2)
    {
        //if PIN was found edit balance by depositing amount
        if (pin2 == pin)
        {
            amount += startingAmount; //Edit amount
            fseek(database, -39, SEEK_CUR); //go back in file to print new balance at the same position 
            fprintf(database,"\n\nPIN: %d\nBalance = %d$   ", pin2, amount); 
            fclose(database);
            return;
        }
    }
    
}

void seek_to_next_line()
{
    int c;
    while( (c = fgetc( stdin )) != EOF && c != '\n' );
}


//function to withdraw cash from the right account from the database 
void withdraw (int pin, int amount)
{
    int pin2, startingAmount;
        
    FILE *database = fopen ("database.txt", "r+"); //open file in edit mode 

    //iterate through all PINs till the right one is found 
    while (fscanf(database, "\n\n\nPIN: %d\nBalance = %d$   ", &pin2,&startingAmount)== 2)
    {
        //if PIN was found stop
        if (pin2 == pin)
        {
            startingAmount -= amount; //Edit amount
            fseek(database, -39, SEEK_CUR); //go back to beginning of the balance entry
            fprintf(database,"\n\nPIN: %d\nBalance = %d$   ", pin2, startingAmount); //edit file with new amount
            fclose(database);
            return;
        }
    }
    
}


int checkBalance (int pin)
{
    int pin2, startingAmount;
        
    FILE *database = fopen ("database.txt", "r+"); //open file in edit mode 

    //Iterate through all account looking for the right PIN
    while (fscanf(database, "\n\n\nPIN: %d\nBalance = %d$   ", &pin2,&startingAmount)== 2)
    {
        //If found print the balance to console 
        if (pin2 == pin)
        {
            printf("\nYour balance is %d$", startingAmount);
            fclose(database);
            return startingAmount;
        }
    }
    
}

//Function to make sure theres no letter input
bool limitNumber (char *input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] < 48 || input[i] > 57)
            return false;
    }
    return true;
}