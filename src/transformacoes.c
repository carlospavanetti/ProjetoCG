#include "transformacoes.h"
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

Matriz *CriarTransformacaoEscala(double sx, double sy, double sz) {
    Matriz *S = CriarIdentidade(4);
    em(S, 0, 0) = sx;
    em(S, 1, 1) = sy;
    em(S, 2, 2) = sz;
    return S;
}

Matriz *CriarTransformacaoTranslacao(double dx, double dy, double dz) {
    Matriz *T = CriarIdentidade(4);
    em(T, 0, 3) = dx;
    em(T, 1, 3) = dy;
    em(T, 2, 3) = dz;
    return T;
}

#define X (0)
#define Y (1)
#define Z (2)

double GrausARadianos(double graus) {
    return graus * M_PI / 180.0;
}

Matriz *CriarTransformacaoRotacao(double ang, int eixo) {
    double radAng = GrausARadianos(ang);
    double cosAng = cos(radAng);
    double senAng = sin(radAng);
    Matriz *R = CriarIdentidade(4);

    if (eixo == X) {
        em(R, 1, 1) = em(R, 2, 2) = cosAng;
        em(R, 2, 1) =  senAng;
        em(R, 1, 2) = -senAng;
    }

    if (eixo == Y) {
        em(R, 0, 0) = em(R, 2, 2) = cosAng;
        em(R, 0, 2) =  senAng;
        em(R, 2, 0) = -senAng;
    }

    if (eixo == Z) {
        em(R, 0, 0) = em(R, 1, 1) = cosAng;
        em(R, 1, 0) =  senAng;
        em(R, 0, 1) = -senAng;
    }

    return R;
}

void Homogeneizar(Matriz *V) {
    if (V->colunas > 1)
        return;

    int i;
    double w = em(V, V->linhas - 1, 0);
    if (w == 0)
        return;

    for (i = 0; i < V->linhas; ++i)
        em(V, i, 0) /= w;
}
