#include "matriz.h"
#include "transformacoes.h"
#include "projecoes.h"
#include "contexto.h"
#include "pipeline.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    InicializarContexto(0);
    double vertices[] = {
        1.0, 0.0, 1.0,
        0.0, 2.0, 1.0,
        0.0, 0.0, 0.5,
        2.0, 0.0, 0.5
    };

    SelecionarMatrizCorrente(MATRIZ_MODELO);
    AplicarRotacao(45, Z);
    AplicarEscala(1.4142, 1.4142, 1);

    SelecionarMatrizCorrente(MATRIZ_PROJECAO);
    AplicarProjecaoPerspectivaAspecto(90, 1, 1, 2);
    // AplicarProjecaoPerspectivaVolume(-1, 1, -1, 1, 1, 2);

    double *transformados = TransformarVertices(vertices, 4);
    double *projetados = ProjetarVertices(transformados, 4);
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            printf("%.3f ", transformados[i * 4 + j]);
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            printf("%.3f ", projetados[i * 4 + j]);
        printf("\n");
    }

    free(transformados);
    free(projetados);
}
