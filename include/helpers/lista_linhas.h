#ifndef __LISTA_LINHAS_H__
#define __LISTA_LINHAS_H__

typedef struct {
    int y;
    int *x_inicial;
    int *x_final;

    int capacidade;
    int quantidade;
} ListaLinhas;

typedef struct DA {
    int y_max;
    int x_inicial;

    int x_inteiro;
    int x_fracionario;

    int dx;
    int dy;

    struct DA *proxima;
} DadosAresta;

void InsertirRegistroAresta(
    DadosAresta **lista,
    int y_max, int x_inicial,
    int dx, int dy);

DadosAresta *NovoRegistroAresta(int y_max, int x_inicial, int dx, int dy);

void LiberarTabelaArestas(DadosAresta **tabela);

// TabelaGlobalDeArestas;
// TabelaDeArestasAtivas;

#endif // __LISTA_LINHAS_H__
