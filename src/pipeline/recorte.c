#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "contexto.h"
#include "poligonos.h"
#include "helpers/lista_vertices.h"
#include "helpers/interseccao.h"

// Sutherland–Hodgman
ListaVertices *RecortarContraPlano(int plano_recorte, ListaVertices *entrada);

Poligono *RecortarParaAreaDeVisao(Poligono *poligono) {
    ListaVertices *saida = lista_vazia(poligono->numero_vertices);

    int i;
    // copiar vertices do poligono para a lista de saída
    for (i = 0; i < poligono->numero_vertices; ++i)
        inserir_vertice(saida, VerticeDoPoligono(poligono, i));

    // recortar contra cada plano da janela de visualizacao
    // saida <- recorte da ultima lista de vertices contra o ultimo plano
    int plano_recorte;
    for (plano_recorte = ESQUERDA; plano_recorte <= LONGE; ++plano_recorte)
        saida = RecortarContraPlano(plano_recorte, saida);

    Poligono *resultante = CriarPoligonoDeListaDeVertices(saida);
    LiberarLista(&saida);

    return resultante;
}

ListaVertices *RecortarContraPlano(int plano_recorte, ListaVertices *entrada) {
    int i;
    int tamanho_entrada = entrada->indice;
    // cada três vertices pode gerar quatro quando recortados contra um plano
    ListaVertices *saida = lista_vazia(4 * tamanho_entrada / 3);

    double *P1 = &entrada->vertices[4 * (tamanho_entrada - 1)];
    for (i = 0; i < tamanho_entrada; ++i) {
        double *P2 = &entrada->vertices[i << 2];
        if (P2[X] == NAN) break;

        if (dentro_plano(plano_recorte, P2)) {
            if (!dentro_plano(plano_recorte, P1)) {
                double *ponto_interseccao =  interseccao(plano_recorte, P1, P2);
                inserir_vertice(saida, ponto_interseccao);
                free(ponto_interseccao);
            }
            inserir_vertice(saida, P2);
        }
        else if (dentro_plano(plano_recorte, P1)) {
            double *ponto_interseccao =  interseccao(plano_recorte, P1, P2);
            inserir_vertice(saida, ponto_interseccao);
            free(ponto_interseccao);
        }
        P1 = P2;
    }

    LiberarLista(&entrada);
    return saida;
}
