#include <stdio.h>
#include <stdbool.h>

#include "./suspender_votacao.h"
#include "../structs/Eleitor.h"

bool suspender_votacao(Eleitor comissao[], int *qtde_eleitores) {
    FILE *arquivo;
    int votos = 0;

    // Abre o arquivo `parcial.txt` para escrita
    arquivo = fopen("parcial.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo parcial.txt\n");
        return false;
    }

    // Conta quantos eleitores já votaram
    for (int i = 0; i < *qtde_eleitores; i++) {
        if (comissao[i].votou) {
            votos++;
        }
    }

    // Escreve a quantidade de votos no início do arquivo
    fprintf(arquivo, "%d\n", votos);

    // Escreve o CPF e o código do TG de quem votou
    for (int i = 0; i < *qtde_eleitores; i++) {
        if (comissao[i].votou) {
            fprintf(arquivo, "%s %d\n", comissao[i].cpf, comissao[i].codigo_TG);
        }
    }

    // Fecha o arquivo
    fclose(arquivo);
    return true;
}