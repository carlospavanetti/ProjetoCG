#ifndef __POLIGONOS_H__
#define __POLIGONOS_H__

typedef struct {
    int numero_vertices;
    int *indice_vertices;
    double *endereco_vertices;
} Poligono;

double *VerticeDoPoligono(Poligono *p, int indice) {
    if (p == NULL)
        return NULL;
    return p->endereco_vertices[4 * indice_vertices[indice]];
}

#endif // __POLIGONOS_H__
