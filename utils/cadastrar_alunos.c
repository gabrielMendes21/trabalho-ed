#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastrar_alunos.h"
#include "../structs/Aluno.h"

bool cadastrar_alunos(Aluno alunos[], int *qtde_alunos)
{
    // TODO
    // Ler o arquivo `aluno.txt` e criar um dado do tipo `Aluno` para cada um
    // Não se esqueca de atualizar a quantidade de alunos no vetor
    
    // Abertura do arquivo
    FILE *file = fopen("./arquivos_de_entrada/aluno.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return false;
    }

    int numero_alunos;
    fscanf(file, "%d\n", &numero_alunos);  // Leitura da primeira linha

    // Leitura dos dados de cada aluno
    for (int i = 0; i < numero_alunos; i++) {
        char linha[100];

        // Lê uma linha inteira do arquivo
        if (fgets(linha, sizeof(linha), file) != NULL) {
            // Usamos sscanf para fazer o parsing da linha
            sscanf(linha, "%d %d %s %d %[^\n]",
                   &alunos[i].matricula,
                   &alunos[i].ano_letivo,
                   alunos[i].dpto,
                   &alunos[i].pes.idade,
                   alunos[i].pes.nome);
        }

        (*qtde_alunos)++;
    }

    fclose(file);
    return true;
}