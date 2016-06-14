#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contexto.h"
#include "helpers/lista_linhas.h"

#define LINHAS_VIEWPORT (2048)

void InserirRegistroAresta(
    DadosAresta **lista,
    int y_max, int x_inicial, int z_inicial,
    int dx, int dy, int dz) {

    DadosAresta *novo_registro =
        NovoRegistroAresta(y_max, x_inicial, z_inicial, dx, dy, dz);

    if ((*lista) == NULL) {
        (*lista) = novo_registro;
        novo_registro->proxima = NULL;
        return;
    }

    DadosAresta *posicao = *lista;
    while (posicao->proxima != NULL) {
        posicao = posicao->proxima;
    }

    // novo_registro->proxima = posicao->proxima;
    // posicao->proxima = novo_registro;
    posicao->proxima = novo_registro;
    posicao->proxima->proxima = NULL;
    // *lista = novo_registro;
    // novo_registro->proxima = NULL;
    return;
}

DadosAresta *NovoRegistroAresta(
    int y_max, int x_inicial, int z_inicial,
    int dx, int dy, int dz) {
    DadosAresta *registro = (DadosAresta *) malloc(sizeof(DadosAresta));

    registro->y_max         = y_max;

    registro->x_inicial     = x_inicial;
    registro->x_inteiro     = x_inicial;
    registro->x_fracionario = 0;

    registro->z_inicial     = z_inicial;
    registro->z_inteiro     = z_inicial;
    registro->z_fracionario = 0;

    registro->dx            = dx;
    registro->dy            = dy;
    registro->dz            = dz;

    registro->proxima = NULL;

    return registro;
}

void LiberarTabelaArestas(DadosAresta **tabela) {
    int i;
    for (i = 0; i < LINHAS_VIEWPORT; i++) {
        DadosAresta *ref = tabela[i];
        DadosAresta *lixo;
        if (ref != NULL) {
            lixo = ref;
            // ref = ref->proxima;
            free(lixo);
        }
    }
    free(tabela);
}

void TransferirParaAET(DadosAresta **GET, DadosAresta **AET, int pos_y) {
    DadosAresta *lista = GET[pos_y];

    while (lista->proxima != NULL)
        lista = lista->proxima;

    lista->proxima = *AET; // Problema aqui!
    if (lista->proxima != NULL)
        lista->proxima->proxima = NULL;
    *AET = GET[pos_y];


    // AET = OrdenarAET(AET);
}

ListaLinhas *InicializarListaLinhas() {
    ListaLinhas *L = (ListaLinhas *) malloc(sizeof(ListaLinhas));

    L->capacidade = (1 << 16) - 1;
    L->dados = (Linha *) malloc(L->capacidade * sizeof(Linha));
    L->quantidade = 0;

    return L;
}

void TracarLinhas(DadosAresta **AET, int varredura_y, ListaLinhas *lista) {
    DadosAresta *aresta = *AET;
    // DadosAresta *anterior;
    // anterior = (DadosAresta *) malloc(sizeof(DadosAresta));
    // anterior->proxima = aresta;

    while (aresta != NULL) {
        Linha *linha = (Linha *) malloc(sizeof(Linha));
        linha->x_inicial = aresta->x_inicial;
        linha->x_final   = aresta->x_inteiro;
        linha->z_inicial = aresta->z_inicial;
        linha->z_final   = aresta->z_inteiro;
        linha->y = varredura_y;

        InserirLinha(lista, linha);

        aresta->x_fracionario += aresta->dx;
        aresta->z_fracionario += aresta->dz;

        while (aresta->x_fracionario > aresta->dy) {
            aresta->x_inteiro++;
            aresta->x_fracionario -= aresta->dy;
        }

        while (aresta->z_fracionario > aresta->dy) {
            aresta->z_inteiro++;
            aresta->z_fracionario -= aresta->dy;
        }

        // remover arestas que chegam ao fim
        // if (aresta->y_max == varredura_y + 1) {
        //     printf("%p\n", anterior);
        //     anterior->proxima = aresta->proxima;
        //     free(aresta);
        //     aresta = anterior->proxima;
        // }

        // anterior = aresta;
        aresta = aresta->proxima;
        free(linha);
    }
}

void InserirLinha(ListaLinhas *lista, Linha *linha) {
    // if (lista == NULL)
    if (lista->quantidade == lista->capacidade) {
        lista->capacidade = lista->capacidade << 1;
        lista->dados = realloc(lista->dados, lista->capacidade);
    }

    int index = lista->quantidade;

    lista->dados[index].y = linha->y;
    lista->dados[index].x_inicial = linha->x_inicial;
    lista->dados[index].x_final   = linha->x_final;
    lista->dados[index].z_inicial = linha->z_inicial;
    lista->dados[index].z_final   = linha->z_final;
    lista->quantidade++;
}
