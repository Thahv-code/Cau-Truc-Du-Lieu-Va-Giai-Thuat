//
// Created by Thanh on 04/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
typedef  struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* insertAtHead(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}