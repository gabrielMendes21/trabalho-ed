#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "Eleitor.h"
#include "TG.h"

#ifndef COMPUTAR_VOTO_H
#define COMPUTAR_VOTO_H


bool computar_voto(TG projetos[], int *qtd_projetos, Eleitor *eleitor, int codigo_projeto)
{
    // Adicionar o CPF do eleitor e o código do Projeto (TG) votado 
    if(eleitor->votou){
        printf("Eleitor já votou!\n");
        return false;
    }

    eleitor->votou = true;
    eleitor->codigo_TG = codigo_projeto;

    // Incrementar a quantidade de votos do projeto
    for(int i = 0; i < *qtd_projetos; i++){
        if(projetos[i].codigo == codigo_projeto){
            projetos[i].qtde_votos++;
        }
    }

    return true;
}

#endif