//
// Created by Thanh on 25/06/2025.
//
#include <stdio.h>
int main() {
    int n;
    printf("nhap so luong phan tu mang:");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) {
        printf("nhap phan tu thu %d :", i + 1);
        scanf("%d",&arr[i]);
    }
   int checkNumber;
    printf("nhap so cua ban muon tim:");
    scanf("%d",&checkNumber);
    for (int i=0;i<n;i++) {

        if (checkNumber == arr[i]) {
            printf("%d", i);

            return 0;
        }
    }
    printf("khong tim thay");
}