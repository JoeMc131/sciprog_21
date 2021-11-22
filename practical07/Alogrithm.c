// import packages
#include "stdio.h"

int recursive_GCD(int a, int b){
    /*
     * Use a recursive method to compute the greatest common denominator
     *
     * Method obtained from assignment PDF
     *
     * */
    if(b == 0){
        return a;
    }else{
        return recursive_GCD(b, a%b);
    }
}
int iterative_GCD(int a, int b){
    /*
     * Iteravtive method of computing the greatest common denominator.
     *
     * Method obtained from assignment PDF
     * */
    int temp;

    while (b!=0){
        temp = b;

        b = a%b;

        a = temp;
    }

    return a;
}
int main(void){
    // ask the user to input two integers to compute the greatest common denominator of
    printf("\nPlease enter in two integers\n");

    // initialise integers
    int a, b;

    // read integrers from user input
    scanf("%d %d", &a, &b);

    // compute two answers from the two separate methods
    int iterative_ans = iterative_GCD(a, b);
    int recursive_ans = recursive_GCD(a, b);

    // print results
    printf("\nLCM:\nIterative answer = %d\n"
           "Recursive answer = %d\n", iterative_ans, recursive_ans);
}