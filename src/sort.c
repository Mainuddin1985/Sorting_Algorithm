/*
 ============================================================================
 Name        : sort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers pointed by the pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Print the array.
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}


void sort(int array[], int l_index, int r_index)
{
    // if array length is length <= 1 no need to swap
    if (l_index >= r_index)
    {
        return;
    }

    // Choose pivot to be the last element.
    int pivot = array[r_index];

    // Index of the split
    int count = l_index;

    // Traverse through array from l_index to r_index
    for (int i = l_index; i <= r_index; i++)
    {
        // If an element less than or equal to the pivot is found...
        if (array[i] <= pivot)
        {
            // Then swap array[count] and array[i] so that the smaller element array[i]
            // is to the left of all elements greater than pivot
            swap(&array[count], &array[i]);

            // keep track of what to swap
            count++;
        }
    }


    sort(array, l_index, count-2); // Recursively sort the left side of pivot
    sort(array, count, r_index);   // Recursively sort the right side of pivot
}


int main()
{
    int array[] = { 2, 2, 1, 0, 1, 0, 1, 1, 0, 2, 2, 1, 1, 1, 2, 0, 0, 1, 1, 0, 1, 0, 1, 2, 0, 0, 0,1, 1, 2};
    int n = sizeof(array) / sizeof(array[0]);
    sort(array, 0, n-1);
    printf("Sorted array: \n");
    printArray(array, n);
    return 0;
}
