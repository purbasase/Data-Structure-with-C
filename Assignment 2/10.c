//c program to search an element in an array using dynamic memory allocaation

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, searchElement, found = 0;
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

    printf("Enter the element to search: ");
    scanf("%d", &searchElement);

    for (int i = 0; i < n; i++) {
        if (arr[i] == searchElement) {
            printf("Element found at index %d.\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found.\n");
    }

    free(arr);
    return 0;
}
