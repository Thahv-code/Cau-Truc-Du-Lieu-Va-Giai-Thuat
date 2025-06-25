//
// Created by Thanh on 25/06/2025.
//
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
        printf(" arr[%d]:",i);
        scanf("%d",&arr[i]);
    }
    int findNumber, index;
    printf("nhap so cua ban muon tim:");
    scanf("%d",&findNumber);
    for (int i=0;i<n;i++) {
        if (findNumber == arr[i]) {
            index=i;
            break;
        }
    }
    if (index != -1) {
        printf("khong tim thay");
    } else {
        printf("%d", index);
    }
    return 0;
}