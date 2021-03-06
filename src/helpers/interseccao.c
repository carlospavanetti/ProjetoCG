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
    double fator = SINAL(plano) - a[eixo]; // xp - xa

    for (i = X; i <= Z; ++i) {
        if (eixo == i) {
            ponto_interseccao[i] = SINAL(plano);
            continue;
        }
        // W = (delta W / delta X) * (X - Xa) + Wa
        ponto_interseccao[i] = (delta[i] * fator / delta[eixo]) + a[i];
    }

    return ponto_interseccao;
}

// -x < +1 e : x > -1
//  x < +1 d
