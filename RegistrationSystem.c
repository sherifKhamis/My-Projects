#include <stdio.h>

void newUser ();


int main ()
{
    char *name, *password;
    newUser (name, password);
    printf("\nUsername = %s\nPassword = %s", name, password);

    return 0;
}

//function to register a new user 
void newUser (char name[100], char password[100])
{
    //name input
    printf("\nWhats your username ?: ");
    scanf("%s", &name);

    //For the second scanf() to work this code 
    //needs to remove any newlines in the buffer
    int c; 
    while ((c = getchar()) != EOF && c != '\n') ;

    //password input
    printf("\nWhats your Password ?: ");
    scanf("%s", &password);

    return;
}