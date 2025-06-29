//
// Created by Thanh on 27/06/2025.
//
#include <stdio.h>
void sum(int n) {
    if (n == 0) return 0;
        return n%10 + sum(n/10);
}

int main() {
    int n;
    printf("nhap so nguyen:");
    scanf("%d",&n);
    if (n < 0) {
        printf("So nguyen phai lon hon 0");
    }

    int totalSum = sum(n);
    printf("Tong so nguyen: %d", sum);
    return 0;
}