#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "contexto.h"

double *TransformarVertices(double *vertices, int quantidade);

void DesenharTriangulos(double *vertices, int quantidade) {
    double *vertices_transformados = TransformarVertices(vertices, quantidade);

    int i;
    for (i = 0; i < 4 * quantidade / 3; i++)
        printf("%.2f ", vertices_transformados[i]);
    printf("\n");
}

double *TransformarVertices(double *vertices, int quantidade) {
    double *vertices_transformados;
    Matriz *MVM = Modelo();

    int tamanho_array = 4 * quantidade / 3;
    vertices_transformados = (double *) malloc(tamanho_array * sizeof(double));

    int v, i, j;
    for (v = 0; v < quantidade; v ++) {
        for (i = 0; i < 3; ++i) {
            vertices_transformados[4*v + i] = 0;
            for (j = 0; j < 3; ++j)
                vertices_transformados[4*v + i] += em(MVM, i, j) * vertices[3*v + j];
            vertices_transformados[v + i] += em(MVM, i, 3);
        }
        vertices_transformados[4*v + 3] = 1;
    }

    return vertices_transformados;
}
