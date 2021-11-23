
// import packages
#include "stdio.h"
#include "Magic_square.h"
#include "stdlib.h"

void User_method(void){

    //n is the size of the square matrix to be set by the user
    int n;
    printf("\nPlease input size of matrix: \n");
    scanf("%d", &n);


    // create pointer to square matrix with allocated memory
    int **square = malloc(n*sizeof (int*));

    // Use loop to allocate memory for each row
    for(int i = 0; i<n; i++){
        square[i] = malloc(n* sizeof(int));
    }

    //tell the user to enter in each element and read the user entries
    for(int i  = 0; i<n; i++){
        printf("please enter elements in row %d: \n", i+1);
        for (int j = 0; j<n; j++){
            scanf("%d", &square[i][j]);
        }
    }

    // Use isMagicSquare function to determine if the square matrix is magic
    int isMagic = isMagicSquare(square, n);

    // print results, use ternary operator
    printf("\nthe matrix %s magic\n", isMagic ? "is": "is not");

    // free each rows memory and then free the matrix
    for(int i = 0; i<n;i++){
        free(square[i]);
    }
    free(square);

}
int main(void){

    User_method();

    return 0;
}