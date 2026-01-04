#include "queue.h"
#include <stdlib.h>

void enqueue(struct Queue *q, char value) {
    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->value = value;

    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
        
        return;
    }
    
    q->rear->prev = new_node;
    q->rear = new_node;
}
