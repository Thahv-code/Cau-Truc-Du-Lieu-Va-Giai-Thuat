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

void deleteByValue(Node** head, int target) {
    Node* current = *head;
    while (current != NULL) {
        if (current->data == target) {
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                *head = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
            Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d<->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, value, target;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh sach truoc khi xoa:\n");
    printList(head);

    printf("Nhap gia tri can xoa: ");
    scanf("%d", &target);

    deleteByValue(&head, target);

    printf("Danh sach sau khi xoa cac phan tu %d:\n", target);
    printList(head);

    return 0;
}