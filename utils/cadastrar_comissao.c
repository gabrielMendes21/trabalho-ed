#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "./cadastrar_comissao.h"
#include "../structs/Eleitor.h"

bool cadastrar_comissao(Eleitor comissao[], int *qtde_eleitores) {
    FILE *arquivo_comissao = fopen("arquivos_de_entrada/comissao.txt", "r");
    if (arquivo_comissao == NULL) {
        printf("Erro ao abrir o arquivo comissao.txt\n");
        return false;
    }

    int c;
  
    // Ler a quantidade de eleitores na primeira linha
    fscanf(arquivo_comissao, "%d", &c); // Use & para qtde_eleitores

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