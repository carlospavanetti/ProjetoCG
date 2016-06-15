#ifndef __TEXTURA_H__
#define __TEXTURA_H__

#define MAX_TEXTURAS 1

#define hulk_skin 0
#define cabelo 1
#define jeans 2
#define coisa_skin 3
#define couro 4
#define asfalto 5
#define predio1 6
#define predio2 7
#define calcada 8
#define predio3 9
#define predio4 10
#define predio5 11
#define predio6 12
#define telhado 13
#define dia 14
#define noite 15
#define ceu 16
#define ceu_noite 17

typedef struct TexturaBitmap {
	int largura;
	int altura;
	char *dados;
} TexturaBitmap;

void CarregarTexturas();
void CriarTextura(int id);
void SelecionarTextura(int i);

void CarregarBitmap(char *pFileName, int id);

#endif // __TEXTURA_H__
