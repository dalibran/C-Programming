/*
Dana Alibrandi
Project 1
March 17, 2018
*/

/* Include Files */
#include <stdio.h>

/* Function Prototypes */
int PrintInitials( void );
/* Prints initials, separated from main() for readability */

int main( void )
{
     printf("My name is Dana Christian Alibrandi\n");
     printf("Here are my initials in block letters!\n");
     PrintInitials();
     printf("The End!\n");
     return 0;
}

/****************PrintInitials()*****************/

int PrintInitials ( void )
{
    printf("\n");
    printf("DDDD     CCCC    AAAA\n");
    printf("D   D   C       A    A\n");
    printf("D   D   C       A    A\n");
    printf("D   D   C       AAAAAA\n");
    printf("D   D   C       A    A\n");
    printf("D   D   C       A    A\n");
    printf("DDDD     CCCC   A    A\n");
    printf("\n");
    return 0;
}
