#include <stdio.h>
//
// Created by Thanh on 22/06/2025.
//
int main() {
    int n, value, count = 0;

    printf("enter number array: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("invalid.\n");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("invalid\n");
        return 1;
    }
    printf("enter number:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("enter number: ");
    scanf("%d", &value);
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    printf("%d\n", value, count);
    free(arr);
    return 0;
}