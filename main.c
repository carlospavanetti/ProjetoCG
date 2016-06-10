#include "matriz.h"
#include "transformacoes.h"
#include "projecoes.h"
#include "contexto.h"

#include <stdio.h>
#include <stdlib.h>

void DesenharTriangulos(double *vertices, int quantidade);
int main() {
    double v[6] = {1, 0, 0, 0, 0, 1};
    InicializarContexto(0);
    SelecionarMatrizCorrente(MATRIZ_MODELO);
    Matriz *R = CriarTransformacaoRotacao(90, Z);
    AplicarTransformacao(R);
    DesenharTriangulos(v, 6);
    LiberarMatriz(&R);
}
