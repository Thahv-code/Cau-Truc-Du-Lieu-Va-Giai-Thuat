//
// Created by Thanh on 24/07/2025.
//
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node*next;
}Node;
Node* createNode(int data) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
Node* adjacency[10];


void createAdjacency(int U, int V) {
    Node* node = createNode(U);
    node->next = adjacency[U];
    adjacency[U] = node;

    node = createNode(V);
    node->next = adjacency[V];
    adjacency[V] = node;
}
void print() {
    for (int i=0;i<4;i++) {
        Node* current=adjacency[i];
        printf("Đỉnh thứ ");
        while (current!=NULL) {
            printf("%d", current->data);
            current=current->next;
            if (current!=NULL) {
                printf("->");
            }
            else {
                printf("NULL");

            }
        }
        printf("\n");
    }
}
int main() {
    for (int i=0;i<4;i++) {
        adjacency[i]=NULL;
    }

    createAdjacency(1,2);
    createAdjacency(1,3);
    createAdjacency(2,3);
    createAdjacency(2,4);
    createAdjacency(3,4);
    createAdjacency(5,3);
    createAdjacency(6,3);


    Node* current=adjacency[3];
    int sum=0;
    while (current!=NULL) {
        sum++;
        current=current->next;
    }
    printf("Số đỉnh kề với 3 là: %d", sum);
}