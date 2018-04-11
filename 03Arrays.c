/*  Dana Alibrandi
*   CS 50
*   Project 3
*   April 7, 2018
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 20
#define UPPER_LIMIT 20
#define LOWER_LIMIT 12
#define DATA_UPPER_LIMIT 90
#define DATA_LOWER_LIMIT 10
#define TRUE 1
#define FALSE 0

/* Function Prototypes */
void Randomize( int [], int );
void PrintArray( int [], int );
void FindMaxMin( int [], int );
void FindAverage( int [], int );
void SortArrayBubble ( int [], int );
void FindMedian ( int [], int );

int main(void)
{
    srand(time(NULL));
    int arraySize = rand() % (UPPER_LIMIT + 1 - LOWER_LIMIT) + LOWER_LIMIT;
    int array[arraySize];

    Randomize(array, arraySize);
    PrintArray(array, arraySize);
    FindMaxMin(array, arraySize);
    FindAverage(array, arraySize);
    SortArrayBubble(array, arraySize);
    FindMedian(array, arraySize);

    return 0;
}

/*********************Function Definitions**********************/

void Randomize( int array [], int arraySize)
/*
*   Generates random elements for the array based on arraySize.
*   Prints general project info so PrintArray can be reused elsewhere.
*/
{
    for (int i = 0; i < arraySize; i++) {
      array[i] = rand() % (DATA_UPPER_LIMIT + 1 - DATA_LOWER_LIMIT) + DATA_LOWER_LIMIT;
    }

    printf("\nDana Alibrandi - Project 3\n");
    printf("\nArray Size = %d\n", arraySize);
    printf("\nArray elements:\n");
}

void PrintArray( int array [], int arraySize )
{
    for (int i = 0; i < arraySize; i++) {
      printf("%d ", array[i]);
    }

    printf("\n");
}

void FindMaxMin ( int array [],  int arraySize )
{
    int max = 0, min = array[0];

    for (int i = 0; i < arraySize; i++) {
      if (array[i] > max) max = array[i];
      if (array[i] < min) min = array[i];
    }

    printf("\nMaximum = %d, Minimum = %d\n", max, min);
}

void FindAverage( int array [], int arraySize )
{
    int sum = 0;

    for (int i = 0; i < arraySize; i++) {
      sum += array[i];
    }

    printf("\nAverage = %d\n", sum / arraySize);
    printf("\n");
}

void SortArrayBubble( int array[], int arraySize )
/*
*   Iterates through each item in the array comparing it to the
*   adjacent item. If array[i] is larger than array[i + 1], the two
*   values are swapped. The 'sorted' variable acts as a boolean to test whether
*   a swap has occured.
*/
{
    int sorted = FALSE;

    while (sorted == FALSE) {
      sorted = TRUE;

      for (int i = 0; i < arraySize - 1; i++) {
        if (array[i] > array[i + 1]) {
          int temp;
          temp = array[i];
          *(array + i) = array[i + 1];
          *(array + i + 1) = temp;
          sorted = FALSE;
        }
      }

      PrintArray(array, arraySize);
      printf("\n");
    }
}

void FindMedian( int array[], int arraySize )
{
    int median;

    if (arraySize % 2 != 0) {
      median = array[arraySize / 2];
    }
    else {
      median = (array[arraySize / 2] + array[(arraySize / 2) - 1]) / 2;
    }

    printf("Median = %d\n", median);
}
