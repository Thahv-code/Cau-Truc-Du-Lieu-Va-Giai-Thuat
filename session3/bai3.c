//
// Created by Thanh on 24/06/2025.
//
#include <stdio.h>
#include <stdlib.h>
void averge(int* arr,int n) {
    int sum=0;
    int count=0;
    for (int i=0;i<n;i++) {
        if (arr[i]%2==0) {
            sum+=arr[i];
            count++;
        }
    }
    if (count!=0) {
        printf("So tung cac so chan cua mang la %d",sum/count);
    }else{
        printf("Khong co so chan");
    }
}
int main() {
    int n;
    do{
        printf("nhap so  n :");
        scanf("%d",&n);
        if(n<0){
            printf("nhap lai");
        }
    }while(n<0);

    int* arr=malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Null");
        return 0;
    }
    for(int i=0;i<n;i++){
        printf("nhap phan tu %d :",i+1);
        scanf("%d",&arr[i]);
    }
    averge( arr,n);
    free(arr);

}