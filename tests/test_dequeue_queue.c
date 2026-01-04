#include "queue.h"
#include <assert.h>
#include <stdlib.h>

void should_point_front_and_rear_to_same_node_after_dequeue() {
    struct Queue q = {.front = NULL, .rear = NULL};

    enqueue(&q, 'a');
    enqueue(&q, 'b');

    dequeue(&q);

    assert(q.front->value == 'b');
    assert(q.rear->value == 'b');
}

void should_update_front_only_when_dequeuing_multi_element_queue() {
    struct Queue q = {.front = NULL, .rear = NULL};

    enqueue(&q, 'a');
    enqueue(&q, 'b');
    enqueue(&q, 'c');

    dequeue(&q);

    assert(q.front->value == 'b');
    assert(q.rear->value == 'c');
}


int main() {
    should_point_front_and_rear_to_same_node_after_dequeue();
    should_update_front_only_when_dequeuing_multi_element_queue();

    return 0;
}