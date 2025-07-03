//
// Created by Thanh on 03/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteByValue(struct Node** head, int value) {
    while (*head != NULL && (*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    struct Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int main() {
    struct Node* head = NULL;

    head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(1);
    head->next->next->next->next->next->next = createNode(5);

    printList(head);

    int x;
    printf("Nhap so muon xoa: ");
    scanf("%d", &x);

    deleteByValue(&head, x);

    printList(head);

    return 0;
}