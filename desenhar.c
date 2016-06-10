void DesenharTriangulos(double *vertices, int quantidade) {
    double *vertices_transformados = TransformarVertices(vertices, quantidade);
}

double *TransformarVertices(double *vertices, int quantidade) {
    double *vertices_transformados;

    int tamanho_array = 4 * quantidade / 3;
    vertices_transformados = (double *) malloc(tamanho_array * sizeof(double));

    double w;
    for (v = 0; v < tamanho_array; v += 4) {
        for (i = 0; i < 3; ++i) {
            vertices_transformados[v + i] = 0;
            for (j = 0; j < 3; ++j)
                vertices_transformados[v + i] += em(MVM, i, j) * vertice[v + j];
            vertices_transformados[v + i] += em(MVM, i, 3);
        }
        vertices_transformados[v + 3] = 1;
    }

    return vertices_transformados;
}
