#ifndef SUSPENDER_VOTACAO_H
#define SUSPENDER_VOTACAO_H

#include <stdio.h>
#include <stdbool.h>


extern int qtdeEleitores;  // Quantidade de eleitores

// Estrutura do Eleitor, já definida em algum lugar do seu código principal
typedef struct {
    char cpf[15];  // CPF do eleitor
    bool votou;    // true se já votou; false se não votou
    int codigoTG;  // Código do TG votado (0 se não votou)
} Eleitor;

bool codigo_projeto_valido(Eleitor comissao[]) {
    FILE *arquivo;
    int votos = 0;

    // Abre o arquivo `parcial.txt` para escrita
    arquivo = fopen("parcial.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo parcial.txt\n");
        return false;
    }

    // Conta quantos eleitores já votaram
    for (int i = 0; i < qtdeEleitores; i++) {
        if (comissao[i].votou) {
            votos++;
        }
    }

    // Escreve a quantidade de votos no início do arquivo
    fprintf(arquivo, "%d\n", votos);

    // Escreve o CPF e o código do TG de quem votou
    for (int i = 0; i < qtdeEleitores; i++) {
        if (comissao[i].votou) {
            fprintf(arquivo, "%s %d\n", comissao[i].cpf, comissao[i].codigoTG);
        }
    }

    // Fecha o arquivo
    fclose(arquivo);
    return true;
}

#endif