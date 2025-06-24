//
// Created by Thanh on 24/06/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Enter initial number of elements (0 < n < 1000): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("Invalid size.\n");
        return 1;
    }

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter number of elements to add (m ≥ 0): ");
    scanf("%d", &m);
    if (m < 0 || n + m > 1000) {
        printf("Invalid number of elements to add.\n");
        free(array);
        return 1;
    }

    int *newArray = (int *)realloc(array, (n + m) * sizeof(int));
    if (newArray == NULL) {
        printf("Memory reallocation failed.\n");
        free(array);
        return 1;
    }
    array = newArray;

    printf("Enter %d more elements:\n", m);
    for (int i = n; i < n + m; i++) {
        scanf("%d", &array[i]);
    }

    printf("Final array:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
