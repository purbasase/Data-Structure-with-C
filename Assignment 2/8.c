//c program to allocate memory using malloc() and then reallocate the previously allocated memory using realloc(). Display the elements which have been taken after reallocation

#include <stdio.h>
#include <stdlib.h>int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the new number of elements: ");
    scanf("%d", &n);

    arr = (int *)realloc(arr, n * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    printf("Enter the new elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The elements after reallocation are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
