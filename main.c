#include "lista_encadeada.h"
#include <stdlib.h>
#include <stdio.h>

#define N 5

int main() {
    lista_encadeada *l = nova_lista();

    for(int i = 0; i < N; i++) {
        char a = 'a'+i;
        inserir_no_fim(l, a);
        inserir_no_fim(l, 1.2*a);
    }

    imprimir_lista(l);

    for(int i = 0; i < N*2; i++) {
        remover_do_fim(l);
        printf("-----\n");
        imprimir_lista(l);
    }

    free(l);

}
