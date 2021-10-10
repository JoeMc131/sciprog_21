#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void){

    //This program converts data types

    //Declare variables
    int i, i_num, temp, numdigits;
    float f_num;
    char bin_num[60];

    //Initialise 4-bit integer
    printf("\nPlease input integer\n");
    scanf("%d", &i_num);

    //Convert integer to 4-bit float
    f_num = (float) i_num;

    //Convert integer to binary number(string)
    i = 0; temp = i_num;

    while(temp>0){
        sprintf(&bin_num[i], "%1d", temp%2);
        temp = temp/2;
        i++;
    }

    //Finish string
    bin_num[i] = '\0';

    //Complete
    //
    float binary = atof(bin_num);
    numdigits = logf(binary);
    printf("Number of digits is %d\n", numdigits);

    printf("i_num = %d, f_num = %f, i_num in binary = ",
        i_num, f_num);

    for(int j = numdigits-1; j>=0; --j){
        printf("%c", bin_num[j]);
    }

    printf("\n");

    return 0;
}
