/*
  Tayly Heimily
  March 21, 2018
  Code to swap address of two variables
*/

#include <stdlib.h>
#include <stdio.h>

void swap(int* first, int* second);

int main(int argc, char* argv[]) {
    int first = 8;
    int second = 26;

    // print to see what first and second are before swap
    printf("first: %d\n", first);
    printf("second: %d\n", second);

    // pass the address of first and second into swap function
    swap(&first,&second);
  
    return EXIT_SUCCESS;
}

// function to swap two variables
void swap(int* first, int* second){
    // temporary value to hold first before swap
    int temp = *first;

    // swap the values
    *first = *second;
    *second = temp;

    // print value stored at each address
    printf("first: %d\n", *first);
    printf("second: %d\n", *second);
}

