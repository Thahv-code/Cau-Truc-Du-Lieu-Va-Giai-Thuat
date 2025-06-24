//
// Created by Thanh on 20/06/2025.
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
    if (arr[i]%2==0) {
        printf("%d\n",arr[i]);
    }
}