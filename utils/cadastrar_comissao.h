#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "Eleitor.h"

#ifndef CADASTRAR_COMISSAO_H
#define CADASTRAR_COMISSAO_H

bool cadastrar_comissao(Eleitor comissao[], int *qtde_eleitores) {
    FILE *arquivo_comissao = fopen("comissao.txt", "r");
    if (arquivo_comissao == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return false;
    }

    int c;
  
    // Ler a quantidade de eleitores na primeira linha
    fscanf(arquivo_comissao, "%d", &c); // Use & para qtde_eleitores
    printf("Quantidade de eleitores: %d\n\n", c);

    // Ler os CPFs e preencher o vetor `comissao`
    for (int i = 0; i < c; i++) {
        fscanf(arquivo_comissao, "%s", comissao[*qtde_eleitores].cpf); // Lê o CPF
        comissao[*qtde_eleitores].votou = false;              // Inicializa como false
        comissao[*qtde_eleitores].codigo_TG = 0;  
        (*qtde_eleitores)++;// Inicializa como 0
    }

    fclose(arquivo_comissao);
    return true;
}

#endif
