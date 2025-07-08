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
    if (s->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    return s->data[s->top--];
}

void printStack(Stack s) {
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.data[i]);
        if (i < s.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s.top);
    printf("    cap: %d\n", s.maxSize);
    printf("}\n");
}

int main() {
    Stack myStack = createStack(5);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    push(&myStack, 50);

    printStack(myStack);
    printf("%d\n", pop(&myStack));

    while (myStack.top != -1) {
        pop(&myStack);
    }

    printStack(myStack);
    pop(&myStack);

    free(myStack.data);
    return 0;
}