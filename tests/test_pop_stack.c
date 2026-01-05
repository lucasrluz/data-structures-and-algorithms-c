#include "stack.h"
#include <assert.h>
#include <stdlib.h>

void deve_apontar_front_para_null_quando_removido_unico_elemento_da_stack() {
    struct Stack s = {0};

    push(&s, 'a');
    pop(&s);

    assert(s.top == NULL);
}

void deve_atualizar_front_quando_removido_elemento_da_stack() {
    struct Stack s = {0};

    push(&s, 'a');
    push(&s, 'b');

    pop(&s);

    assert(s.top->value == 'a');
}

int main() {
    deve_apontar_front_para_null_quando_removido_unico_elemento_da_stack();
    deve_atualizar_front_quando_removido_elemento_da_stack();
    
    return 0;
}