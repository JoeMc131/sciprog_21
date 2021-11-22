#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double factorial(double n){
    /*
     * Computes the factorial of a natural number by using a recursive method*/
    if (n<=1){
        return 1;
    }else{
        return  n*factorial( n-1);
    }
}

double estimate(double x, double n){
    //provide the nth term in the estimate for e
    double ans = 0;

    ans+= pow(x, n)/ factorial(n);

    return ans;
}

int main(void){
    // initialise the size of array and the order of the polynomial term
    int array_size;
    int polynomial_order;

    // create pointer for array that contains the terms of the estimate
    double* array;

    // the amount of terms used in the estimate
    polynomial_order = 20;

    // array size is the polynomial order + 1 because of the 1 at the beginning
    array_size = polynomial_order + 1;

    // allocate memory size
    array = (double*) malloc(array_size *sizeof (double));

    // ans stores the estimate for e
    double ans = 0;

    // loop goes through the tersm and stores them in array, each term is then
    // added to ans and printed
    for(int i = 0; i<array_size; i++){
        array[i] = estimate(1, i);
        ans+=array[i];

        printf("f[%d] = %.20lf\n", i, ans);
    }

    // reset answer
    ans= 0;

    // use math.h to obtain accurate value for e
    double e_real = M_PI;

    printf("\ne real = %.20lf\n\n", e_real);

    // difference will store the difference between estimate and real answer
    double difference;

    // go through terms and compute the differecne for each order of polynomial used
    for(int i = 0; i<array_size; i++){
        ans+=array[i];
        difference = e_real - ans;
        printf("f[%d] difference = %.20lf\n", i, difference);
    }

    // free array memory
    free(array);
    array = NULL;
}
