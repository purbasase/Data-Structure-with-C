//Write a program to print the Fibonacci series using recursion.




#include <stdio.h>

// Recursive function to calculate the Fibonacci number
int fibonacci(int n) {
    if (n <= 0) {
        return 0; // Base case: F(0) = 0
    } else if (n == 1) {
        return 1; // Base case: F(1) = 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

// Function to print the Fibonacci series
void printFibonacciSeries(int terms) {
    printf("Fibonacci series up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Main function
int main() {
    int terms;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &terms);

    printFibonacciSeries(terms);

    return 0;
}
