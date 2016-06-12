#include "matriz.h"
#include "contexto.h"
#include <stdlib.h>
#include <string.h>

static Matriz *TransformacoesModelo;
// static Matriz *TransformacoesCamera;
static Matriz *TransformacoesProjecao;

static Pilha *PilhaMatrizModelo;
// static Pilha *PilhaMatrizCamera;
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

#define CAPACIDADE_PADRAO (100)

void AtualizarPonteiroPilha() {
    if (MatrizCorrenteID == MATRIZ_MODELO)
        PilhaMatrizModelo = PilhaCorrente;
    // if (MatrizCorrenteID == MATRIZ_CAMERA)
    //     PilhaMatrizCamera = PilhaCorrente;
    if (MatrizCorrenteID == MATRIZ_PROJECAO)
        PilhaMatrizProjecao = PilhaCorrente;
}

void EmpilharMatriz() {
    double *destino = &PilhaCorrente->matrizes[16 * PilhaCorrente->topo];
    double *fonte = MatrizCorrente->dados;
    memcpy(destino, fonte, 16 * sizeof(double));
    PilhaCorrente->topo++;

    if(PilhaCorrente->topo >= PilhaCorrente->capacidade) {
        if (PilhaCorrente->proxima == NULL) {
            PilhaCorrente->proxima = CriarPilha(CAPACIDADE_PADRAO);
            PilhaCorrente->proxima->anterior = PilhaCorrente;
        }

        PilhaCorrente = PilhaCorrente->proxima;
        AtualizarPonteiroPilha();
    }
}

void DesempilharMatriz() {
    if (PilhaCorrente->topo <= 0) {
        if (PilhaCorrente->anterior == NULL)
            return;
        PilhaCorrente = PilhaCorrente->anterior;
        AtualizarPonteiroPilha();
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

    // if (MID == MATRIZ_CAMERA) {
    //     PilhaCorrente = PilhaMatrizCamera;
    //     MatrizCorrente = TransformacoesCamera;
    // }

    if (MID == MATRIZ_PROJECAO) {
        PilhaCorrente = PilhaMatrizProjecao;
        MatrizCorrente = TransformacoesProjecao;
    }
}

void InicializarContexto(int params) {
    TransformacoesModelo = CriarIdentidade(4);
    TransformacoesProjecao = CriarIdentidade(4);
}

Matriz *MatrizModelo() {
    return CopiarMatriz(TransformacoesModelo);
}

Matriz *MatrizProjecao() {
    return CopiarMatriz(TransformacoesProjecao);
}

void AplicarTransformacao(Matriz *T) {
    Matriz *R = Multiplicar(T, MatrizCorrente);
    memcpy(MatrizCorrente->dados, R->dados, 16 * sizeof(double));
    LiberarMatriz(&R);
}

void CarregarIdentidade() {
    static double Id[] = { 1, 0, 0, 0,   0, 1, 0, 0,   0, 0, 1, 0,   0, 0, 0, 1 };
    memcpy(MatrizCorrente->dados, Id, 16 * sizeof(double));
}
