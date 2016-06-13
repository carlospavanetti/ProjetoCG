#include <stdlib.h>
#include <string.h>

#include "contexto.h"
#include "poligonos.h"
#include "helpers/lista_vertices.h"
#include "helpers/interseccao.h"

Poligono *RecortarParaAreaDeVisao(Poligono *poligono) {
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

        if (dentro_plano(linha_recorte, P2)) {
            if (dentro_plano(linha_recorte, P1)) {
                double *ponto_interseccao =  interseccao(linha_recorte, P1, P2);
                inserir_vertice(lista_saida, ponto_interseccao);
                free(ponto_interseccao);
            }
            inserir_vertice(lista_saida, P2);
        }
        else if (dentro_plano(linha_recorte, P1)) {
            double *ponto_interseccao =  interseccao(linha_recorte, P1, P2);
            inserir_vertice(lista_saida, interseccao(linha_recorte, P1, P2));
            free(ponto_interseccao);
        }
        P1 = P2;
    }
    LiberarLista(&lista_entrada);

    Poligono *resultante = CriarPoligonoDeListaDeVertices(lista_saida);
    LiberarLista(&lista_saida);

    return resultante;
}
