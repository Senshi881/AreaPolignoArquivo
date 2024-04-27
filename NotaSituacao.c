/*
O programa a ser construído deve ler dados de cada aluno, identificando o nome e as notas para,  a seguir, 
determinar a nota média e a situação final do aluno (APROVADO, caso a nota média seja maior ou igual a 7.0 ou REPROVADO, caso a nota média seja menor do que 7.0). 
Por fim, deve ser gerado um arquivo chamado SituacaoFinal.csv em que cada linha deverá ter o nome do aluno, a nota média com duas casas decimais e a situação do aluno. 
Por exemplo, para a aluna 
Maria Oliveira, cujas notas foram 9.0 e 9.3, deverá ser gravado no arquivo de saída:
Maria Oliveira, 9.15, APROVADO

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[1024];
    int prefixo, telefone, telefone1;
    char curso[1024];
    float nota1;
    float nota2;
} Aluno;

void alunoM(char nome[1024], float n1, float n2, FILE *arquivoSituacaoFinal);

int main() {
    FILE *arquivo, *arquivoSituacaoFinal;
    int i = 0;
    system("cls");

    arquivo = fopen("DadosEntrada.csv", "r");
    arquivoSituacaoFinal = fopen("SituacaoFinal.csv", "w");

    if (arquivo == NULL || arquivoSituacaoFinal == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO");
        exit(1);
    }

    Aluno aluno[95];
    while(fscanf(arquivo, "%[^,], (%d) %d-%d,%[^,],%f,%f\n", aluno[i].nome, &aluno[i].prefixo, &aluno[i].telefone, &aluno[i].telefone1, aluno[i].curso, &aluno[i].nota1, &aluno[i].nota2) != EOF) {
        alunoM(aluno[i].nome, aluno[i].nota1, aluno[i].nota2, arquivoSituacaoFinal);
        i++;
    }

    fclose(arquivo);
    fclose(arquivoSituacaoFinal);

    return 0;
}

void alunoM(char nome[1024], float n1, float n2, FILE *arquivoSituacaoFinal) {
    float mF = (n1 + n2) / 2; // Média Final
    if (mF >= 7) {
        fprintf(arquivoSituacaoFinal, "%s, %.2f, APROVADO\n", nome, mF);
        printf("%s, %.2f, APROVADO\n", nome, mF);
    } else {
        fprintf(arquivoSituacaoFinal, "%s, %.2f, REPROVADO\n", nome, mF);
        printf("%s, %.2f, REPROVADO\n", nome, mF);
    }
}