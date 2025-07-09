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
        printf("Khong the cap phat bo nho!\n");
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
        printf("Khong the cap phat bo nho cho Stack!\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

void displayStack(Stack* stack) {
    Node* current = stack->top;
    printf("Noi dung ngan xep: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Stack* myStack = createStack();
    printf("Stack da duoc tao thanh cong!\n");
    displayStack(myStack);

    return 0;
}