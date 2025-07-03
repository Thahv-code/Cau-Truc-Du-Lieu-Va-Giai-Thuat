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

void findMiddle(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    if (count % 2 == 0) mid++;

    temp = head;
    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }

    printf("Node %d: %d\n", mid, temp->data);
}

int main() {
    struct Node* head = NULL;

    head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printList(head);
    findMiddle(head);

    head->next->next->next->next->next = createNode(6);

    printList(head);
    findMiddle(head);

    return 0;
}