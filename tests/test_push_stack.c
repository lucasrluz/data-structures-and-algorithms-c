#include "stack.h"
#include <assert.h>

void deve_atualizar_front_quando_adicionado_elemento_na_stack() {
    struct Stack s = {0};

    push(&s, 'a');

    assert(s.top->value == 'a');
}

void deve_atualizar_front_quando_adicionado_mais_de_um_elemento_na_stack() {
    struct Stack s = {0};

    push(&s, 'a');

    assert(s.top->value == 'a');

    push(&s, 'b');
    
    assert(s.top->value == 'b');
    assert(s.top->prev->value == 'a');
}

int main() {
    deve_atualizar_front_quando_adicionado_elemento_na_stack();
    deve_atualizar_front_quando_adicionado_mais_de_um_elemento_na_stack();

    return 0;
}