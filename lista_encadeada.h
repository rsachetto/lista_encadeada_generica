#ifndef __LISTA_ENCADEADA_H
#define __LISTA_ENCADEADA_H

#define is_char_literal(c) (#c[0] == '\'')

#define inserir_no_fim(l, X) \
is_char_literal(X) ? inserir_no_fim_char(l,X) : \
_Generic((X),\
int: inserir_no_fim_int,\
int*: inserir_no_fim_pint,\
float: inserir_no_fim_float,\
float*: inserir_no_fim_pfloat,\
double: inserir_no_fim_double,\
double*: inserir_no_fim_pdouble,\
char: inserir_no_fim_char,\
char*: inserir_no_fim_pchar,\
long: inserir_no_fim_long,\
long*: inserir_no_fim_plong,\
short: inserir_no_fim_short,\
short*: inserir_no_fim_pshort,\
void*: inserir_no_fim_pvoid,\
default: nao_suportado\
)(l, X)

#define inserir_no_inicio(l, X) \
is_char_literal(X) ? inserir_no_inicio_char(l,X) : \
_Generic((X),\
int: inserir_no_inicio_int,\
int*: inserir_no_inicio_pint,\
float: inserir_no_inicio_float,\
float*: inserir_no_inicio_pfloat,\
double: inserir_no_inicio_double,\
double*: inserir_no_inicio_pdouble,\
char: inserir_no_inicio_char,\
char*: inserir_no_inicio_pchar,\
long: inserir_no_inicio_long,\
long*: inserir_no_inicio_plong,\
short: inserir_no_inicio_short,\
short*: inserir_no_inicio_pshort,\
void*: inserir_no_inicio_pvoid,\
default: nao_suportado\
)(l, X)


#define MAP(l, fn)                                                             \
  do {                                                                         \
    celula *c = l->primeiro;                                                   \
    while (c) {                                                                \
      fn(c);                                                                   \
      c = c->proximo;                                                          \
    }                                                                          \
  } while (0)


typedef enum tipo_celula_t {
    INT,
    PINT,
    FLOAT,
    PFLOAT,
    DOUBLE,
    PDOUBLE,
    CHAR,
    PCHAR,
    LONG,
    PLONG,
    SHORT,
    PSHORT,
    PVOID

} tipo_celula;

typedef struct celula_t {

    tipo_celula tipo;

    union {
        int valor_int;
        int *valor_pint;
        float valor_float;
        float *valor_pfloat;
        double valor_double;
        double *valor_pdouble;
        char valor_char;
        char *valor_pchar;
        long valor_long;
        long *valor_plong;
        short valor_short;
        short *valor_pshort;
        void *valor_pvoid;
    };

    struct celula_t *proximo;
    struct celula_t *anterior;

} celula;

typedef struct lista_encadeada_t {
    celula *primeiro;
    celula *ultimo;
    unsigned long tamanho;
} lista_encadeada;

lista_encadeada *nova_lista();
void inserir_no_fim_int(lista_encadeada *l, int x);
void inserir_no_fim_pint(lista_encadeada *l, int* x);
void inserir_no_fim_float(lista_encadeada *l, float x);
void inserir_no_fim_pfloat(lista_encadeada *l, float* x);
void inserir_no_fim_double(lista_encadeada *l, double x);
void inserir_no_fim_pdouble(lista_encadeada *l, double* x);
void inserir_no_fim_char(lista_encadeada *l, char x);
void inserir_no_fim_pchar(lista_encadeada *l, char* x);
void inserir_no_fim_long(lista_encadeada *l, long x);
void inserir_no_fim_plong(lista_encadeada *l, long * x);
void inserir_no_fim_short(lista_encadeada *l, short x);
void inserir_no_fim_pshort(lista_encadeada *l, short * x);
void inserir_no_fim_pvoid(lista_encadeada *l, void* x);

void inserir_no_inicio_int(lista_encadeada *l, int x);
void inserir_no_inicio_pint(lista_encadeada *l, int* x);
void inserir_no_inicio_float(lista_encadeada *l, float x);
void inserir_no_inicio_pfloat(lista_encadeada *l, float* x);
void inserir_no_inicio_double(lista_encadeada *l, double x);
void inserir_no_inicio_pdouble(lista_encadeada *l, double* x);
void inserir_no_inicio_char(lista_encadeada *l, char x);
void inserir_no_inicio_pchar(lista_encadeada *l, char* x);
void inserir_no_inicio_long(lista_encadeada *l, long x);
void inserir_no_inicio_plong(lista_encadeada *l, long * x);
void inserir_no_inicio_short(lista_encadeada *l, short x);
void inserir_no_inicio_pshort(lista_encadeada *l, short * x);
void inserir_no_inicio_pvoid(lista_encadeada *l, void* x);



void imprimir_lista(lista_encadeada *l);
void remover_do_fim(lista_encadeada *l);
void nao_suportado(lista_encadeada *l, void* x);


#endif /* __LISTA_ENCADEADA_H */
