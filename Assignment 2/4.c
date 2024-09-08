//c program that reads 2d matrices from the console ,verifies if matrices multiplication is possible or not .The multiplies the matrices and prints the 3rd metrices

#include <stdio.h>
void multiplyMatrices(int fm[][10], int sm[][10], int result[][10], int rf, int cf, int rs, int cs) {
    for (int i = 0; i < rf; ++i) {
        for (int j = 0; j < cs; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cf; ++k) {
                result[i][j] += fm[i][k] * sm[k][j];
            }
        }
    }
}

int main() {
    int fm[10][10], sm[10][10], result[10][10];
    int rf, cf, rs, cs;

    // Input dimensions of first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rf, &cf);

    // Input dimensions of second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rs, &cs);

    // Verify if multiplication is possible
    if (cf != rs) {
        printf("Error! Column of first matrix not equal to row of second.\n");
        return -1;
    }

    // Input elements for first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rf; ++i) {
        for (int j = 0; j < cf; ++j) {
            scanf("%d", &fm[i][j]);
        }
    }

    // Input elements for second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rs; ++i) {
        for (int j = 0; j < cs; ++j) {
            scanf("%d", &sm[i][j]);
        }
    }

    // Multiply matrices
    multiplyMatrices(fm, sm, result, rf, cf, rs, cs);

    // Display the result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < rf; ++i) {
        for (int j = 0; j < cs; ++j) {
            printf("%d ", result[i][j]);
            if (j == cs - 1)
                printf("\n");
        }
    }

    return 0;
}
