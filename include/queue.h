#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    char value;
    struct Node *prev;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void enqueue(struct Queue *q, char value);

#endif
