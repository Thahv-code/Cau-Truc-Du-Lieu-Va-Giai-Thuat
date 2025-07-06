//
// Created by Thanh on 06/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addToHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void deleteHead(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("<->");
        temp = temp->next;
    }
    printf("->NULL\n");
}

int main() {
    Node* head = NULL;

    addToHead(&head, 5);
    addToHead(&head, 4);
    addToHead(&head, 3);
    addToHead(&head, 2);
    addToHead(&head, 1);

    printf("Danh sach ban dau:\n");
    printList(head);

    deleteHead(&head);

    printf("Danh sach sau khi xoa phan tu dau:\n");
    printList(head);

    return 0;
}