#include <math.h>
#include <stdlib.h>

#include "contexto.h"
#include "poligonos.h"

typedef struct {
    double *vertices;
    int indice;
    int capacidade;
} ListaVertices;

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

int dentro_aresta(int i, double *p1) {
    return 1;
}

double *interseccao(int i, double *a, double *b) {
    return NULL;
}

Poligono *RecortarParaAreaDeVisaoB(Poligono *poligono) {
    ListaVertices *lista_entrada;
    ListaVertices *lista_saida = lista_vazia(poligono->numero_vertices);

    int i;
    // copiar vertices do poligono para a lista de saída
    for (i = 0; i < poligono->numero_vertices; ++i) {
        double *vi = VerticeDoPoligono(poligono, i);
        lista_saida->vertices[i + X] = vi[X];
        lista_saida->vertices[i + Y] = vi[Y];
        lista_saida->vertices[i + Z] = vi[Z];
    }

    // for linha_recorte:
    int linha_recorte = 0;

    lista_entrada = lista_saida;
    int tamanho_entrada = lista_entrada->indice;
    lista_saida = lista_vazia(tamanho_entrada);

    double *P1 = &lista_entrada->vertices[tamanho_entrada - 1];
    for (i = 0; i < tamanho_entrada; ++i) {
        double *P2 = &lista_entrada->vertices[i];

        if (dentro_aresta(linha_recorte, P2)) {
            if (dentro_aresta(linha_recorte, P1)) {
                inserir_vertice(lista_saida, interseccao(linha_recorte, P1, P2));
            }
            inserir_vertice(lista_saida, P2);
        }
        else if (dentro_aresta(linha_recorte, P1))
            inserir_vertice(lista_saida, interseccao(linha_recorte, P1, P2));
        P1 = P2;
    }
    LiberarLista(&lista_entrada);

    Poligono *resultante = NULL;
    // resultante <- lista_saida;

    return resultante;
}

double *VerticeDoPoligono(Poligono *p, int indice) {
   if (p == NULL)
       return NULL;
   return p->endereco_vertices + 4 * p->indice_vertices[indice];
}
