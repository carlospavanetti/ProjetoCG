#ifndef __PROJECOES_H__
#define __PROJECOES_H__

#include "matriz.h"
#include <stdlib.h>

Matriz *CriarProjecaoOrtografica(
        double esquerda, double direita,
        double baixo, double cima,
        double perto, double longe);

Matriz *CriarProjecaoPerspectivaVolume(
        double esquerda, double direita,
        double baixo, double cima,
        double perto, double longe);

Matriz *CriarProjecaoPerspectivaAspecto(
        double angulo_de_abertura, double proporcao,
        double perto, double longe);

void AplicarProjecaoOrtografica(
        double esquerda, double direita,
        double baixo, double cima,
        double perto, double longe);

void AplicarProjecaoPerspectivaVolume(
        double esquerda, double direita,
        double baixo, double cima,
        double perto, double longe);

void AplicarProjecaoPerspectivaAspecto(
        double angulo_de_abertura, double proporcao,
        double perto, double longe);

#endif // __PROJECOES_H__
