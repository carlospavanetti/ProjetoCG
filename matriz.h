#ifndef __MATRIZ_H__
#define __MATRIZ_H__

#define TYPE double
typedef struct Matriz {
    TYPE *dados;
    int linhas, colunas;
} Matriz;

#define em(M, i, j) ((M)->dados[(i) * (M)->colunas + (j)])

Matriz *CriarMatriz(int linhas, int colunas);
void LiberarMatriz(Matriz **M);

int DimensaoMatriz(Matriz *M);
int TamanhoEmMemoriaMatriz(Matriz *M);

Matriz *CopiarMatriz(Matriz *A);
int MatrizesIguais(Matriz *A, Matriz *B);

Matriz *CriarZero(int linhas, int colunas);
Matriz *CriarIdentidade(int dim);

void ImprimirMatriz(Matriz *M);

Matriz *Transpor(Matriz *A);
Matriz *Oposto(Matriz *A);

Matriz *Somar(Matriz *A, Matriz *B);
Matriz *Subtrair(Matriz *A, Matriz *B);

Matriz *MultiplicarPorEscalar(Matriz *A, TYPE k);
Matriz *Multiplicar(Matriz *A, Matriz *B);

#endif // __MATRIZ_H__
