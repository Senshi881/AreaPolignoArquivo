#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float AreaTriangulo(Ponto A, Ponto B, Ponto C);

int main() {
    FILE *arquivo;
    int vertices;
    float areaTotal = 0.0;
    system("cls");

    arquivo = fopen("trianguloABC.txt", "r");
    if (arquivo == NULL) {
        printf("ARQUIVO NÃO ENCONTRADO");
        exit(1);
    }

    fscanf(arquivo, "%d", &vertices);

    Ponto pontos[vertices];

    for (int i = 0; i < vertices; i++) {
        fscanf(arquivo, "%f %f", &pontos[i].X, &pontos[i].Y);
    }

    fclose(arquivo);

    for (int i = 1; i < vertices - 1; i++) {
        areaTotal += AreaTriangulo(pontos[0], pontos[i], pontos[i+1]);
    }

    printf("A área do polígono é %.2f\n", areaTotal);

    return 0;
}

float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return fabs((A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2);
}
