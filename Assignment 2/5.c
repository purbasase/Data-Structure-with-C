//c program that reads a 2d matrix and check if the matrix is a symmetric or not.

#include <stdio.h>
int main() {
    int n;
    // Input the size of the matrix (for simplicity, we assume a square matrix)
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is symmetric
    int isSymmetric = 1; // Assume the matrix is symmetric

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; // The matrix is not symmetric
                break;
            }
        }
        if(!isSymmetric) {
            break;
        }
    }

    // Output the result
    if(isSymmetric) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}
