#include "matriz.h"
#include "contexto.h"
#include <stdlib.h>
#include <string.h>

static Matriz *TransformacoesModelo;
static Matriz *TransformacoesCamera;
static Matriz *TransformacoesProjecao;

static Pilha *PilhaMatrizModelo;
static Pilha *PilhaMatrizCamera;
static Pilha *PilhaMatrizProjecao;

static Pilha *PilhaCorrente;
static int MatrizCorrenteID;
static Matriz *MatrizCorrente;

Pilha *CriarPilha(int capacidade) {
    Pilha *P = (Pilha *) malloc(sizeof(Pilha));
    P->topo = 0;
    P->capacidade = capacidade;
    P->matrizes = (double *) malloc(16 * sizeof(double) * capacidade);

    P->proxima = P->anterior = NULL;
    return P;
}

void EmpilharMatriz() {
    double *destino = &PilhaCorrente->matrizes[16 * PilhaCorrente->topo];
    double *fonte = MatrizCorrente->dados;
    memcpy(destino, fonte, 16 * sizeof(double));
    PilhaCorrente->topo++;

    if(PilhaCorrente->topo >= PilhaCorrente->capacidade) {
        // avanca
    }
}

void DesempilharMatriz() {
    if (PilhaCorrente->topo <= 0) {
        // retornar uma pilha
    }

    PilhaCorrente->topo--;

    double *destino = MatrizCorrente->dados;
    double *fonte = &PilhaCorrente->matrizes[16 * PilhaCorrente->topo];
    memcpy(destino, fonte, 16 * sizeof(double));
}

void SelecionarMatrizCorrente(int MID) {
    MatrizCorrenteID = MID;
    if (MID == MATRIZ_MODELO) {
        PilhaCorrente = PilhaMatrizModelo;
        MatrizCorrente = TransformacoesModelo;
    }

    if (MID == MATRIZ_CAMERA) {
        PilhaCorrente = PilhaMatrizCamera;
        MatrizCorrente = TransformacoesCamera;
    }

    if (MID == MATRIZ_PROJECAO) {
        PilhaCorrente = PilhaMatrizProjecao;
        MatrizCorrente = TransformacoesProjecao;
    }
}
