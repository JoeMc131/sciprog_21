#include "math.h"
#include "stdio.h"

float deg2rad(float angle_degrees){

    float radians = (M_PI/180)*angle_degrees;

    return radians;
}

float trapezoidal(float arr[], int N, float a, float b){
    float ans = arr[0] + arr[-1];

    for(int i = 1; i<N; i++){
        ans += 2*arr[i];
    }
    ans*= deg2rad((b-a)/(2*N));
    return ans;
}

int main(void){

    float a = 0;
    float b = 60;
    int N = 13;
    float tan_arr[N+1];
    float x = 0;
    float step_size = 5;

    for(int index = 0;index<=N;index++){
        x = deg2rad(x);

        tan_arr[index] = tanf(x);

        printf("%.1f \n", tan_arr[index]);

        x = index*step_size;
    }

    float integral = trapezoidal(tan_arr, N, a, b);

    printf("\n%.3f", integral);

    return 0;
}
