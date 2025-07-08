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

void push(Stack *s, int value) {
    if (s->top < s->maxSize - 1) {
        s->top++;
        s->data[s->top] = value;
    }
}

int pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->data[s->top--];
}

void reverseArray(int *arr, int n) {
    Stack s = createStack(n);
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
    free(s.data);
}

void printArray(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);
    reverseArray(arr, n);
    printArray(arr, n);

    free(arr);
    return 0;
}