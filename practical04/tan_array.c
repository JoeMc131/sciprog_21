//import the packages
#include "math.h"
#include "stdio.h"

// convert angle from degrees to radians
float deg2rad(float angle_degrees){

    float radians = (M_PI/180)*angle_degrees;

    return radians;
}

//preform trapezoidal rule using elements in array
float trapezoidal(float arr[], int N, float a, float b){
    //answer is initlised by adding the first and last values	 
    float ans = arr[0] + arr[-1];

    //compute integral using loop   
    for(int i = 1; i<N; i++){
        ans += 2*arr[i];
    }
    //mulitply answer by the radian form of the sacle factor
    ans*= deg2rad((b-a)/(2*N));
    return ans;
}

int main(void){
    
    float a = 0;		//lower limit of integral      
    float b = 60;		//upper limit of integral
    int N = 13;			//number of steps in integral
    float tan_arr[N+1];		//array size
    float x = 0;		//where the x variable starts
    float step_size = 5;	// step size of the integral

    for(int index = 0;index<=N;index++){
	//convert the x variable to radians
        x = deg2rad(x);

	//store the tan of x in an array
        tan_arr[index] = tanf(x);
	
	//print array elements
        printf("%.1f \n", tan_arr[index]);

	//increment x value
        x = index*step_size;
    }

    //compute integral	
    float integral = trapezoidal(tan_arr, N, a, b);

    //print results
    printf("\n%.3f", integral);

    return 0;
}
