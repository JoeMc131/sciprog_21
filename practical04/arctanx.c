#include "stdio.h"
#include "stdbool.h"
#include "math.h"

double arctanh1(double x, double delta){
    //Create variable for the answer
    double ans = 0;

    // stores each term in each iteration
    double term;

    //lets the loop know when to stop
    bool break_loop = false;

    //n increases each loop and is used in the calculation
    double n = 0;

    //loop to preform sum
    while (break_loop==false){
        term = (pow(x, 2*n + 1))/(2*n + 1);

        // check when to stop loop
        if(fabs(term)<delta){
            break_loop = true;
        }else{
            ans+=term;
        }
        //increment n
        n++;
    }
    return ans;
}

double arctanh2(double x){

    //Use approximation to find arctan(x)
    double ans = 0.5*(log(1 + x) - log(1 - x));

    return ans;
}

int main(void){

    // calculate size of array
    double size = (0.9 -(-0.9))/0.01;

    // convert size to int
    int n = (int) size;

    // create arrays
    double first_array[n];
    double second_array[n];

    //index of the arrays
    int index = 0;

    //delta to be set by user
    double delta;

    printf("Please input delta: \n");
    scanf("%lf", &delta);

    // loop to store answers for each value of x
    for(double x = -0.9; x<=0.9; x+=0.01){
        first_array[index] = arctanh1(x, delta);
        second_array[index] = arctanh2(x);

        index++;
    }

    // print out results
    printf("\narctan 1\tarctan 2\tcompared:");

    for(int i = 0; i<n; i++){
        printf("\n%.10lf\t%.10lf\t%.10lf", first_array[i], second_array[i], fabs(first_array[i]-second_array[i]));
    }

    return 0;
}