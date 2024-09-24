#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "./computar_voto.h"
#include "../structs/Eleitor.h"
#include "../structs/TG.h"


bool computar_voto(TG projetos[], int *qtd_projetos, Eleitor *eleitor, char *codigo_projeto)
{
    // Adicionar o CPF do eleitor e o código do Projeto (TG) votado 
    if(eleitor->votou){
        printf("Eleitor já votou!\n");
        return false;
    }

    eleitor->votou = true;
    eleitor->codigo_TG = atoi(codigo_projeto);

    // Incrementar a quantidade de votos do projeto
    for(int i = 0; i < *qtd_projetos; i++){
        if(projetos[i].codigo == atoi(codigo_projeto)){
            projetos[i].qtde_votos++;
        }
    }

    return true;
}