#ifndef __HUMANOIDE_H__
#define __HUMANOIDE_H__

typedef struct {
    int ombro_direito;
    int ombro_esquerdo;
    int cotovelo_direito;
    int cotovelo_esquerdo;
} Humanoide;

void DesenharPersonagem();
void InicializarPersonagem();
Humanoide *Personagem();

#endif // __HUMANOIDE_H__
