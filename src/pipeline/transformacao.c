//
// double *TransformarVertices(double *vertices, int quantidade) {
//     double *transformados;
//     Matriz *MVM = Modelo();
//
//     int tamanho_array = 4 * quantidade / 3;
//     transformados = (double *) malloc(tamanho_array * sizeof(double));
//
//     int v, _3v, _4v, i, j;
//     for (v = 0; v < quantidade; v++) {
//         _4v = v << 2;
//         _3v = _4v - v;
//
//         for (i = 0; i < 3; ++i) {
//             transformados[_4v + i] = 0;
//             for (j = 0; j < 3; ++j)
//                 transformados[_4v + i] += em(MVM, i, j) * vertices[_3v + j];
//             transformados[v + i] += em(MVM, i, 3);
//         }
//         transformados[_4v + 3] = 1;
//     }
//
//     return transformados;
// }
