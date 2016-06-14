#ifndef __LISTA_LINHAS_H__
#define __LISTA_LINHAS_H__

typedef struct {
    int y;
    int x_inicial, x_final;
    int z_inicial, z_final;
} Linha;

typedef struct {
    Linha *dados;

    int capacidade;
    int quantidade;
} ListaLinhas;

typedef struct DA {
    int y_max;
    int x_inicial;
    int z_inicial;

    int x_inteiro;
    int x_fracionario;
    int z_inteiro;
    int z_fracionario;

    int dx;
    int dy;
    int dz;

    struct DA *proxima;
} DadosAresta;

void LiberarTabelaArestas(DadosAresta **tabela);

void InserirRegistroAresta(
    DadosAresta **lista,
    int y_max, int x_inicial, int z_inicial,
    int dx, int dy, int dz);

DadosAresta *NovoRegistroAresta(int y_max, int xi, int zi, int dx, int dy, int dz);

void TransferirParaAET(DadosAresta **GET, DadosAresta **AET, int varredura_y);

ListaLinhas *InicializarListaLinhas();
void InserirLinha(ListaLinhas *lista, Linha *linha);
void TracarLinhas(DadosAresta **AET, int varredura_y, ListaLinhas *lista);

// TabelaGlobalDeArestas;
// TabelaDeArestasAtivas;lista

#endif // __LISTA_LINHAS_H__
