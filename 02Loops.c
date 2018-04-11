/*  Dana Alibrandi
*   CS 50
*   Project 2
*   March 28, 2018
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define UPPER_LIMIT 41
#define LOWER_LIMIT 21

/* Function Prototypes */
int randomNum( void );            /* Returns a random number */
int firstTriangle( int );         /* Generates first triangle */
int separateTriangles( int );     /* Separates triangles with equal signs */
int secondTriangle( int );        /* Generates second triangle */

int main(void)
{
    int num = randomNum();

    printf("\nStudent Name: Dana Alibrandi\n");
    printf("\nNumber of lines: %d\n", num);
    putchar('\n');

    firstTriangle(num);
    separateTriangles(num);
    secondTriangle(num);

    putchar('\n');
    return 0;
}

/*********************Function Definitions**********************/

int randomNum( void )
{
    int sample;
    srand(time(NULL));
    sample = rand() % (UPPER_LIMIT - LOWER_LIMIT + 1) + LOWER_LIMIT;
    if (sample % 2 == 0) sample++;
    return sample;
}

int firstTriangle( int num )
{
    int totalSpaces = (num - 1) / 2, totalRows = (num - 1) / 2;

    for ( int a = 0; a < totalRows; a++ ) {            /* creates rows */
      for ( int b = totalSpaces; b > 0; b-- ) {        /* adds spaces */
        putchar(' ');
      }
      for ( int c = 0; c <= a * 2; c++ ) {             /* adds initials */
        putchar('D');
      }
      putchar('\n');
      totalSpaces--;
    }

    return 0;
}

int separateTriangles ( int num )
{
    for ( int a = 0; a < num; a++ ) {
      putchar('=');
    }

    putchar('\n');
    return 0;
}

int secondTriangle( int num )
{
    int totalSpaces = (num - 1) / 2, totalRows = (num - 1) / 2;

    for( int a = 0; a < totalRows; a++ ) {                  /* creates rows */
      for ( int b = totalRows; b >= totalSpaces; b-- ) {    /* adds spaces */
        putchar(' ');
      }
      for ( int c = num - 3; c >= a * 2; c-- ) {            /* adds initials */
        putchar('A');
      }
      putchar('\n');
      totalSpaces--;
    }

    return 0;
}


