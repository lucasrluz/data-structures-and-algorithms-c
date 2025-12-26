#include <stdio.h>
#include <stdlib.h>

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
    struct LinkedList list = { .head=NULL };

    insert_beginning(&list, 'a');
    insert_beginning(&list, 'b');
    insert_beginning(&list, 'c');

    printf("Adicionando elementos:\n");
    printf("Primeiro elemento: %c\n", list.head->value);
    printf("Segundo elemento: %c\n", list.head->next->value);
    printf("Terceito elemento: %c\n\n", list.head->next->next->value);

    printf("Removendo elementos:\n");

    remove_beginning(&list);
    printf("Primeiro elemento: %c\n", list.head->value);
    printf("Segundo elemento: %c\n\n", list.head->next->value);

    remove_beginning(&list);
    printf("Primeiro elemento: %c\n", list.head->value);

    return 0;
}
