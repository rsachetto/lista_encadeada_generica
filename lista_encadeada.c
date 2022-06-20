#include "lista_encadeada.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define LOWER(type) LOWER_ ## type
#define LOWER_INT int

#define COMMON_CELL_CREATION(l, x, type)                                       \
  celula *c = (celula *)nova_celula(type);                                     \
  do {                                                                         \
    assert(l);                                                                 \
    c->valor_##type = x;                                                       \
  } while (0)

#define COMMON_INSERT_END(l, x, type)                                          \
  do {                                                                         \
    COMMON_CELL_CREATION(l, x, type);                                          \
    inserir_celula_no_fim(l, c);                                               \
  } while (0)

#define COMMON_INSERT_BEGIN(l, x, type)                                        \
  do {                                                                         \
    COMMON_CELL_CREATION(l, x, type);                                          \
    inserir_celula_no_inicio(l, c);                                            \
  } while (0)

static celula* nova_celula(tipo_celula tipo) {
    celula *c = (celula *) malloc(sizeof(celula));
    c->tipo = tipo;
    c->proximo = NULL;
    c->anterior = NULL;
    return c;
}

static void inserir_celula_no_fim(lista_encadeada *l, celula* c) {

    if(l->tamanho == 0) {
        l->primeiro = c;
    }
    else {
        l->ultimo->proximo = c;
        c->anterior = l->ultimo;
    }

    l->ultimo = c;
    l->tamanho++;

}

static void inserir_celula_no_inicio(lista_encadeada *l, celula* c) {

    if(l->tamanho == 0) {
        l->ultimo = c;
    }
    else {
        celula *aux = l->primeiro;
        c->proximo = aux;
        aux->anterior = c;
    }

    l->primeiro = c;
    l->tamanho++;

}


lista_encadeada *nova_lista() {
    lista_encadeada *l = (lista_encadeada*) calloc(1, sizeof(lista_encadeada));
    return l;
}

void imprimir_lista(lista_encadeada *l) {

    celula *c = l->primeiro;

    while(c) {
        switch(c->tipo) {
            case INT:
                printf("%d\n", c->valor_INT);
                break;
            case PINT:
                printf("%p\n", c->valor_PINT);
                break;
            case LONG:
                printf("%ld\n", c->valor_LONG);
                break;
            case PLONG:
                printf("%p\n", c->valor_PLONG);
                break;
             case SHORT:
                printf("%d\n", c->valor_SHORT);
                break;
            case PSHORT:
                printf("%p\n", c->valor_PSHORT);
                break;
            case FLOAT:
                printf("%f\n", c->valor_FLOAT);
                break;
            case PFLOAT:
                printf("%p\n", c->valor_PFLOAT);
                break;
            case DOUBLE:
                printf("%lf\n", c->valor_DOUBLE);
                break;
            case PDOUBLE:
                printf("%p\n", c->valor_PDOUBLE);
                break;
            case CHAR:
                printf("%c\n", c->valor_CHAR);
                break;
            case PCHAR:
                printf("%s\n", c->valor_PCHAR);
                break;
            case PVOID:
                printf("%p\n", c->valor_PVOID);
                break;
        }
        c = c->proximo;
    }
}



void remover_do_fim(lista_encadeada *l) {

    if(l->tamanho == 0)
        return;

    celula *r = l->ultimo;
    l->ultimo = l->ultimo->anterior;

    if(l->ultimo != NULL)
        l->ultimo->proximo = NULL;

    free(r);

    l->tamanho--;

    if(l->tamanho == 0)
        l->primeiro = NULL;

}

void inserir_no_fim_int(lista_encadeada *l, int x) {
    COMMON_INSERT_END(l, x, INT);
}

void inserir_no_fim_pint(lista_encadeada *l, int* x) {
    COMMON_INSERT_END(l, x, PINT);
}
void inserir_no_fim_float(lista_encadeada *l, float x) {
    COMMON_INSERT_END(l, x, FLOAT);
}
void inserir_no_fim_pfloat(lista_encadeada *l, float* x) {
    COMMON_INSERT_END(l, x, PFLOAT);
}
void inserir_no_fim_double(lista_encadeada *l, double x) {
    COMMON_INSERT_END(l, x, DOUBLE);
}

void inserir_no_fim_pdouble(lista_encadeada *l, double* x) {
    COMMON_INSERT_END(l, x, PDOUBLE);
}
void inserir_no_fim_char(lista_encadeada *l, char x) {
    COMMON_INSERT_END(l, x, CHAR);
}

void inserir_no_fim_pchar(lista_encadeada *l, char* x) {
    COMMON_INSERT_END(l, x, PCHAR);
}
void inserir_no_fim_long(lista_encadeada *l, long x) {
    COMMON_INSERT_END(l, x, LONG);
}
void inserir_no_fim_plong(lista_encadeada *l, long * x) {
    COMMON_INSERT_END(l, x, PLONG);
}
void inserir_no_fim_short(lista_encadeada *l, short x) {
    COMMON_INSERT_END(l, x, SHORT);
}
void inserir_no_fim_pshort(lista_encadeada *l, short * x) {
    COMMON_INSERT_END(l, x, PSHORT);
}
void inserir_no_fim_pvoid(lista_encadeada *l, void* x) {
    COMMON_INSERT_END(l, x, PVOID);
}


void inserir_no_inicio_int(lista_encadeada *l, int x) {
    COMMON_INSERT_BEGIN(l, x, INT);
}

void inserir_no_inicio_pint(lista_encadeada *l, int* x) {
    COMMON_INSERT_BEGIN(l, x, PINT);
}
void inserir_no_inicio_float(lista_encadeada *l, float x) {
    COMMON_INSERT_BEGIN(l, x, FLOAT);
}
void inserir_no_inicio_pfloat(lista_encadeada *l, float* x) {
    COMMON_INSERT_BEGIN(l, x, PFLOAT);
}
void inserir_no_inicio_double(lista_encadeada *l, double x) {
    COMMON_INSERT_BEGIN(l, x, DOUBLE);
}

void inserir_no_inicio_pdouble(lista_encadeada *l, double* x) {
    COMMON_INSERT_BEGIN(l, x, PDOUBLE);
}
void inserir_no_inicio_char(lista_encadeada *l, char x) {
    COMMON_INSERT_BEGIN(l, x, CHAR);
}

void inserir_no_inicio_pchar(lista_encadeada *l, char* x) {
    COMMON_INSERT_BEGIN(l, x, PCHAR);
}
void inserir_no_inicio_long(lista_encadeada *l, long x) {
    COMMON_INSERT_BEGIN(l, x, LONG);
}
void inserir_no_inicio_plong(lista_encadeada *l, long * x) {
    COMMON_INSERT_BEGIN(l, x, PLONG);
}
void inserir_no_inicio_short(lista_encadeada *l, short x) {
    COMMON_INSERT_BEGIN(l, x, SHORT);
}
void inserir_no_inicio_pshort(lista_encadeada *l, short * x) {
    COMMON_INSERT_BEGIN(l, x, PSHORT);
}
void inserir_no_inicio_pvoid(lista_encadeada *l, void* x) {
    COMMON_INSERT_BEGIN(l, x, PVOID);
}

void nao_suportado(lista_encadeada *l, void *x) {
    (void)l;
    (void)x;
    fprintf(stderr, "Tipo nao suportado!\n");
}
