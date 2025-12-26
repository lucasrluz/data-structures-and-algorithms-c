#include <stdio.h>

struct Node {
    char value;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

int main() {
    struct LinkedList list = { .head=NULL };

    struct Node n1 = { .value='a', .next=NULL };
    struct Node n2 = { .value='b', .next=NULL };

    list.head = &n1;

    n1.next = &n2;

    printf("Primeiro elemento: %c\n", list.head->value);
    printf("Segundo elemento: %c\n", list.head->next->value);

    return 0;
}
