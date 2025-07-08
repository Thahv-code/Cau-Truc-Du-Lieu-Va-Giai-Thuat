//
// Created by Thanh on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *data;
    int top;
    int maxSize;
} Stack;

Stack createStack(int maxSize) {
    Stack s;
    s.data = (char *)malloc(maxSize * sizeof(char));
    s.top = -1;
    s.maxSize = maxSize;
    return s;
}

void push(Stack *s, char value) {
    if (s->top < s->maxSize - 1) {
        s->top++;
        s->data[s->top] = value;
    }
}

char pop(Stack *s) {
    if (s->top == -1) return '\0';
    return s->data[s->top--];
}

bool isPalindrome(char *str) {
    int len = strlen(str);
    Stack s = createStack(len);
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            free(s.data);
            return false;
        }
    }
    free(s.data);
    return true;
}

int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}