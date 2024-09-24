#include <stdio.h>
#include <stdbool.h>

#include "./cpf_pode_votar.h"

bool cpf_pode_votar(char *cpf, FILE *arquivo_comissao) 
{
    int qtd_Cpfs;
    char cpfLido[15]; // Variável para armazenar cada CPF lido

    // Lê a primeira linha com a quantidade de CPFs
    fscanf(arquivo_comissao, "%i", &qtd_Cpfs);

    // Lê cada CPF do arquivo e compara com o CPF inserido 
    for (int i = 0; i < qtd_Cpfs; i++) {
        fscanf(arquivo_comissao, "%s", cpfLido); // Lê o CPF da linha

        // Comparação com um CPF inserido
        if (strcmp(cpf, cpfLido) == 0) {
            printf("CPF encontrado! Pode votar.\n");
            fclose(arquivo_comissao);
            return true;
        }
    }

    printf("CPF nao encontrado. Este CPF nao pode votar\n");
    fclose(arquivo_comissao);
    return false;
}