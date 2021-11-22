//import packages needed for programme
#include "stdio.h"
#include "stdlib.h"

// allocates memory for the array
int* allocatearray(int n){
    //initialise array pointer
    int* array;

    //allocate array memory
    array = (int*) malloc(n*sizeof (int));

    // print array size
    printf("Array is of size %d\n\n", n);

    return array;
}

void fillarray(int *array, int n){
    // fill array with ones
    for(int i= 0; i<n; i++){
        array[i] = 1;
    }
}

void printarray(int *array, int n){
    // print each element in the arary
    for(int i = 0; i<n; i++){
        printf("%d ", array[i]);
    }
}

void freearray(int *array){
    // free array memory
    free(array);
}

int main(void){
    // n is the size of the array
    int n;

    // tell user to enter in n
    printf("Please enter n:\n");

    // read user input
    scanf("%d", &n);

    // exectute each function
    int *array = allocatearray(n);

    fillarray(array, n);

    printarray(array, n);

    freearray(array);

    array = NULL;
}
