#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "contexto.h"

double *TransformarVertices(double *vertices, int quantidade);

void DesenharTriangulos(double *vertices, int quantidade) {
    // double *vertices_transformados = TransformarVertices(vertices, quantidade);
    // double *iluminacao_vertices = AplicarIluminacao(vertices_transformados, quantidade);
    // double *vertices_projetados = ProjetarVertices(vertices_transformados, quantidade);
    // double *arestas_visiveis = RecortarArestas(vertices_projetados, &quantidade);
    // linhas *rasterizacao = RasterizarPoligonos(arestas_visiveis, quantidade);
    // int *textura_final = RenderizarFragmentos(rasterizacao);

    /* TODO:
    Iluminacao(); => VertexShader, ponto de luz em cada vertice - XXX: não!
    AplicarProjecao(); => Lista de vertices projetados
    RecortarArestas(); => Lista de pontos e arestas visiveis
    PreencherPoligonos(); => Lista de linhas horizontais que preenchem poligono
    TexturasEFragmentos(); => Buffer de pixels para plotar, textura final
    DrawPixelArray();
    XXX */

    // int i;
    // for (i = 0; i < 4 * quantidade / 3; i++)
    //     printf("%.2f ", vertices_transformados[i]);
    // printf("\n");
}
