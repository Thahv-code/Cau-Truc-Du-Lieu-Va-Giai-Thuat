//
// Created by Thanh on 13/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue createQueue() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}