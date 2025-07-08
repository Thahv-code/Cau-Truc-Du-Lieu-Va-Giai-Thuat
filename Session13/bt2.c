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

int main() {
    Stack myStack = createStack(5);
    int value;
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        push(&myStack, value);
    }

    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= myStack.top; i++) {
        printf("%d", myStack.data[i]);
        if (i < myStack.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", myStack.top);
    printf("    cap: %d\n", myStack.maxSize);
    printf("}\n");

    free(myStack.data);
    return 0;
}