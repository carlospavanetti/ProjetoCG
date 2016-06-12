#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "contexto.h"
#include "poligonos.h"
#include "lista_vertices.h"

ListaVertices *lista_vazia(int quantidade) {
    ListaVertices *V = (ListaVertices *) malloc(sizeof(ListaVertices));

    V->indice = 0;
    V->capacidade = quantidade;
    V->vertices = (double *) malloc(3 * quantidade * sizeof(double));

    int i;
    for (i = 0; i < 3 * quantidade; ++i)
        V->vertices[i + X] = V->vertices[i + Y] = V->vertices[i + Z] = NAN;

    return V;
}

void LiberarLista(ListaVertices **L) {
    ListaVertices *ref = *L;
    free(ref->vertices);
    free(ref);
    *L = NULL;
}

void inserir_vertice(ListaVertices *lista, double *vertice) {
    int indice = lista->indice;
    // if (indice > lista->capacidade) XXX exception!!!

    lista->vertices[indice + X] = vertice[X];
    lista->vertices[indice + Y] = vertice[Y];
    lista->vertices[indice + Z] = vertice[Z];

    lista->indice = indice + 1;
}

Poligono *CriarPoligonoDeListaDeVertices(ListaVertices *lista) {
    Poligono *P = (Poligono *) malloc(sizeof(Poligono));

    int i;
    int tamanho_em_memoria = P->numero_vertices * sizeof(double);

    P->numero_vertices = lista->indice;
    P->endereco_vertices = (double *) malloc(tamanho_em_memoria);
    memcpy(P->endereco_vertices, lista->vertices, tamanho_em_memoria);

    P->indice_vertices = (int *) malloc(P->numero_vertices * sizeof(int));
    for (i = 0; i < P->numero_vertices; ++i)
        P->indice_vertices[i] = i;

    return P;
}
