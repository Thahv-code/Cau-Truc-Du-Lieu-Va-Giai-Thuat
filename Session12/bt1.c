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

void printListForward(Node* head) {
    printf("Danh sach (tu dau den cuoi):\n");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printListBackward(Node* head) {
    printf("Danh sach (tu cuoi ve dau):\n");
    while (head && head->next != NULL) {
        head = head->next;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, value;

    printf("Nhap so luong phan tu muon tao: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printListForward(head);
    printListBackward(head);

    return 0;
}