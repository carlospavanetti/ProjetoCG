#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "contexto.h"
#include "poligonos.h"
#include "helpers/lista_linhas.h"
#include "helpers/preparar_rasterizacao.h"

ListaLinhas *RasterizarPoligono(Poligono *poligono) {
    // viewport [-1, 1] => [-1024, 1024] => [0, 2048]

    int *vertices = PrepararPoligonoParaNovoViewport(poligono);
    DadosAresta **GET = InicializaGET(vertices, poligono->numero_vertices);
    DadosAresta **AET = (DadosAresta **) malloc(sizeof(DadosAresta *));
    *AET = NULL;
    ListaLinhas *lista = InicializarListaLinhas();

    // AQUI ACONTECE
    // Busca menor coordenada Y
    int varredura_y = 0;
    while (GET[varredura_y] == NULL)
        varredura_y++;

    while (varredura_y < 2048) {
        if (GET[varredura_y] != NULL)
            TransferirParaAET(GET, AET, varredura_y);
        TracarLinhas(AET, varredura_y, lista);
        varredura_y++;
    }

    LiberarTabelaArestas(GET);
    free(AET); // FIXME
    free(vertices);
    free(lista->dados);
    free(lista);
    return NULL;
}
