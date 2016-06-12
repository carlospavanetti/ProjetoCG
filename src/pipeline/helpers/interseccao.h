#ifndef __INTERSECCAO_RETAS_H__
#define __INTERSECCAO_RETAS_H__

#include <stdbool.h>

#define ESQUERDA (0)
#define DIREITA  (1)
#define BAIXO    (2)
#define CIMA     (3)
#define PERTO    (4)
#define LONGE    (5)

#define ESQUERDA_COORD (X)
#define DIREITA_COORD  (X)
#define BAIXO_COORD    (Y)
#define CIMA_COORD     (Y)
#define PERTO_COORD    (Z)
#define LONGE_COORD    (Z)

#define ESQUERDA_SINAL (-1)
#define DIREITA_SINAL  (+1)
#define BAIXO_SINAL    (-1)
#define CIMA_SINAL     (+1)
#define PERTO_SINAL    (-1)
#define LONGE_SINAL    (+1)

bool dentro_plano(int plano, double *ponto);
double *interseccao(int plano, double *a, double *b);

#endif // __INTERSECCAO_RETAS_H__
