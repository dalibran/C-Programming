/*  Dana Alibrandi
*   CS 50
*   Project 4
*   April 29, 2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define UPPER_LIMIT 6
#define LOWER_LIMIT 1
#define TRUE 1
#define FALSE 0

/* Function Prototypes */
int roll ();
void evaluateRoll ( int, int, int );
void driveOutcome ( int, int, int, int );

int main(void)
{
    srand(time(NULL));
    int firstRoll = TRUE, sum = 0, originalSum = 0;

    printf("\nDana Alibrandi - Project 4: Craps\n\n");
    evaluateRoll( sum = roll(), firstRoll , originalSum );
    printf("\nDana Alibrandi - End of Project 4\n\n");

    return 0;
}

/*********************Function Definitions***********************/

int roll()
/*
*   Generates random numbers between 1 - 6 for the dice. Prints
*   the results from a roll and returns the sum.
*/
{
    int x = rand() % (UPPER_LIMIT + 1 - LOWER_LIMIT) + LOWER_LIMIT;
    int y = rand() % (UPPER_LIMIT + 1 - LOWER_LIMIT) + LOWER_LIMIT;
    int sum = x + y;

    printf("Player rolled %d + %d = %d\n", x, y, sum);
    return sum;
}


void evaluateRoll( int sum, int firstRoll, int originalSum )
/*
*   Evalutes the result of a roll. On the first roll, if the sum is
*   not 7, 11, 2, 3, or 12, then the program will keep track of the original
*   point, roll again, and evalute its result using recursion.
*
*   The firstRoll boolean helps track the point on the first roll,
*   so that the winning criteria can be determined later in the game.
*/
{
    int sevenEleven = TRUE;
    if ( firstRoll ) originalSum = sum;

    switch ( sum ) {
      case 7:
      case 11:
        driveOutcome( sum, firstRoll, originalSum, sevenEleven );
        break;

      case 2:
      case 3:
      case 12:
        driveOutcome( sum, firstRoll, originalSum, !sevenEleven );
        break;

      default:
        if ( firstRoll ) {
          printf("\nPoint is %d, The game continues:\n\n", originalSum);
          firstRoll = FALSE;
          evaluateRoll( sum = roll(), firstRoll, originalSum );
        }
        else if ( originalSum == sum ) {
          printf("\nPlayer wins!\n\n");
        }
        else {
          evaluateRoll( sum = roll(), firstRoll, originalSum );
        }
        break;
    }
}


void driveOutcome( int sum, int firstRoll, int originalSum, int sevenEleven )
/*
* Abstracts outcome logic into its own function for readability.
*/
{
    if ( ( sum == 7 && !firstRoll ) || ( !sevenEleven && firstRoll ) ) {
      printf("\nPlayer Loses.\n\n");
    }
    else if ( firstRoll ) {
      printf("\nPlayer Wins!\n\n");
    }
    else {
      evaluateRoll( sum = roll(), firstRoll, originalSum );
    }
}

