#include <stdlib.h>
#include "poligonos.h"

double *VerticeDoPoligono(Poligono *p, int indice) {
    if (p == NULL)
        return NULL;
    return &p->endereco_vertices[4 * p->indice_vertices[indice]];
}
