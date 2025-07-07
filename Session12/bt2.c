//
// Created by Thanh on 07/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printData(Node* head) {
    while (head != NULL) {
        printf("data: %d\n", head->data);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    int n, value;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printData(head);

    return 0;
}