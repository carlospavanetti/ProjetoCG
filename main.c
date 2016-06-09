#include "matriz.h"
#include "transformacoes.h"
#include "projecoes.h"
#include "contexto.h"

int main() {
    // Matriz *P1 = CriarProjecaoPerspectiva(5);
    Matriz *P1 = CriarProjecaoPerspectivaVolume(0, 20, 0, 20, 10, 20);
    Matriz *P2 = CriarProjecaoOrtografica(0, 20, 0, 20, 0, 20);
    Matriz *P3 = CriarProjecaoOrtografica(-10, 10, -10, 10, -10, 10);
    // Matriz *P4 = CriarProjecaoPerspectivaVolume(-10, 10, -10, 10, 10, 20);
    Matriz *P4 = CriarProjecaoPerspectivaAspecto(90, 1, 10, 20);

    Matriz *V = CriarMatriz(4, 1);
    em(V, 0, 0) = 10;
    em(V, 1, 0) = 20;
    em(V, 2, 0) = 10;
    em(V, 3, 0) = 1;

    Matriz *V1 = Multiplicar(P1, V);
    Homogeneizar(V1);
    Matriz *V2 = Multiplicar(P2, V);
    Matriz *V3 = Multiplicar(P3, V);
    Matriz *V4 = Multiplicar(P4, V);
    Homogeneizar(V4);

    ImprimirMatriz(V1);
    ImprimirMatriz(V2);
    ImprimirMatriz(V3);
    ImprimirMatriz(V4);

    LiberarMatriz(&V);
    LiberarMatriz(&P1);
    LiberarMatriz(&P2);
    LiberarMatriz(&P3);
    LiberarMatriz(&P4);

    LiberarMatriz(&V1);
    LiberarMatriz(&V2);
    LiberarMatriz(&V3);
    LiberarMatriz(&V4);
}
