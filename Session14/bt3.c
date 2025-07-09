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
    if (current == NULL) {
        printf("NULL\n}\n\n");
        return;
    }
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n}\n\n");
}

void printStackElements(Stack* stack) {
    if (stack->top == NULL) {
        printf("Ngăn xếp trống\n");
        return;
    }
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    Stack* myStack = createStack();

    push(myStack, 5);
    push(myStack, 4);
    push(myStack, 3);
    push(myStack, 2);
    push(myStack, 1);
    displayStack(myStack);

    int value;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &value);
    if (value > 0) {
        push(myStack, value);
    }

    printStackElements(myStack);

    return 0;
}