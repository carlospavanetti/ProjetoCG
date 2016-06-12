#ifndef __LISTA_VERTICES_H__
#define __LISTA_VERTICES_H__

typedef struct {
    double *vertices;
    int indice;
    int capacidade;
} ListaVertices;

ListaVertices *lista_vazia(int quantidade);
void LiberarLista(ListaVertices **L);

void inserir_vertice(ListaVertices *lista, double *vertice);
Poligono *CriarPoligonoDeListaDeVertices(ListaVertices *lista);

#endif // __LISTA_VERTICES_H__
