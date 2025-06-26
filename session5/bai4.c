//
// Created by Thanh on 26/06/2025.
//
#include <stdio.h>
int sum(int a, int b) {
    if (a > b)
        return 0;
    return a + sum(a + 1, b);
}
   int main() {
    int firstNum, secondNum;
    printf("enter first number: ");
    scanf("%d", &firstNum);
    printf("enter second number: ");
    scanf("%d", &secondNum);

    if (firstNum > secondNum) {
        int temp = firstNum;
        firstNum = secondNum;
        secondNum = temp;
    }
     int result = sum(firstNum, secondNum);
    printf("%d", result);
    return 0;
}