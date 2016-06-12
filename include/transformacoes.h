#ifndef __TRANSFORMACOES_H__
#define __TRANSFORMACOES_H__

#include "matriz.h"

#define X (0)
#define Y (1)
#define Z (2)

double GrausARadianos(double graus);
void Homogeneizar(Matriz *V);

Matriz *CriarTransformacaoEscala(double sx, double sy, double sz);
Matriz *CriarTransformacaoTranslacao(double dx, double dy, double dz);
Matriz *CriarTransformacaoRotacao(double ang, int eixo);

#endif // __TRANSFORMACOES_H__
