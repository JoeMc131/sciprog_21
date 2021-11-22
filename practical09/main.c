//used when reading in the file
#define MAX_FILE_NAME 100

//import packages
#include "stdio.h"
#include "Magic_square.h"
#include "stdlib.h"

int getLines(char filename[MAX_FILE_NAME]){
    //initilise filename
    FILE *f;

    //open the file
    f = fopen(filename, "r");

    //reads the character at a specific index
    int char_read;

    // counts the number of lines
    int count = 1;

    while((char_read =  fgetc(f))!=EOF){
        if (char_read=='\n'){
            //if the current character is a new line add to count
            count++;
        }
    }

    //print the number of lines
    printf("\nNumber of lines  = %d\n", count);

    // close the file
    fclose(f);

    return count;
}

void Read_method(char fileName[MAX_FILE_NAME]){

    // preforms the isMagicSquare function on a matrix that's been read in from a text file

    // n is the number of lines, ie. size of square matrix
    int n;

    // initlise the file pointer
    FILE *f;

    // open the file
    f = fopen(fileName, "r");

    // get the number of lines
    n = getLines(fileName);

    // square matrix pointer, allocate memory
    int **square = malloc(n*sizeof (int*));

    // allocate memory for each row
    for (int i = 0; i < n; ++i) {
        square[i] = malloc(n*sizeof (int));
    }

    // read in values from text file
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            fscanf(f, "%d", &square[i][j]);
        }
    }

    // print result
    printf("\nThe matrix %s magic\n", isMagicSquare(square, n) ? "is":"is not");

    // free memory
    for(int i = 0; i<n; i++){
        free(square[i]);
    }
    free(square);

    // close file
    fclose(f);
}

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
    //initialise the filename
    char filename[MAX_FILE_NAME];

    // ask user to enter in the filename
    printf("Enter file name: ");
    scanf("%s", filename);

    // preform the read file method first, then the user input method
    Read_method(filename);
    User_method();

    return 0;
}