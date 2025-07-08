//
// Created by Thanh on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top;
    int maxSize;
} Stack;

Stack createStack(int maxSize) {
    Stack s;
    s.data = (int *)malloc(maxSize * sizeof(int));
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}

int main() {
    Stack myStack = createStack(5);
    printf("%d\n", myStack.maxSize);
    free(myStack.data);
    return 0;
}