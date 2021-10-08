#include "math.h"
#include "stdio.h"

double f(double x){

//    The integrand
    return tan(x);
}


int main(void){

//    the limits of integration
    double a = 0;
    double b = M_PI/3;

//    The number steps taken in the integration
    double N = 12;

//    The index of each step, to be incremented in the while loop
    int i = 1;

//    step size
    double dx = (b-a)/N;

//    The current value of x
    double x;

//    Where the answer will be stored, first and last values added first
    double ans = f(a) + f(b);

//    While loop to preform integration
    while(i<=N-1){
//        calculate current x value
        x = a + i*dx;

//        add onto answer
        ans += 2*f(x);

//        increment i
        i += 1;
    }

//    Multiply answer by factor
    ans *= (b-a)/(2*N);

//    print results
    printf("\nN = %d\na = %.3f\nb = %.3f\n", &N, &a, &b);

    printf("\nThe computed answer to the integral is %.10f", ans);
    printf("\nThe actual answer is %.10f\n", logf(2));

    return 0;
}
