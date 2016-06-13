#include <stdlib.h>
#include <string.h>

#include "contexto.h"
#include "poligonos.h"
#include "helpers/lista_vertices.h"
#include "helpers/interseccao.h"

ListaVertices *RecortarContraPlano(int plano_recorte, ListaVertices *entrada);

// Sutherland–Hodgman
Poligono *RecortarParaAreaDeVisao(Poligono *poligono) {
    ListaVertices *entrada;
    ListaVertices *saida = lista_vazia(poligono->numero_vertices);

    int i;
    // copiar vertices do poligono para a lista de saída
    for (i = 0; i < poligono->numero_vertices; ++i) {
        double *vi = VerticeDoPoligono(poligono, i);
        saida->vertices[i + X] = vi[X];
        saida->vertices[i + Y] = vi[Y];
        saida->vertices[i + Z] = vi[Z];
    }

    int plano_recorte;
    for (plano_recorte = ESQUERDA; plano_recorte <= LONGE; ++plano_recorte) {
        entrada = saida;
        saida = RecortarContraPlano(plano_recorte, entrada);
    }

    Poligono *resultante = CriarPoligonoDeListaDeVertices(saida);
    LiberarLista(&saida);

    return resultante;
}

ListaVertices *RecortarContraPlano(int plano_recorte, ListaVertices *entrada) {
    int i;
    int tamanho_entrada = entrada->indice;
    ListaVertices *saida = lista_vazia(tamanho_entrada);

    double *P1 = &entrada->vertices[tamanho_entrada - 1];
    for (i = 0; i < tamanho_entrada; ++i) {
        double *P2 = &entrada->vertices[i];

        if (dentro_plano(plano_recorte, P2)) {
            if (dentro_plano(plano_recorte, P1)) {
                double *ponto_interseccao =  interseccao(plano_recorte, P1, P2);
                inserir_vertice(saida, ponto_interseccao);
                free(ponto_interseccao);
            }
            inserir_vertice(saida, P2);
        }
        else if (dentro_plano(plano_recorte, P1)) {
            double *ponto_interseccao =  interseccao(plano_recorte, P1, P2);
            inserir_vertice(saida, interseccao(plano_recorte, P1, P2));
            free(ponto_interseccao);
        }
        P1 = P2;
    }

    LiberarLista(&entrada);
    return saida;
}
