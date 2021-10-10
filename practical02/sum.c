#include "stdio.h"
#include <math.h>
#include "stdlib.h"

int main(void){

    // Declare variables
    int i;
    float sum1, sum2, difference;

    // Sum1 calculation
    sum1 = 0;
    for (i = 1; i <= 1000; i++)
    {
        sum1 += 1./i;
    }

    // Sum2 calculation
    sum2 = 0;
    for(i = 1000; i>0; i--){
        sum2 += 1./i;
    }

    // print results
    printf("\nsum 1 = %f", sum1);
    printf("\nsum 2 = %f", sum2);

    // Calculate difference
    difference = fabsf(sum1 - sum2);

    // print difference
    printf("\n\nDifference = %.10f", difference);
    

    return 0;
}
