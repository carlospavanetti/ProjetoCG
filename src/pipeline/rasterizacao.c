#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "contexto.h"
#include "poligonos.h"
#include "helpers/lista_linhas.h"
#include "helpers/preparar_rasterizacao.h"

#define LINHAS_VIEWPORT (2048)

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

    while (varredura_y < LINHAS_VIEWPORT) {
        if (GET[varredura_y] != NULL)
            TransferirParaAET(GET, AET, varredura_y);
        TracarLinhas(AET, varredura_y, lista);
        varredura_y++;
    }
    // 
    // int i;
    // for (i = 0; i < LINHAS_VIEWPORT; ++i) {
    //     DadosAresta *ref = GET[i];
    //     printf("%04d ", i);
    //     while (ref != NULL) {
    //         printf("%p -> ",  ref);
    //         ref = ref->proxima;
    //     }
    //     printf("(NIL)\n");
    // }
    LiberarTabelaArestas(GET);
    free(AET); // FIXME
    free(vertices);
    free(lista->dados);
    free(lista);
    return NULL;
}
