//
// Created by Thanh on 23/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int startNode, int endNode) {
    Node* newNode1 = createNode(endNode);
    newNode1->next = graph[startNode];
    graph[startNode] = newNode1;

    Node* newNode2 = createNode(startNode);
    newNode2->next = graph[endNode];
    graph[endNode] = newNode2;
}

void printGraph(Node* graph[], int size) {
    for (int i = 0; i < size; i++) {
        Node* temp = graph[i];
        if (temp == NULL) {
            printf("NULL\n");
        } else {
            while (temp != NULL) {
                printf("%d", temp->data);
                if (temp->next != NULL) printf("->");
                temp = temp->next;
            }
            printf("->NULL\n");
        }
    }
    printf("\n");
}

int main() {
    Node* graph[3] = {NULL, NULL, NULL};

    printGraph(graph, 3);

    addEdge(graph, 1, 2);
    printGraph(graph, 3);

    addEdge(graph, 0, 1);
    printGraph(graph, 3);

    return 0;
}