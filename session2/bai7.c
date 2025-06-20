#include <stdio.h>
//
// Created by Thanh on 20/06/2025.
//
int  main() {
    int n, target;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) {
        printf(" arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter number:");
    scanf("%d",&target);
    int found=0;
    int flag=0;
    for (int i=0;i<n - 1 && !found;i++) {
        for (int j=i + 1;j <n;j++) {
            if (arr[i] + arr[j] ==target) {
                printf("%d + %d = %d\n",arr[i],arr[j],target);
             flag++;
                }
            }
        }
    if (flag==0) {
        printf("Khong co ");
    }

}