#ifndef __CONTEXTO_H__
#define __CONTEXTO_H__

#define MATRIZ_MODELO   (0)
#define MATRIZ_CAMERA   (1)
#define MATRIZ_PROJECAO (2)

typedef struct Pilha {
    int topo;
    int capacidade;
    double *matrizes;

    struct Pilha *proxima;
    struct Pilha *anterior;
} Pilha;

Pilha *CriarPilha(int capacidade);

void EmpilharMatriz();
void DesempilharMatriz();
void SelecionarMatrizCorrente(int MID);

#define BUFFER_SIMPLES (1 << 0)
#define BUFFER_DUPLO   (1 << 1)

void InicializarContexto(int params);

Matriz *Modelo();
void AplicarTransformacao(Matriz *);

#endif // __CONTEXTO_H__
