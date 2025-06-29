//
// Created by Thanh on 27/06/2025.
//
#include <stdio.h>

void nhiPhan(int n) {
    if (n > 0) {
        nhiPhan(n / 2);
        printf("%d", n % 2);
    }
}
int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n == 0) {
        printf("0");
    } else {
        nhiPhan(n);
    }
    return 0;
}
