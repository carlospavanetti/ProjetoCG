#include <stdio.h>
#include <stdlib.h>

#include "projecoes.h"
#include "transformacoes.h"

#include <math.h>

Matriz *CriarProjecaoOrtografica(
        double esquerda, double direita,
        double baixo, double cima,
        double perto, double longe) {

    double mx = (direita + esquerda) / 2;
    double my = (cima    + baixo) / 2;
    double mz = (longe   + perto) / 2;

    double sx = 2 / (direita - esquerda);
    double sy = 2 / (cima - baixo);
    double sz = 2 / (longe - perto);

    Matriz *T = CriarTransformacaoTranslacao(-mx, -my, -mz);
    Matriz *S = CriarTransformacaoEscala(sx, sy, -sz);

    Matriz *P = Multiplicar(S, T);

    LiberarMatriz(&T);
    LiberarMatriz(&S);

    return P;
}

Matriz *CriarProjecaoPerspectivaVolume(
        double esquerda, double direita,
        double baixo, double cima,
        double perto, double longe) {


    if (perto < 0 || longe < perto) {
        printf("Plano de projeção perspectiva deve receber valor positivo\n");
        return NULL;
    }

    perto *= -1; // os planos de projeção devem estar
    longe *= -1;

    double fx = 2 * perto / (direita - esquerda);
    double fy = 2 * perto / (cima    - baixo);
    double dz = 2 * perto * longe / (perto - longe);

    double Ax = (direita + esquerda) / (direita - esquerda);
    double By = (cima    + baixo)    / (cima    - baixo);
    double Cz = (perto   + longe)    / (perto   - longe);


    Matriz *P = CriarZero(4, 4);
    em(P, 0, 0) = fx;
    em(P, 1, 1) = fy;

    em(P, 0, 2) = Ax;
    em(P, 1, 2) = By;
    em(P, 2, 2) = Cz;

    em(P, 2, 3) = dz;
    em(P, 3, 2) = -1;

    return P;
}

Matriz *CriarProjecaoPerspectivaAspecto(
        double angulo_de_abertura, double proporcao,
        double perto, double longe) {

    double meio_angulo_rad = GrausARadianos(angulo_de_abertura / 2);
    double tangente = tan(meio_angulo_rad);

    double cima = perto * tangente;
    double baixo = -cima;

    double direita = cima * proporcao;
    double esquerda = -direita;

    return CriarProjecaoPerspectivaVolume(
        esquerda, direita, baixo, cima, perto, longe);
}

void AplicarProjecaoOrtografica(
        double esquerda, double direita,
        double baixo, double cima,
        double perto, double longe) {
    Matriz *P = CriarProjecaoOrtografica(
        esquerda, direita, baixo, cima, perto, longe);
    AplicarTransformacao(P);
    LiberarMatriz(&P);
}

void AplicarProjecaoPerspectivaVolume(
        double esquerda, double direita,
        double baixo, double cima,
        double perto, double longe) {

    Matriz *P = CriarProjecaoPerspectivaVolume(
        esquerda, direita, baixo, cima, perto, longe);
    AplicarTransformacao(P);
    LiberarMatriz(&P);
}

void AplicarProjecaoPerspectivaAspecto(
        double angulo_de_abertura, double proporcao,
        double perto, double longe) {
    Matriz *P = CriarProjecaoPerspectivaAspecto(
        angulo_de_abertura, proporcao, perto, longe);
    AplicarTransformacao(P);
    LiberarMatriz(&P);
}
