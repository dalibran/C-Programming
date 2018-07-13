/*  Dana Alibrandi
*   CS 50
*   Project 5
*   May 7, 2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define UPPER_LIMIT 20
#define LOWER_LIMIT 14
#define DATA_UPPER_LIMIT 99
#define DATA_LOWER_LIMIT 10
#define FALSE 0
#define TRUE 1

/* Function Prototypes */
void initializeProject( int [], int, int );
void printArray( int [], int, int, int );
void sequentialSearch( int [], int, int);
void swap( int *, int * );
int partition( int [], int, int );
void quickSort( int [], int, int );
void binSearch( int [], int, int, int, int * );

int main( void )
{
    srand(time(NULL));
    int sampleSize = rand() % (UPPER_LIMIT + 1 - LOWER_LIMIT) + LOWER_LIMIT;
    int searchElement = rand() % (DATA_UPPER_LIMIT + 1 - DATA_LOWER_LIMIT) + DATA_LOWER_LIMIT;
    int array[sampleSize], pivot = 99, counter = 0;

    initializeProject( array, sampleSize, pivot );
    sequentialSearch( array, sampleSize, searchElement );

    printf("\nSorting...\n");
    quickSort( array, 0, sampleSize );
    printf("Sorted:\n");
    printArray( array, 0, sampleSize, pivot );

    binSearch(array, 0, sampleSize, searchElement, &counter);
    printf("Number of searches: %d\n\n", counter);

    printf("\nDana Alibrandi - End of Project 5\n\n");
    return 0;
}

/*********************Function Definitions**********************/

void initializeProject( int array [], int sampleSize, int pivot)
/*
*   Generates random elements for the array based on sampleSize.
*   Prints general project info so printArray can be reused elsewhere.
*/
{
    for ( int i = 0; i < sampleSize; i++ ) {
      array[i] = rand() % (DATA_UPPER_LIMIT + 1 - DATA_LOWER_LIMIT) + DATA_LOWER_LIMIT;
    }

    printf("\nDana Alibrandi - Project 5\n");
    printf("\nSample size = %d\n", sampleSize);
    printf("\nArray elements:\n");
    printArray(array, 0, sampleSize, pivot);
}


void printArray( int array [], int first, int last, int pivot )
{
/*
*   Uses pivot variable for formatting when printing during
*   the quickSort.
*
*/
    for ( int i = first; i < last; i++ ) {
      if ( i == pivot )  {
        printf("<%d> ", array[i]);
      }
      else {
        printf("%d ", array[i]);
      }
    }
    printf("\n\n");
}


void sequentialSearch ( int array [],  int sampleSize, int searchElement )
{
    int found = FALSE;
    printf("Search element: %d\n", searchElement);

    for ( int i = 0; i < sampleSize; i++ ) {
      if ( array[i] == searchElement ) {
        found = TRUE;
        printf("\nItem found: %d\n", searchElement);
        printf("Number of searches: %d\n", i + 1);
        break;
      }
    }

    if ( found == FALSE ) {
      printf("\nItem not found: %d\n", searchElement);
      printf("Number of searches: %d\n", sampleSize);
    }
}


void swap( int *a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int array [], int first, int last )
{
    int pivot = array[last - 1];
    int leftIndex = first;

    for ( int i = first; i <= last - 1; i++ ) {
      if ( array[i] < pivot ) {
        swap(&array[i], &array[leftIndex]);
        leftIndex++;
      }
    }

    swap(&array[leftIndex], &array[last - 1]);
    return leftIndex;
}


void quickSort( int array [], int first, int last )
{
    int pivot;

    if ( first < last ) {
      pivot = partition(array, first, last);
      if ( array[last - 1] != array[first] ) printArray( array, first, last, pivot );
      quickSort( array, first, pivot );
      quickSort( array, pivot + 1, last );
    }
}


void binSearch( int array [], int first, int last, int searchElement, int *counter )
{
/*
*   Binary search using recursion to locate item. *counter is used
*   to keep track of the number of searches.
*
*/
    int midIndex;

    if ( first <= last ) {
      midIndex = (first + last) / 2;
      *counter += 1;

      if ( searchElement < array[midIndex] ) {
        binSearch(array, first, midIndex - 1, searchElement, counter);
      }
      else if ( searchElement > array[midIndex] ) {
        binSearch(array, midIndex + 1, last, searchElement, counter);
      }
      else
        printf("Item Found: %d, Element Position: %d\n", searchElement, midIndex);
      }

    else {
      printf("Item not found: %d \n", searchElement);
    }
}
