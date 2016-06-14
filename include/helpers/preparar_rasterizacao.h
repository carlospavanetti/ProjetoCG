#ifndef __PREPARAR_RASTERIZACAO_H__
#define __PREPARAR_RASTERIZACAO_H__

#include "poligonos.h"
#include "helpers/lista_linhas.h"

DadosAresta **InicializaGET(int *vertices, int quantidade);
int *PrepararPoligonoParaNovoViewport(Poligono *poligono);

#endif // __PREPARAR_RASTERIZACAO_H__
