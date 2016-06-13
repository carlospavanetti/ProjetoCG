#include "matriz.h"
#include "transformacoes.h"
#include "projecoes.h"
#include "contexto.h"
#include "pipeline.h"

#include <stdio.h>
#include <stdlib.h>

Poligono *poligono_teste(double *vertices) {
    Poligono *P = (Poligono *) malloc(sizeof(Poligono));

    P->numero_vertices = 3;
    P->endereco_vertices = vertices;

    int i;
    P->indice_vertices = (int *) malloc(P->numero_vertices * sizeof(int));
    for (i = 0; i < P->numero_vertices; ++i)
        P->indice_vertices[i] = i;
    return P;
}

int main() {
    InicializarContexto(0);
    double vertices[] = {
        -2.0, -2.0, 1,
        2.0, 2.0, 1,
        0.0, -0.5, 1
    };

    SelecionarMatrizCorrente(MATRIZ_MODELO);
    // AplicarRotacao(45, Z);
    // AplicarEscala(1.4142, 1.4142, 1);

    SelecionarMatrizCorrente(MATRIZ_PROJECAO);
    AplicarProjecaoPerspectivaAspecto(90, 1, 1, 2);
    // AplicarProjecaoPerspectivaVolume(-1, 1, -1, 1, 1, 2);

    double *transformados = TransformarVertices(vertices, 4);
    double *projetados = ProjetarVertices(transformados, 4);
    int i, j;

    // for (i = 0; i < 4; i++) {
    //     for (j = 0; j < 4; j++)
    //         printf("%.3f ", transformados[i * 4 + j]);
    //     printf("\n");
    // }
    // printf("\n");

    // for (i = 0; i < 4; i++) {
    //     for (j = 0; j < 4; j++)
    //         printf("%.3f ", projetados[i * 4 + j]);
    //     printf("\n");
    // }

    // Poligono *p = poligono_teste(projetados);
    // Poligono *r = RecortarParaAreaDeVisao(p);

    // for (i = 0; i < r->numero_vertices; ++i) {
    //     double *v = VerticeDoPoligono(r, i);
    //     printf("%.2f %.2f %.2f\n", v[X], v[Y], v[Z]);
    // }

    free(transformados);
    free(projetados);
}
