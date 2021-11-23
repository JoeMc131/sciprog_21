//import packages
#include "stdio.h"

void hanoi(int no_disks, int source, int destination, int middle){
    /*
     * Algorithm is as follows:
     *
     * n-1 disks moved to position 2
     * 1 disk moved from position 1 to position 3
     * n-1 disks moved from position 2 to posiition 3
     *
     * Use recursion to implement algorithm
     *
     */
    if (no_disks==1){
        printf("\nmoved disk number %d from %d to  %d\n", no_disks, source, destination);
    }else{
        hanoi(no_disks-1, source, middle, destination);
        printf("\nMoved disk number %d from %d to %d\n", no_disks, source, destination);
        hanoi(no_disks-1, middle, destination, source);
    }
}

int main(void){
    // n_disks will determine the number of disks in the hanoi puzzle,
    // it will be set by user
    int n_disks;
    printf("\nenter the number of disks:\n");
    scanf("%d", &n_disks);

    // print the solution
    printf("\nTower of hanoi solution\n");

    hanoi(n_disks, 1, 3, 2);
}
