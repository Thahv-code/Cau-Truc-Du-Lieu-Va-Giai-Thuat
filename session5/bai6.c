//
// Created by Thanh on 26/06/2025.
//
#include <stdio.h>

int sum(int arr[], int n);
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int result = sum(arr, n);
    printf("Sum of array elements: %d\n", result);
    return 0;
}
int sum(int arr[], int n) {
    if (n < 1) {
        return 0;
    }
    return arr[n-1] + sum(arr, n-1);
}