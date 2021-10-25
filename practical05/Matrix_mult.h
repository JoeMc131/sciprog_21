/*
 * This program preforms the matrix multiplication by taking two matrices and an empty matrix
 * to be filled with the result
 *
 * Could improve by returning the resulting matrix instead of returning nothing
 *
 */


//The dimensions of the matrix
int n;
int p;
int q;

void matmult(int A[n][p], int B[p][q], int C[n][q]){
    //Initlise the matrix to be zero everywhere (otherwise i get weird values when I run the program)
    for(int i = 0; i<n; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] = 0;
            }
        }
    }

    //Preform the matrix multiplication
    for(int i = 0; i<n; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}