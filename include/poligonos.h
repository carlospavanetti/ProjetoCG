#ifndef __POLIGONOS_H__
#define __POLIGONOS_H__

#include <stdlib.h>

typedef struct {
    int numero_vertices;
    int *indice_vertices;
    double *endereco_vertices;
} Poligono;

double *VerticeDoPoligono(Poligono *p, int indice);

#endif // __POLIGONOS_H__
