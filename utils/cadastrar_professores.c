#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cadastrar_professores.h"



bool cadastrar_professores(Professor profs[], int *qtde_profs) {
    // Abertura do arquivo
    FILE *file = fopen("arquivos_de_entrada/professor.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo professor.txt\n");
        return false;
    }

    // Inicializa a contagem de professores
    int c;
    fscanf(file, "%d\n", &c);


    for (int i = 0; i < c; i++) {
        char linha[100];

        // Lê uma linha inteira do arquivo
        if (fgets(linha, sizeof(linha), file) != NULL) 
        {
            // Usamos sscanf para fazer o parsing da linha
            sscanf(linha, "%d %d %s %d %[^\n]",
                   &profs[*qtde_profs].codigo,
                   profs[*qtde_profs].dpto,
                   &profs[*qtde_profs].pes.idade,
                   profs[*qtde_profs].pes.nome);
        }

        (*qtde_profs)++;
    }

    fclose(file);
    return true;
}
