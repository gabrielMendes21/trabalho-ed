#include <stdio.h>
#include <stdbool.h>

#include "./cpf_pode_votar.h"

bool cpf_pode_votar(char *cpf, Eleitor comissao[], int qtde_eleitores) 
{
    // Lê cada CPF do arquivo e compara com o CPF inserido 
    for (int i = 0; i < qtde_eleitores; i++) {
        // Comparação com um CPF inserido
        if (strcmp(cpf, comissao[i].cpf) == 0) {
            printf("CPF encontrado! Pode votar.\n");
            return true;
        }
    }

    printf("CPF nao encontrado. Este CPF nao pode votar\n");
    return false;
}