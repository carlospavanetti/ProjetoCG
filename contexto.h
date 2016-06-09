struct {
    int topo;
    GLdouble matrizes[100][3][3];
} PILHA;

void EmpilharMatriz() {
    COPIAR_MATRIZES(PILHA.matrizes[PILHA.topo], TRANSFORMACAO_MODELO);
    PILHA.topo++;
    if (PILHA.topo >= 100) printf("Por favor, empilhar somente 100 matrizes\n");
}

void DesempilharMatriz() {
    if (PILHA.topo <= 0) {
        printf("Não há matriz para desempilhar\n");
        return;
    }

    PILHA.topo--;
    COPIAR_MATRIZES(TRANSFORMACAO_MODELO, PILHA.matrizes[PILHA.topo]);
}
