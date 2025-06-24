//
// Created by Thanh on 22/06/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos, val;
    printf("Enter array size (1–100): ");
    scanf("%d", &n);
    if (n < 1 || n > 100) return 1;
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter position to update (0–%d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) return 1;
    printf("Enter new value: ");
    scanf("%d", &val);
    arr[pos] = val;
    printf("Updated array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}

