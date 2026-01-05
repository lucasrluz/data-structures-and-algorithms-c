#ifndef STACK_H
#define STACK_H

struct Node {
    char value;
    struct Node *prev;
};

struct Stack {
    struct Node *top;
};

void push(struct Stack *s, char value);
void pop(struct Stack *s);

#endif