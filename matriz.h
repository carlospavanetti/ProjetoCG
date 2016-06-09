#ifndef __MATRIZ_H__
#define __MATRIZ_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE double
typedef struct Matriz {
    TYPE *dados;
    int linhas, colunas;
} Matriz;

#define em(M, i, j) ((M)->dados[(i) * (M)->colunas + (j)])

Matriz *CriarMatriz(int linhas, int colunas) {
    Matriz *n = (Matriz *) malloc(sizeof(Matriz));
    n->dados = (TYPE *) malloc(linhas * colunas * sizeof(TYPE));

    n->linhas = linhas;
    n->colunas = colunas;
    return n;
}

void LiberarMatriz(Matriz **M) {
    Matriz *ref = *M;
    free(ref->dados);
    free(ref);
    *M = NULL;
}

int DimensaoMatriz(Matriz *M) {
    return M->linhas * M->colunas;
}

size_t TamanhoEmMemoriaMatriz(Matriz *M) {
    return DimensaoMatriz(M) * sizeof(TYPE);
}

Matriz *CopiarMatriz(Matriz *A) {
    if (A == NULL)
        return NULL;

    Matriz *R = NULL;
    R = CriarMatriz(A->linhas, A->colunas);
    memcpy(R->dados, A->dados, TamanhoEmMemoriaMatriz(A));

    return R;
}

int MatrizesIguais(Matriz *A, Matriz *B) {
    if (A->linhas != B->linhas) return 0;
    if (A->colunas != B->colunas) return 0;

    return memcmp(A->dados, B->dados, TamanhoEmMemoriaMatriz(A)) == 0;
}

Matriz *CriarZero(int linhas, int colunas) {
    int i, j;
    Matriz *Zero = CriarMatriz(linhas, colunas);
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; ++j)
            em(Zero, i, j) = 0;
    return Zero;
}

Matriz *CriarIdentidade(int dim) {
    int i, j;

    Matriz *Ident = CriarMatriz(dim, dim);
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; ++j)
            if (i == j) em(Ident, i, j) = 1;
            else        em(Ident, i, j) = 0;
    return Ident;
}

void ImprimirMatriz(Matriz *M) {
    int i, j;
    for (i = 0; i < M->linhas; ++i) {
        for (j = 0; j < M->colunas; ++j)
            printf(" %.3f", em(M, i, j));
        printf("\n");
    }
    printf("\n");
}

Matriz *Somar(Matriz *A, Matriz *B) {
    if (A == NULL)
        return NULL;
    if (B == NULL)
        return NULL;
    if (A->linhas != B->linhas)
        return NULL;
    if (A->colunas != B->colunas)
        return NULL;

    int i, j;
    Matriz *C = NULL;
    C = CriarMatriz(A->linhas, A->colunas);
    for (i = 0; i < A->linhas; i++)
        for (j = 0; j < A->colunas; j++)
            em(C, i, j) = em(A, i, j) + em(B, i, j);

    return C;
}

Matriz *Oposto(Matriz *A) {
    if (A == NULL)
        return NULL;

    int i, j;
    Matriz *R = NULL;

    R = CriarMatriz(A->linhas, A->colunas);
    for (i = 0; i < A->linhas; i++)
        for (j = 0; j < A->colunas; j++)
            em(R, i, j) = -em(A, i, j);

    return R;
}

Matriz *Subtrair(Matriz *A, Matriz *B) {
    return Somar(A, Oposto(B));
}

Matriz *MultiplicarPorEscalar(Matriz *A, TYPE k) {
    if (A == NULL)
        return NULL;

    int i, j;
    Matriz *B = CriarMatriz(A->linhas, A->colunas);
    for (i = 0; i < A->linhas; ++i)
        for (j = 0; j < A->colunas; ++j)
            em(B, i, j) = k * em(A, i, j);

    return B;
}

Matriz *Multiplicar(Matriz *A, Matriz *B) {
    if (A == NULL)
        return NULL;
    if (B == NULL)
        return NULL;
    if (A->colunas != B->linhas)
        return NULL;

    int i, j, k;
    // A (a x k)
    // B (k x b)
    // C (a x b)
    Matriz *C = NULL;
    C = CriarZero(A->linhas, B->colunas);

    for (i = 0; i < C->linhas; i++)
        for (j = 0; j < C->colunas; j++)
            for (k = 0; k < A->colunas; k++)
            // for (k = 0; k < B->linhas; k++)
                em(C, i, j) += em(A, i, k) * em(B, k, j);
    return C;
}

Matriz *Transpor(Matriz *A) {
    if (A == NULL)
        return NULL;

    int i, j;
    Matriz *At = NULL;

    At = CriarMatriz(A->colunas, A->linhas);
    for (i = 0; i < A->linhas; i++)
        for (j = 0; j < A->colunas; j++)
            em(At, j, i) = em(A, i, j);

    return At;
}

#endif // __MATRIZ_H__
