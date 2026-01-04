#include "queue.h"
#include <assert.h>

void should_create_queue_with_a_value() {
    struct Queue q = {0};

    enqueue(&q, 'a');

    assert(q.front->value == 'a');
    assert(q.rear->value == 'a');
}

void should_create_queue_with_a_and_b_value() {
    struct Queue q = {0};

    enqueue(&q, 'a');

    assert(q.front->value == 'a');
    assert(q.rear->value == 'a');

    enqueue(&q, 'b');

    assert(q.front->value == 'a');
    assert(q.rear->value == 'b');
}

void should_create_queue_with_a_b_and_c_value() {
    struct Queue q = {0};

    enqueue(&q, 'a');

    assert(q.front->value == 'a');
    assert(q.rear->value == 'a');

    enqueue(&q, 'b');

    assert(q.front->value == 'a');
    assert(q.rear->value == 'b');

    enqueue(&q, 'c');

    assert(q.front->value == 'a');
    assert(q.rear->value == 'c');
}

int main() {
    should_create_queue_with_a_value();
    should_create_queue_with_a_and_b_value();
    should_create_queue_with_a_b_and_c_value();

    return 0;
}