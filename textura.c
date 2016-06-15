#include "textura.h"

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

char *ARQUIVOS[MAX_TEXTURAS] = {
    "imagens/vai.bmp"
};

GLuint IDs_TEXTURAS[MAX_TEXTURAS];
TexturaBitmap DADOS_TEXTURAS[MAX_TEXTURAS];

void CarregarTexturas() {
    glGenTextures(MAX_TEXTURAS, IDs_TEXTURAS);

    int id;
    for (id = 0; id < MAX_TEXTURAS; ++id) {
    	glBindTexture(GL_TEXTURE_2D, IDs_TEXTURAS[id]);
    	CarregarBitmap(ARQUIVOS[id], id);
        CriarTextura(id);
    }
}

void CriarTextura(int id) {
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
        DADOS_TEXTURAS[id].largura, DADOS_TEXTURAS[id].altura, 0,
        GL_RGB, GL_UNSIGNED_BYTE, DADOS_TEXTURAS[id].dados);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
}

void SelecionarTextura(int i) {
	glBindTexture(GL_TEXTURE_2D, IDs_TEXTURAS[i]);
}

void CarregarBitmap(char *nome_arquivo, int id) {
    FILE *arquivo = NULL;
    TexturaBitmap *imagem = &DADOS_TEXTURAS[id];
    unsigned short planos, bpp;

    if ((arquivo = fopen(nome_arquivo, "rb")) == NULL)
		printf("Arquivo não encontrado: %s.\n", nome_arquivo);

    // Informações de largura/altura 18 bytes
    fseek(arquivo, 18, SEEK_CUR);

	int i;
    if ((i = fread(&imagem->largura, 4, 1, arquivo)) != 1)
		printf("Erro ao ler informações de largura em %s.\n ", nome_arquivo);

    if ((i = fread(&imagem->altura, 4, 1, arquivo)) != 1)
		printf("Erro ao ler informações de altura em %s.\n ", nome_arquivo);

    if ((fread(&planos, 2, 1, arquivo)) != 1)
		printf("Erro ao ler informações de #planos em %s.\n ", nome_arquivo);

    if (planos != 1 )
		printf("Erro em #planos %s.\n ", nome_arquivo);

    if ((i = fread(&bpp, 2, 1, arquivo)) != 1)
		printf("Erro ao ler informações de bits/pixel em %s.\n ", nome_arquivo);

    if (bpp != 24)
		printf("Erro em bits/pixel: %s.\n ", nome_arquivo);

    // Dados da imagem
    fseek(arquivo, 24, SEEK_CUR);
    // 24 bits -> 3 bytes
    int tamanho_imagem = 3 * (imagem->largura * imagem->altura);
    imagem->dados = (char *) malloc(tamanho_imagem);

    if ((i = fread(imagem->dados, tamanho_imagem, 1, arquivo)) != 1)
		printf("Erro ao ler informações de pixels em %s.\n ", nome_arquivo);

    // BGR => RGB FIXME
	char B;
    for(i = 0; i < tamanho_imagem; i += 3)	{
		B = imagem->dados[i]; // B
		imagem->dados[i] = imagem->dados[i + 2]; // B <- R
		imagem->dados[i + 2] = B; // R <- B
    }
}
