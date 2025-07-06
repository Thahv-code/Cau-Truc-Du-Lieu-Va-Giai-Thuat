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

    int value;
    printf("Nhap so nguyen duong muon them vao dau danh sach: ");
    scanf("%d", &value);

    if (value > 0) {
        addToHead(&head, value);
        printf("Danh sach sau khi them:\n");
        printList(head);
    } else {
        printf("Gia tri khong hop le. Chi chap nhan so nguyen duong.\n");
    }

    return 0;
}