//
// Created by Thanh on 26/06/2025.
//
#include <stdio.h>

void printNumbers(int n) {
    if (n < 1) {
        return;
    }
    printNumbers(n - 1);
    printf("%d ", n);
}
int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printNumbers(n);
    return 0;
}