//
// Created by Thanh on 23/07/2025.
//
#include <stdio.h>

#define SIZE 4

void printGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void addEdge(int graph[SIZE][SIZE], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int main() {
    int graph[SIZE][SIZE] = {0};

    printGraph(graph);
    printf("\n");

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    return 0;
}