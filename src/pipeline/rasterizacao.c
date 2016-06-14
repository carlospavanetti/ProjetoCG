#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "contexto.h"
#include "poligonos.h"
#include "helpers/lista_linhas.h"

ListaLinhas *RasterizarPoligono(Poligono *arestas) {
    // viewport [-1, 1] => [-1024, 1024] => [0, 2048]
    // P1 = ultimo_ponto;
    // for (reta in poligono)
    //     adicione reta a linha adequada da AET;

    DadosAresta **GET = calloc(2048, sizeof(DadosAresta *));

    InsertirRegistroAresta(&GET[3], 10, 20, 1, 1);
    InsertirRegistroAresta(&GET[3], 12, 24, 2, 2);
    InsertirRegistroAresta(&GET[3], 24, 21, 3, 2);
    InsertirRegistroAresta(&GET[3], 36, 26, 2, 4);
    InsertirRegistroAresta(&GET[3], 48, 36, 5, 5);

    DadosAresta *ref = GET[3];
    while(ref != NULL) {
        printf("%d %d %d %d\n", ref->y_max, ref->x_inicial, ref->dx, ref->dy);
        ref = ref->proxima;
    }

    LiberarTabelaArestas(GET);
    return NULL;
}
//
// #define LINHA_HORIZONTAL(A, B) ((A)[Y] == (B)[Y])
// void InicializaGET(int *vertices, int quantidade) {
//     DadosAresta **GET = calloc(2048, sizeof(DadosAresta *));
//
//     int *P1 = &vertices[(quantidade - 1) << 2];
//
//     int i;
//     for (i = 0; i < quantidade << 2; i += 4) {
//         int * P2 = &vertices[i];
//
//         if (LINHA_HORIZONTAL(P1, P2)) {
//             // preparando próxima aresta
//             P1 = P2;
//             // não processaremos a atual
//             continue;
//         }
//
//         int y_min, y_max, x_inicial, dx, dy;
//         if (P1[Y] > P2[Y]) {
//             y_min = P2[Y];
//             y_max = P1[Y];
//             x_inicial = P2[X];
//
//             dx = P1[X] - x_inicial;
//         } else {
//             y_min = P1[Y];
//             y_max = P2[Y];
//             x_inicial = P1[X];
//
//             dx = P2[X] - x_inicial;
//         }
//         dy = y_max - y_min;
//
//         InsertirRegistroAresta(&GET[y_min], y_max, x_inicial, dx, dy);
//
//         P1 = P2;
//     }
// }
//
// int *PrepararPoligonoParaNovoViewport(Poligono *poligono) {
//     int tamanho_em_memoria = 4 * sizeof(int) * poligono->numero_vertices; // xyz
//     int *sequencia_vertices = (int *) malloc(tamanho_em_memoria);
//
//     int i, j;
//     for (i = 0; i < poligono->numero_vertices; ++i) {
//         double * V = VerticeDoPoligono(poligono, i);
//
//         for (j = X; j <= Z; ++j)
//             sequencia_vertices[(i << 2) + j] = (1024 * V[j]) + 1024;
//         sequencia_vertices[(i << 2) + W] = 1;
//     }
//
//     return sequencia_vertices;
// }
