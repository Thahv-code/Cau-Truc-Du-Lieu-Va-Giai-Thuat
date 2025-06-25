//
// Created by Thanh on 25/06/2025.
//
#include <stdio.h>
int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) {
        printf(" numbermm[%d]:",i);
        scanf("%d",&arr[i]);
    }
    int count=0;
    for (int i=0;i<n/2;i++) {
        if (arr[i]!=arr[n-1-i]) {
            printf("cap doi xung la (%d,%d)", arr[i], arr[n-1-i]);
            count++;
        }
    }
    if (count==0) {
        printf("Khong co cap doi xung");
    }
    return 0;
}