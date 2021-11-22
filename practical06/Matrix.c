/*
 * This program utilises Matrix_mult.h to preform a matrix multiplication on
 * two matrices A and B and stores the result in C
 *
 */

//import files
#include "stdio.h"
#include "Matrix_mult.h"

int main(void){

    // initiate the dimensions of the matrix
    n = 5;
    p = 3;
    q = 4;

    //initialise the matrices
    int A[n][p];
    int B[p][q];
    int C[n][q];

    //A is filled by adding the indices
    for(int i = 0; i<n; i++){
        for(int j = 0; j<p; j++){
            A[i][j] = i + j;
        }
    }
    // B is filled by subtracting the matrices
    for(int i = 0; i<p; i++){
        for(int j = 0; j<q; j++){
            B[i][j] = i - j;
        }
    }

    //preform the matrix multiplication
    matmult(A, B, C);


    // print A
    printf("\n\nA is: \n");

    for(int i = 0; i<n; i++){
        printf("\n");
        for(int j = 0; j<p; j++){
            printf("%d\t", A[i][j]);
        }
    }

    //print B
    printf("\n\nB is: \n");

    for(int i = 0; i<p; i++){
        printf("\n");
        for(int j = 0; j<q; j++){
            printf("%d\t", B[i][j]);
        }
    }

    //print C
    printf("\n\nC is: \n");

    for(int i = 0; i<n; i++){
        printf("\n");
        for(int j = 0; j<q; j++){
            printf("%d\t", C[i][j]);
        }
    }

    // newline for tidiness
    printf("\n");

    return 0;
}
