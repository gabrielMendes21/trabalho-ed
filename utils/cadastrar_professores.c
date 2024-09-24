#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cadastrar_professores.h"



bool cadastrar_professores(Professor profs[], int *qtde_profs) {
    // Abertura do arquivo
    FILE *file = fopen("./arquivos_de_entrada/professores.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo professor.txt\n");
        return false;
    }

    // Inicializa a contagem de professores
    *qtde_profs = 0;
    fscanf(file, "%d\n", qtde_profs);


for (int i = 0; i < *qtde_profs; i++) {
        char linha[100];

        // Lê uma linha inteira do arquivo
        if (fgets(linha, sizeof(linha), file) != NULL) {
            // Usamos sscanf para fazer o parsing da linha
            sscanf(linha, "%d %d %s %d %[^\n]",
                   &profs[i].codigo,
                   profs[i].dpto,
                   &profs[i].pes.idade,
                   profs[i].pes.nome);
        }

        (*qtde_profs)++;
    }

    fclose(file);
    return true;
}
