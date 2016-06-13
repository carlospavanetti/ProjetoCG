#ifndef __INTERSECCAO_RETAS_H__
#define __INTERSECCAO_RETAS_H__

#include <stdbool.h>

#define ESQUERDA (0) // X0 000
#define DIREITA  (1) // X1 001
#define BAIXO    (2) // Y0 010
#define CIMA     (3) // Y1 011
#define PERTO    (4) // Z0 100
#define LONGE    (5) // Z1 101

#define COORDENADA(PLANO) ((PLANO) >> 1)
#define SINAL(PLANO) ((((PLANO) & 1)  == 0) ? (-1) : (1))

bool dentro_plano(int plano, double *ponto);
double *interseccao(int plano, double *a, double *b);

#endif // __INTERSECCAO_RETAS_H__
