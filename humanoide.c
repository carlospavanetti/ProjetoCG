#include <GL/glut.h>
#include <math.h>

#include "humanoide.h"
#include "textura.h"
#include "cubo.h"

static Humanoide *TheGuy;
void InicializarPersonagem() {
    TheGuy = (Humanoide *) malloc(sizeof(Humanoide));
    TheGuy->ombro_direito = TheGuy->ombro_esquerdo = 0;
    TheGuy->cotovelo_direito = TheGuy->cotovelo_esquerdo = 0;
}

Humanoide *Personagem() {
    return TheGuy;
}

void DesenharTorax() {}
void DesenharBraco(int bid) {
    int ombro, cotovelo;
    if (bid == 0) {
        ombro = TheGuy->ombro_direito;
        cotovelo = TheGuy->cotovelo_direito;
    } else if (bid == 1) {
        ombro = TheGuy->ombro_esquerdo;
        cotovelo = TheGuy->cotovelo_esquerdo;
    }

    glPushMatrix();
        glTranslatef(0.1, 0.0, 0.0);
        glPushMatrix();
            glScalef(0.25, 0.25, 0.5);
            glutSolidSphere(0.2, 15, 5);
        glPopMatrix();
        glRotatef(ombro, 0.0, 0.0, 1.0);
        glTranslatef(-0.1, 0.0, 0.0);

        glPushMatrix();
            glScalef (1.0, 0.5, 1.0);
            DesenharCubo(0.2);
        glPopMatrix();

        glTranslatef(-0.2 + 0.1,0.0,0.0);
        glPushMatrix();
            glScalef(0.25, 0.25, 0.5);
            glutSolidSphere(0.2, 15, 5);
        glPopMatrix();
        glRotatef(cotovelo, 0.0, 0.0, 1.0);
        glTranslatef(-0.1, 0.0, 0.0);
        glPushMatrix();
            glScalef (1.2, 0.5, 1.0);
            DesenharCubo(0.2);
        glPopMatrix();
    glPopMatrix();
}
void DesenharCotovelo() {}

void DesenharAntebraco() {}
void DesenharMao() {}
void DesenharPernaSup() {}
void DesenharJoelho() {}

void DesenharPernaInf() {}
void DesenharPe() {}
void DesenharCabeca() {}
void DesenharCabelo() {}

void DesenharOlho() {}
void DesenharCalca() {}

void DesenharPersonagem() {
    glPushMatrix();
        glPushMatrix();
            glScalef(0.6,1.5,0.5);
            DesenharCubo(0.4);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.22,0.0,0.0);
            DesenharBraco(0);
        glPopMatrix();

        glPushMatrix();
            glScalef(-1,1.0,1.0);
            glTranslatef(-0.22,0.0,0.0);
            DesenharBraco(1);
        glPopMatrix();
    glPopMatrix();
}
