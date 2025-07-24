//
// Created by Thanh on 24/07/2025.
//
#include <stdio.h>
#define MAX 100

int n;
int MATRIX[MAX][MAX];

void matrix() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            MATRIX[i][j] = 0;
        }
    }
}

void addEdge(int U, int V) {
    MATRIX[U][V] = 1;
    MATRIX[V][U] = 1;
}

void printMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Nhap so dinh: ");
    scanf("%d", &n);

    matrix();

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(3, 2);
    addEdge(1, 3);
    addEdge(3, 4);

    printMatrix();

    return 0;
}
