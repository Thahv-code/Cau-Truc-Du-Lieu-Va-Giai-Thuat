//
// Created by Thanh on 02/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtHead(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node* createInitialList() {
    struct Node* head = NULL;
    for (int i = 5; i >= 1; i--) {
        insertAtHead(&head, i);
    }
    return head;
}

// Xóa phần tử đầu tiên trong danh sách
void deleteHead(struct Node** head) {
    if (*head != NULL) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = createInitialList();

    printf("Danh sách ban đầu:\n");
    printList(head);

    deleteHead(&head);

    printf("Danh sách sau khi xóa phần tử đầu:\n");
    printList(head);

    return 0;
}