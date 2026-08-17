#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../lista_encadeada.h"

// Suite 1: Criação e Destruição
TestSuite(criacao_destruicao);

Test(criacao_destruicao, nova_lista) {
    lista_encadeada *l = nova_lista();
    cr_assert_not_null(l, "nova_lista deve retornar um ponteiro valido");
    cr_assert_eq(l->tamanho, 0, "Tamanho inicial deve ser 0");
    cr_assert_null(l->primeiro, "Primeiro elemento deve ser NULL");
    cr_assert_null(l->ultimo, "Ultimo elemento deve ser NULL");
    destruir_lista(l);
}

Test(criacao_destruicao, limpar_lista) {
    lista_encadeada *l = nova_lista();
    inserir_no_fim(l, 10);
    inserir_no_fim(l, 20);
    cr_assert_eq(l->tamanho, 2);
    limpar_lista(l);
    cr_assert_eq(l->tamanho, 0);
    cr_assert_null(l->primeiro);
    cr_assert_null(l->ultimo);
    destruir_lista(l);
}

Test(criacao_destruicao, ponteiros_nulos) {
    limpar_lista(NULL);
    destruir_lista(NULL);
    remover_do_fim(NULL);
    remover_do_inicio(NULL);
    imprimir_lista(NULL);
}

// Suite 2: Inserção no Fim (Tipos variados)
TestSuite(insercao_fim);

Test(insercao_fim, tipos_primitivos) {
    lista_encadeada *l = nova_lista();
    int val_int = 42;
    float val_float = 3.14f;
    double val_double = 2.71828;
    char val_char = 'Z';
    long val_long = 123456789L;
    short val_short = 32000;

    inserir_no_fim(l, val_int);
    inserir_no_fim(l, val_float);
    inserir_no_fim(l, val_double);
    inserir_no_fim(l, val_char);
    inserir_no_fim(l, 'X');       // Literais de char
    inserir_no_fim(l, ('Y'));     // Parenteses
    inserir_no_fim(l, val_long);
    inserir_no_fim(l, val_short);

    cr_assert_eq(l->tamanho, 8);

    celula *c = l->primeiro;
    cr_assert_eq(c->tipo, INT);
    cr_assert_eq(c->valor_INT, 42);

    c = c->proximo;
    cr_assert_eq(c->tipo, FLOAT);
    cr_assert_float_eq(c->valor_FLOAT, 3.14f, 1e-5);

    c = c->proximo;
    cr_assert_eq(c->tipo, DOUBLE);
    cr_assert_float_eq(c->valor_DOUBLE, 2.71828, 1e-5);

    c = c->proximo;
    cr_assert_eq(c->tipo, CHAR);
    cr_assert_eq(c->valor_CHAR, 'Z');

    c = c->proximo;
    cr_assert_eq(c->tipo, CHAR);
    cr_assert_eq(c->valor_CHAR, 'X');

    c = c->proximo;
    cr_assert_eq(c->tipo, CHAR);
    cr_assert_eq(c->valor_CHAR, 'Y');

    c = c->proximo;
    cr_assert_eq(c->tipo, LONG);
    cr_assert_eq(c->valor_LONG, 123456789L);

    c = c->proximo;
    cr_assert_eq(c->tipo, SHORT);
    cr_assert_eq(c->valor_SHORT, 32000);

    destruir_lista(l);
}

Test(insercao_fim, ponteiros_e_strings) {
    lista_encadeada *l = nova_lista();
    int x = 100;
    const char *str_const = "Constante";
    char str_arr[] = "Array";
    void *ptr_void = (void*)0xDEADBEEF;

    inserir_no_fim(l, &x);
    inserir_no_fim(l, "Literal String");
    inserir_no_fim(l, str_const);
    inserir_no_fim(l, str_arr);
    inserir_no_fim(l, ptr_void);

    cr_assert_eq(l->tamanho, 5);

    celula *c = l->primeiro;
    cr_assert_eq(c->tipo, PINT);
    cr_assert_eq(c->valor_PINT, &x);

    c = c->proximo;
    cr_assert_eq(c->tipo, PCHAR);
    cr_assert_str_eq(c->valor_PCHAR, "Literal String");

    c = c->proximo;
    cr_assert_eq(c->tipo, PCHAR);
    cr_assert_str_eq(c->valor_PCHAR, "Constante");

    c = c->proximo;
    cr_assert_eq(c->tipo, PCHAR);
    cr_assert_str_eq(c->valor_PCHAR, "Array");

    c = c->proximo;
    cr_assert_eq(c->tipo, PVOID);
    cr_assert_eq(c->valor_PVOID, ptr_void);

    destruir_lista(l);
}

// Suite 3: Inserção no Inicio
TestSuite(insercao_inicio);

Test(insercao_inicio, ordem_elementos) {
    lista_encadeada *l = nova_lista();
    inserir_no_inicio(l, 10);
    inserir_no_inicio(l, 20);
    inserir_no_inicio(l, 'A');

    cr_assert_eq(l->tamanho, 3);
    cr_assert_eq(l->primeiro->tipo, CHAR);
    cr_assert_eq(l->primeiro->valor_CHAR, 'A');

    cr_assert_eq(l->ultimo->tipo, INT);
    cr_assert_eq(l->ultimo->valor_INT, 10);

    destruir_lista(l);
}

// Suite 4: Remoção (Fim e Inicio)
TestSuite(remocao);

Test(remocao, remover_do_fim) {
    lista_encadeada *l = nova_lista();
    inserir_no_fim(l, 1);
    inserir_no_fim(l, 2);
    inserir_no_fim(l, 3);

    remover_do_fim(l);
    cr_assert_eq(l->tamanho, 2);
    cr_assert_eq(l->ultimo->valor_INT, 2);

    remover_do_fim(l);
    remover_do_fim(l);
    cr_assert_eq(l->tamanho, 0);
    cr_assert_null(l->primeiro);
    cr_assert_null(l->ultimo);

    remover_do_fim(l);
    cr_assert_eq(l->tamanho, 0);

    destruir_lista(l);
}

Test(remocao, remover_do_inicio) {
    lista_encadeada *l = nova_lista();
    inserir_no_fim(l, 1);
    inserir_no_fim(l, 2);
    inserir_no_fim(l, 3);

    remover_do_inicio(l);
    cr_assert_eq(l->tamanho, 2);
    cr_assert_eq(l->primeiro->valor_INT, 2);

    remover_do_inicio(l);
    remover_do_inicio(l);
    cr_assert_eq(l->tamanho, 0);
    cr_assert_null(l->primeiro);
    cr_assert_null(l->ultimo);

    remover_do_inicio(l);
    cr_assert_eq(l->tamanho, 0);

    destruir_lista(l);
}

// Suite 5: Macro MAP
TestSuite(macro_map);

static int contador_map = 0;
static void fn_contar(celula *c) {
    (void)c;
    contador_map++;
}

Test(macro_map, iteracao) {
    lista_encadeada *l = nova_lista();
    inserir_no_fim(l, 1);
    inserir_no_fim(l, 2);
    inserir_no_fim(l, 3);

    contador_map = 0;
    MAP(l, fn_contar);
    cr_assert_eq(contador_map, 3);

    destruir_lista(l);
}

// Suite 6: Impressão da Lista (saída via stdout)
TestSuite(impressao);

static void redirect_all_stdout(void) {
    cr_redirect_stdout();
}

Test(impressao, fluxo_saida, .init = redirect_all_stdout) {
    lista_encadeada *l = nova_lista();
    inserir_no_fim(l, 100);
    inserir_no_fim(l, 'Z');
    inserir_no_fim(l, "Teste");

    imprimir_lista(l);

    fflush(stdout);
    cr_assert_stdout_eq_str("100\nZ\nTeste\n");

    destruir_lista(l);
}
