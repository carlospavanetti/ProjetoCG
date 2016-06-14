#ifndef __PIPELINE_H__
#define __PIPELINE_H__

#include "poligonos.h"
#include "helpers/lista_linhas.h"

double *TransformarVertices(double *vertices, int quantidade);
double *ProjetarVertices(double *vertices, int quantidade);
Poligono *RecortarParaAreaDeVisao(Poligono *poligono);

// ListaLinhas
ListaLinhas *RasterizarPoligono(Poligono *arestas);
// Textura *ColorizarFragmentos(TabelaLinhas *fragmentos);

#endif // __PIPELINE_H__
