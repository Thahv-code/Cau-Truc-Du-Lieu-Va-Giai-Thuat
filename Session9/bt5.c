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

int main() {
    struct Node* head = createInitialList();

    printf("Danh sách ban đầu:\n");
    printList(head);

    int x;
    printf("Nhập số nguyên dương cần chèn vào đầu danh sách: ");
    scanf("%d", &x);

    if (x > 0) {
        insertAtHead(&head, x);
        printf("Danh sách sau khi chèn:\n");
        printList(head);
    } else {
        printf("Giá trị không hợp lệ.\n");
    }

    return 0;
}