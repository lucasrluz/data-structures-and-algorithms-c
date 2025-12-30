#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct Node {
    char value;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

int insert_after(struct LinkedList *list, char node, char value) {
    struct Node *n = list->head;

    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->value = value;
    new_node->next = NULL;

    while (n != NULL) {
        if (n->value == node) {
            new_node->next = n->next; 

            n->next = new_node;

            return 0;
        }

        n = n->next;

        if (n == NULL) {
            return 1;
        }
    }

    return 0;  
}

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

    // insert_after
    insert_beginning(&list1, 'a');
    insert_beginning(&list1, 'b');
    insert_beginning(&list1, 'c');

    assert(insert_after(&list1, 'c', 'x') == 0);

    assert(list1.head->value == 'c');
    assert(list1.head->next->value == 'x');
    assert(list1.head->next->next->value == 'b');
    assert(list1.head->next->next->next->value == 'a');

    assert(insert_after(&list1, 'y', 'f') == 1);

    return 0;
}
