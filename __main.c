#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "humanoide.h"
#include "textura.h"

#include "matriz.h"
#include "transformacoes.h"
#include "projecoes.h"
#include "contexto.h"
#include "pipeline.h"

int angx = 0, angy = 0, angz = 0;
void RenderizarCena(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


	// glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        glRotatef(angx,1.0,0.0,0.0);
        glRotatef(angy,0.0,1.0,0.0);
        glRotatef(angz,0.0,0.0,1.0);

        DesenharPersonagem();
    glPopMatrix();
    // glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}

#define INCREMENTO_ANGULO (5.0)
void Teclado(unsigned char key, int x, int y) {
    Humanoide *h = Personagem();
    switch (key) {
    case 'x':
        angx += INCREMENTO_ANGULO;
        break;
    case 'X':
        angx -= INCREMENTO_ANGULO;
        break;
    case 'y':
        angy += INCREMENTO_ANGULO;
        break;
    case 'Y':
        angy -= INCREMENTO_ANGULO;
        break;
    case 'z':
        angz += INCREMENTO_ANGULO;
        break;
    case 'Z':
        angz -= INCREMENTO_ANGULO;
        break;

    case 's':
        h->ombro_direito += INCREMENTO_ANGULO;
        if (h->ombro_direito > 75)
            h->ombro_direito = 75;
        break;
    case 'S':
        h->ombro_direito -= INCREMENTO_ANGULO;
        if (h->ombro_direito < -75)
            h->ombro_direito = -75;
        break;
    case 'e':
        h->cotovelo_direito += INCREMENTO_ANGULO;
        if (h->cotovelo_direito > 120)
            h->cotovelo_direito = 120;
        break;
    case 'E':
        h->cotovelo_direito -= INCREMENTO_ANGULO;
        if (h->cotovelo_direito < -5)
            h->cotovelo_direito = -5;
        break;

    case 27:
        exit(0);
        break;
    }

    glutPostRedisplay();
}

void HabilitarIluminacao() {
	GLfloat objeto_ambiente[4] = {1.0,1.0,1.0,1.0};
	GLfloat objeto_difusa[4] = {1.0,1.0,0.0,1.0};

	GLfloat luz_ambiente[4] = {0.3, 0.3, 0.3, 1.0};
	GLfloat luz_difusa[4] = {1.0, 1.0, 1.0, 0.5};
	GLfloat mat_specular[4] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat mat_shininess[] = {0.01};
	GLfloat light_position[4] = {-100.0, 100.0, 30.0, 1.0};


	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luz_ambiente);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor (1.0, 1.0, 1.0, 1.0);
	glShadeModel (GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, objeto_ambiente);
	// glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

    CarregarTexturas();
	// Viewing();
}

float aspecto = 4.0 / 3.0;
void Redimensionar(GLsizei w, GLsizei h) {
	/* Para previnir uma divisão por zero */
	if ( h == 0 )
		h = 1;
	glViewport(0, 0, w, h);
	aspecto = (GLfloat) w / (GLfloat) h;
}

int main(int argc, char** argv) {
    InicializarContexto(0);

    SelecionarMatrizCorrente(MATRIZ_MODELO);
    AplicarProjecaoPerspectivaAspecto(45, aspecto, 1, 1000);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (700, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Projeto de CG");
	glutReshapeFunc(Redimensionar);
    glutDisplayFunc(RenderizarCena);
    glutKeyboardFunc(Teclado);

    InicializarPersonagem();
    HabilitarIluminacao();

    glutMainLoop();
    return 0;
}
