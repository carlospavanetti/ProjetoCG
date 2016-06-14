#include <stdio.h>
#include <stdlib.h>
#include "helpers/lista_linhas.h"

void InsertirRegistroAresta(
    DadosAresta **lista,
    int y_max, int x_inicial,
    int dx, int dy) {

    DadosAresta *novo_registro = NovoRegistroAresta(y_max, x_inicial, dx, dy);

    if (*lista == NULL) {
        *lista = novo_registro;
        return;
    }

    DadosAresta *posicao = (*lista);
    while (posicao->proxima != NULL) {
        if (posicao->proxima->x_inicial > x_inicial)
            break;
        posicao = posicao->proxima;
    }

    if (posicao->proxima == NULL) {
        posicao->proxima = novo_registro;
        return;
    }

    novo_registro->proxima = posicao->proxima;
    posicao->proxima = novo_registro;
}

DadosAresta *NovoRegistroAresta(int y_max, int x_inicial, int dx, int dy) {
    DadosAresta *registro = (DadosAresta *) malloc(sizeof(DadosAresta));

    registro->y_max     = y_max;
    registro->x_inicial = x_inicial;
    registro->dx        = dx;
    registro->dy        = dy;

    registro->proxima = NULL;

    return registro;
}

void LiberarTabelaArestas(DadosAresta **tabela) {
    int i;
    for (i = 0; i < 2048; i++) {
        DadosAresta *ref = tabela[i];
        DadosAresta *lixo;
        while (ref != NULL) {
            lixo = ref;
            ref = ref->proxima;
            free(lixo);
        }
    }
    free(tabela);
}
