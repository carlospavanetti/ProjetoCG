#include <stdio.h>
#include <stdlib.h>
#include "contexto.h"
#include "helpers/interseccao.h"

bool dentro_plano(int plano, double *ponto) {
    return SINAL(plano) * ponto[COORDENADA(plano)] <= 1;
}

double *interseccao(int plano, double *a, double *b) {
    int i;
    double delta[3];
    double *ponto_interseccao = (double *) malloc(4 * sizeof(double));
    ponto_interseccao[W] = 1.0;

    for (i = X; i <= Z; ++i)
        delta[i] = b[i] - a[i];

    int eixo = COORDENADA(plano);
    int fator = SINAL(plano) - a[eixo]; // xp - xa

    for (i = X; i <= Z; ++i) {
        if (eixo == i) continue;
        // W = (delta W / delta X) * (X - Xa) + Wa
        ponto_interseccao[i] = (delta[i] * fator / delta[eixo]) + a[i];
    }

    printf("%d> A: %.2f %.2f %.2f\n", plano, a[X], a[Y], a[Z]);
    printf("%d> B: %.2f %.2f %.2f\n", plano, b[X], b[Y], b[Z]);
    return ponto_interseccao;
}

// -x < +1 e : x > -1
//  x < +1 d
