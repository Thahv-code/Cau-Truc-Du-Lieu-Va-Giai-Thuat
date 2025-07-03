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
        printf("Không thể cấp phát bộ nhớ\n");
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

void appendNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    struct Node* head = NULL;

    appendNode(&head, 5);
    appendNode(&head, 4);
    appendNode(&head, 3);
    appendNode(&head, 2);
    appendNode(&head, 1);

    printList(head);

    int x;
    printf("Nhap so nguyen duong can them: ");
    scanf("%d", &x);

    if (x > 0) {
        appendNode(&head, x);
        printList(head);
    } else {
        printf("So nhap khong hop le\n");
    }

    return 0;
}