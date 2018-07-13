/*  Dana Alibrandi
*   CS 50
*   Project 6
*   May 16, 2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 12
#define COLUMNS 9

/* Global Variables */
int array[ROWS][COLUMNS];

/* Function Prototypes */
void fillArray( int, int, int[][COLUMNS] );
void addParityBit( int, int, int[][COLUMNS] );
void printArray( int, int, int[][COLUMNS] );

int main( void )
{
    srand(time(NULL));
    printf("\nDana Alibrandi - Project 6: Adding Parity Bit\n\n");

    fillArray(ROWS, COLUMNS, array);
    addParityBit(ROWS, COLUMNS, array);
    printArray(ROWS, COLUMNS, array);

    printf("\nDana Alibrandi - Project 6: End of Program\n\n");
    return 0;
}

/************* Function Definitions ********************/

void fillArray( int rows, int columns, int array[][COLUMNS] )
{
    for ( int i = 0; i < rows; i++ ) {
      for ( int j = 0; j < columns - 1; j++) {
        array[i][j] = rand() % 2;
      }
    }
}

void addParityBit( int rows, int columns, int array[][COLUMNS] )
/*
*   Iterates through the array, sums up each row, and
*   assigns parityBit. Resets sum after assigning parityBit.
*/
{
    int sum = 0, parityBit = (columns - 1);

    for ( int i = 0; i < rows; i++ ) {
      for ( int j = 0; j < columns; j++) {
        if ( j == parityBit ) {
          array[i][parityBit] = sum % 2;
          sum = 0;
        }
        else {
          sum += array[i][j];
        }
      }
    }
}

void printArray( int rows, int columns, int array[][COLUMNS] )
{
    int i = 0, j = 0, parityBit = (columns - 1);

    while ( i < rows ) {
      if ( j == parityBit ) {
        printf(" %d\n", array[i][j]);
        i++, j = 0;
      }
      else {
        printf( "%d ", array[i][j]);
        j++;
      }
    }
}
