#include "matriz.h"
#include "contexto.h"

#include <stdlib.h>

double *ProjetarVertices(double *vertices, int quantidade) {
    double *projetados;
    Matriz *MP = MatrizProjecao();

    projetados = (double *) malloc(4 * quantidade * sizeof(double));

    int v, _4v, i, j;
    for (v = 0; v < quantidade; v++) {
        _4v = v << 2;

        for (i = 0; i < 4; ++i) {
            projetados[_4v + i] = 0;
            for (j = 0; j < 4; ++j)
                projetados[_4v + i] += em(MP, i, j) * vertices[_4v + j];
        }
        projetados[_4v + 3] = 1;
    }

    return projetados;
}
