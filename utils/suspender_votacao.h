#ifndef SUSPENDER_VOTACAO_H
#define SUSPENDER_VOTACAO_H

#include <stdio.h>
#include <stdbool.h>

#include "../structs/Eleitor.h"


bool suspender_votacao(Eleitor comissao[], int *qtdeEleitores)
{
    FILE *parcial;

    int votos;
  
    // Conta quantos eleitores já votaram
    for (int i = 0; i < *qtdeEleitores; i++) {
        if (comissao[i].votou) {
            votos++;
        }
    }

    // Escreve a quantidade de votos no início do arquivo
    fprintf(parcial, "%d\n", votos);

    // Escreve o CPF e o código do TG de quem votou
    for (int i = 0; i < *qtdeEleitores; i++) {
        if (comissao[i].votou) {
            fprintf(parcial, "%s %d\n", comissao[i].cpf, comissao[i].codigo_TG);
        }
    }
  
    // Fecha o arquivo
    fclose(parcial);
    return true;
}

#endif
