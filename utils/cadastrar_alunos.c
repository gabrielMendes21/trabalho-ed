#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para a função getcwd

#include "cadastrar_alunos.h"
#include "../structs/Aluno.h"

bool cadastrar_alunos(Aluno alunos[], int *qtde_alunos)
{
    // TODO
    // Ler o arquivo `aluno.txt` e criar um dado do tipo `Aluno` para cada um
    // Não se esqueca de atualizar a quantidade de alunos no vetor
    
    // Abertura do arquivo
    FILE *alunos_arquivo = fopen("./arquivos_de_entrada/aluno.txt", "r");

    if (alunos_arquivo == NULL)
    {
        printf("Erro ao carregar arquivo\n");
        return false;
    }

    int numero_alunos, id;
    char curso[3];
    
    // Leitura dos dados do arquivo
    fscanf(alunos_arquivo, "%i", &numero_alunos);
    fscanf(alunos_arquivo, "%i", &id);
    fscanf(alunos_arquivo, "%s", curso);

    printf("%s\n", curso);
    return true;
}