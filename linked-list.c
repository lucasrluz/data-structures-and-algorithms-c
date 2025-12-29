#include <stdlib.h>
#include <assert.h>

struct Node {
    char value;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

void insert_beginning(struct LinkedList *list, char value) {
    struct Node *node = malloc(sizeof(struct Node));

    node->value = value;
    node->next = list->head;

    list->head = node;
}

void remove_beginning(struct LinkedList *list) {
    list->head = list->head->next;
}

int main() {
    // insert_beginning
    struct LinkedList list1 = { .head=NULL };

    insert_beginning(&list1, 'a');

    assert(list1.head->value == 'a');

    insert_beginning(&list1, 'b');

    assert(list1.head->value == 'b');
    assert(list1.head->next->value == 'a');

    insert_beginning(&list1, 'c');

    assert(list1.head->value == 'c');
    assert(list1.head->next->value == 'b');
    assert(list1.head->next->next->value == 'a');

    // remove_beginning

    remove_beginning(&list1);

    assert(list1.head->value == 'b');
    assert(list1.head->next->value == 'a');

    remove_beginning(&list1);

    assert(list1.head->value == 'a');

    remove_beginning(&list1);

    assert(list1.head == NULL);

    return 0;
}
