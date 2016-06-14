#include <stdio.h>

#include "contexto.h"
#include "helpers/preparar_rasterizacao.h"

#define LINHA_HORIZONTAL(A, B) ((A)[Y] == (B)[Y])
DadosAresta **InicializaGET(int *vertices, int quantidade) {
    DadosAresta **GET = calloc(2048, sizeof(DadosAresta *));

    int *P1 = &vertices[(quantidade - 1) << 2];

    int i;
    for (i = 0; i < quantidade << 2; i += 4) {
        int * P2 = &vertices[i];

        if (LINHA_HORIZONTAL(P1, P2)) {
            // preparando próxima aresta
            P1 = P2;
            // não processaremos a atual
            continue;
        }

        int y_min, y_max, xi, zi, dx, dy, dz;
        if (P1[Y] > P2[Y]) {
            y_min = P2[Y];
            y_max = P1[Y];
            xi = P2[X];
            zi = P2[Z];

            dx = P1[X] - xi;
            dz = P1[Z] - zi;
        } else {
            y_min = P1[Y];
            y_max = P2[Y];
            xi = P1[X];
            zi = P1[Z];

            dx = P2[X] - xi;
            dz = P2[Z] - zi;
        }
        dy = y_max - y_min;

        InserirRegistroAresta(&GET[y_min], y_max, xi, zi, dx, dy, dz);

        P1 = P2;
    }

    return GET;
}

int *PrepararPoligonoParaNovoViewport(Poligono *poligono) {
    int tamanho_em_memoria = 4 * sizeof(int) * poligono->numero_vertices; // xyz
    int *sequencia_vertices = (int *) malloc(tamanho_em_memoria);

    int i, j;
    for (i = 0; i < poligono->numero_vertices; ++i) {
        double * V = VerticeDoPoligono(poligono, i);

        for (j = X; j <= Z; ++j)
            sequencia_vertices[(i << 2) + j] = (1024 * V[j]) + 1024;
        sequencia_vertices[(i << 2) + W] = 1;
        printf("%d %d %d\n", sequencia_vertices[(i << 2) + X], sequencia_vertices[(i << 2) + Y], sequencia_vertices[(i << 2) + Z]);
    }


    return sequencia_vertices;
}
