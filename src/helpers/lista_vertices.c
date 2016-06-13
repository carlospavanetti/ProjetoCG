#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "contexto.h"
#include "poligonos.h"
#include "helpers/lista_vertices.h"

ListaVertices *lista_vazia(int quantidade) {
    ListaVertices *V = (ListaVertices *) malloc(sizeof(ListaVertices));

    V->indice = 0;
    V->capacidade = quantidade;
    V->vertices = (double *) malloc(4 * quantidade * sizeof(double));

    int i;
    for (i = 0; i < 4 * quantidade; ++i)
        V->vertices[i] = NAN;

    return V;
}

void LiberarLista(ListaVertices **L) {
    ListaVertices *ref = *L;
    free(ref->vertices);
    free(ref);
    *L = NULL;
}

void inserir_vertice(ListaVertices *lista, double *vertice) {
    int indice = 4 * lista->indice;
    // if (indice > lista->capacidade) XXX exception!!!

    lista->vertices[indice + X] = vertice[X];
    lista->vertices[indice + Y] = vertice[Y];
    lista->vertices[indice + Z] = vertice[Z];
    lista->vertices[indice + W] = vertice[W];

    ++lista->indice;
}

Poligono *CriarPoligonoDeListaDeVertices(ListaVertices *lista) {
    Poligono *P = (Poligono *) malloc(sizeof(Poligono));

    P->numero_vertices = lista->indice;
    int tamanho_em_memoria = 4 * P->numero_vertices * sizeof(double);
    P->endereco_vertices = (double *) malloc(tamanho_em_memoria);
    memcpy(P->endereco_vertices, lista->vertices, tamanho_em_memoria);

    int i;
    P->indice_vertices = (int *) malloc(P->numero_vertices * sizeof(int));
    for (i = 0; i < P->numero_vertices; ++i)
        P->indice_vertices[i] = i;

    return P;
}
