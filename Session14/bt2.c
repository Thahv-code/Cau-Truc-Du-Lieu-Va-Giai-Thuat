//
// Created by Thanh on 09/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
}

void displayStack(Stack* stack) {
    Node* current = stack->top;
    printf("stack = {\n   ");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n}\n\n");
}

int main() {
    Stack* myStack = createStack();
    displayStack(myStack);

    int value;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &value);
    if (value > 0) {
        push(myStack, value);
    }

    displayStack(myStack);

    return 0;
}