//
// Created by Thanh on 26/06/2025.
//
#include <stdio.h>
void fibonacciOfArray(int arr[], int i, int length, int prev1, int prev2) {
    if (i > length) {
        return;
    }
    if (i == 0) arr[0] = 0;
    else if (i == 1) arr[1] = 1;
    else arr[i] = arr[i - 1] + arr[i - 2];
    return fibonacciOfArray(arr, i + 1, length, prev2, arr[i - 2]);

}
int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);

    int fibonacci[n];
    fibonacciOfArray(fibonacci, 0, n - 1, 0, 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }

    return 0;
}