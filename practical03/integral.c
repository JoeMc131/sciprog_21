#include "math.h"
#include "stdio.h"

float f(float x){

//    The integrand
    return tanf(x);
}


int main(void){

//    the limits of integration
    float a = 0;
    float b = M_PI/3;

//    The number steps taken in the integration
    int N = 12;

//    The index of each step, to be incremented in the while loop
    float i = 1;

//    step size
    float dx = (b-a)/N;

//    The current value of x
    float x;

//    Where the answer will be stored, first and last values added first
    float ans = f(a) + f(b);

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
    printf("\nN = %d\na = %.3f\nb = %.3f\n", N, a, b);

    printf("\nThe computed answer to the integral is %.5f", ans);
    printf("\nThe actual answer is %.5f\n", logf(2));

    return 0;
}
