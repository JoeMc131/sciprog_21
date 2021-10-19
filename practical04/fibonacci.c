//Joe McCaffrey
#include "stdio.h"

void fib_next(int *n_minus_1, int *n_minus_2){
    //create variable to store answer
    int temp;

    //calculate the next term in the series
    temp = *n_minus_1 + *n_minus_2;

    // change n_minus_2 to n_minus_1 and change n_minus_1 to the answer
    *n_minus_2 = *n_minus_1;
    *n_minus_1 = temp;
}

int main(void){

    // number of series terms to be set by user
    int n;

    printf("Please enter n: \n");

    scanf("%d", &n);

    //create variables to store the last two terms in the series
    int previous, next_int;

    previous = 0;
    next_int = 1;

    //print out the series
    printf("\nThe first %d fibonacci numbers are: \n", n);

    for(int i=1; i<=n; i++){
        printf("\n%d", next_int);

        fib_next(&next_int, &previous);
    }

    return 0;
}