//
// Created by Thanh on 26/06/2025.
//
#include <stdio.h>
    int recursion (int n) {
        if (n == 1) {
            return 1;
        }
        return n + recursion(n - 1);
    }
    int main () {
        int n;
        printf("Enter n:");
        scanf("%d",&n);
        if (n <=0) {
            printf("khong hop le\n");
            return 1;
        }
        printf("%d", recursion(n));
    }
