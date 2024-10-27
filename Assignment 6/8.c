//Write a program to solve the tower of Hanoi problem using recursion.




#include <stdio.h>

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination); // Move n-1 disks from source to auxiliary
    printf("Move disk %d from peg %c to peg %c\n", n, source, destination); // Move the nth disk to destination
    towerOfHanoi(n - 1, auxiliary, destination, source); // Move n-1 disks from auxiliary to destination
}

// Main function
int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Steps to solve Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods

    return 0;
}
