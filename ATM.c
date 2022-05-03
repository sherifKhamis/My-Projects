/* ATM Program in C with a DEPOSIT, WITHDRAW and a CHECK BALANCE function 
   that saves everything into a text file.*/


#include <stdio.h>
#include <stdbool.h> 

void generateDatabase ();
void deposit (int pin, int amount);
bool correctPin (int pin);
void atmMenu ();
void withdraw (int pin, int amount);
void seek_to_next_line();
void checkBalance (int pin);

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
    fprintf(fp, "\n\n\nPIN: 1234\nBalance = 500$");
    fprintf(fp, "\n\n\nPIN: 4321\nBalance = 1000$");
    fprintf(fp, "\n\n\nPIN: 9212\nBalance = 800$");
    fprintf(fp, "\n\n\nPIN: 3032\nBalance = 549$");
    fprintf(fp, "\n\n\nPIN: 9311\nBalance = 1040$");
    fprintf(fp, "\n\n\nPIN: 4320\nBalance = 2000$");
    fprintf(fp, "\n\n\nPIN: 6666\nBalance = 5403$");
    fprintf(fp, "\n\n\nPIN: 4032\nBalance = 50$");
    fprintf(fp, "\n\n\nPIN: 9542\nBalance = 1000$");

    fclose(fp);

}

void atmMenu ()
{
    printf("\n\n*****ATM of Deutsche Bank*****\n\n");
    printf("Please enter your PIN Number: ");
    
    int pin, amount;
    scanf("%d", &pin);
    while (!(correctPin(pin)))
    {
        printf("\nWrong PIN Number, try again!");
        printf("\nPlease enter your PIN Number: ");
        scanf("%d", &pin);
    }

    printf("\nWhat do you want to do ?");
    printf("\nDEPOSIT (a)\nWITHDRAW (b)\nCHECK BALANCE (c)\nChoice: ");
    char choice;
    scanf(" %c", &choice);

    seek_to_next_line(); //to clear out buffer for next scanf

    switch (choice)
    {
        case 'a':
        printf("\nWhich amount ?: ");
        scanf("%d",&amount);
        deposit (pin, amount);
        atmMenu();
        break;

        case 'b':
        printf("\nWhich amount ?: ");
        scanf("%d",&amount);
        withdraw (pin, amount);
        atmMenu();
        break;

        case 'c':
        checkBalance (pin);
        atmMenu();
        break;
    }

}


//function to determine if input pin is available in database
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
        
    FILE *database = fopen ("database.txt", "r+");
    while (fscanf(database, "\n\n\nPIN: %d\nBalance = %d$", &pin2,&startingAmount)== 2)
    {
        if (pin2 == pin)
        {
            amount += startingAmount;
            fseek(database, -30, SEEK_CUR);
            fprintf(database,"\n\nPIN: %d\nBalance = %d$", pin2, amount);
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
        
    FILE *database = fopen ("database.txt", "r+");
    while (fscanf(database, "\n\n\nPIN: %d\nBalance = %d$", &pin2,&startingAmount)== 2)
    {
        if (pin2 == pin)
        {
            startingAmount -= amount;
            fseek(database, -30, SEEK_CUR);
            fprintf(database,"\n\nPIN: %d\nBalance = %d$", pin2, startingAmount);
            fclose(database);
            return;
        }
    }
    
}


void checkBalance (int pin)
{
    int pin2, startingAmount;
        
    FILE *database = fopen ("database.txt", "r+");
    while (fscanf(database, "\n\n\nPIN: %d\nBalance = %d$", &pin2,&startingAmount)== 2)
    {
        if (pin2 == pin)
        {
            printf("\nYour balance is %d$", startingAmount);
            fclose(database);
            return;
        }
    }
    
}