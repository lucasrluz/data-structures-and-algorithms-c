#include "stack.h"
#include <stdlib.h>

void push(struct Stack *s, char value) {
    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->value = value;

    if (s->top == NULL) {
        s->top = new_node;

        return;
    }

    new_node->prev = s->top;
    s->top = new_node;
}

void pop(struct Stack *s) {
    s->top = s->top->prev;
}