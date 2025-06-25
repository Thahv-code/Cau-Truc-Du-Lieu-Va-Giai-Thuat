//
// Created by Thanh on 25/06/2025.
//
#include <stdio.h>
#include <string.h>

int main() {
struct SinhVien {
    int id;
    char name[20];
    int age;
};
    struct SinhVien sinhvien[5];
    for (int i=0;i<5;i++) {
        printf("Enter id: ");
        scanf("%d", &sinhvien[i].id);
        getchar();
        printf("Enter name: ");
        fgets(sinhvien[i].name, 20, stdin);
        sinhvien[i].name[strlen(sinhvien[i].name) - 1 ]='\0';
        printf("Enter age: ");
        scanf("%d", &sinhvien[i].age);
    }
    int id;
    printf("Enter id: ");
    scanf("%d", &id);
    for (int i=0;i<5;i++) {
        if (sinhvien[i].id==id) {
            printf("%s %d\n", sinhvien[i].name, sinhvien[i].age)
            return 0;
        }
    }
    printf("Khong tim thay")
}
