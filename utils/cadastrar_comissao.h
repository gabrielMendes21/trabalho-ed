#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifndef CADASTRAR_COMISSAO_H
#define CADASTRAR_COMISSAO_H

typedef struct {
    char cpf[15]; // Considerando que o CPF tem 14 caracteres + '\0'
} Eleitor;

bool cadastrar_comissao(Eleitor comissao[], int *qtde_eleitores) {
    FILE *file = fopen("comissao.txt", "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return false;
    }

    // Ignorar a primeira linha
    char linha[256];
    if (fgets(linha, sizeof(linha), file) == NULL) {
        fclose(file);
        return false;
    }

    // Ler cada CPF e criar um Eleitor
    while (fgets(linha, sizeof(linha), file) != NULL) {
        // Remover o caractere de nova linha
        linha[strcspn(linha, "\n")] = 0;

        // Criar um novo eleitor
        Eleitor novo_eleitor;
        strncpy(novo_eleitor.cpf, linha, sizeof(novo_eleitor.cpf));

        // Adicionar ao vetor
        comissao[*qtde_eleitores] = novo_eleitor;
        (*qtde_eleitores)++;
    }

    fclose(file);
    return true;
}

#endif
