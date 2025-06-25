//
// Created by Thanh on 25/06/2025.
//
#include <stdio.h>
int  main() {
    int n, target;
    printf("nhap so luong phan tu mang:");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) {
        printf(" arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    int minArr=arr[0];
    for (int i=0;i<n;i++) {
        if (arr[i]<minArr) {
            minArr=arr[i];
        }
    }
    printf("%d\n",minArr);
    return 0;

}