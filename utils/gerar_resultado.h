#include <stdio.h>
#include <stdbool.h>

#ifndef GERAR_RESULTADO_H
#define GERAR_RESULTADO_H

bool gerar_resultado(TG projetos[], Eleitor comissao[], Aluno formandos[], int tamanho_vet)
{
    //abre o arquivo
    FILE *arquivo = fopen("resultado.txt", "w");
    //verifica se o arquivo foi criado
    if (arquivo == NULL){
        printf("Erro ao criar o arquivo\n");
        return false;
    }
    //escreve o número de votos em cada projeto
    fprintf(arquivo, "Resultado da votação:\n");
    for(int i = 0; i < tamanho_vet; i++){
        fprintf(arquivo, "Projeto: %s, votos: %d\n", projetos[i]. titulo, projetos[i].qtde_votos);
    }

    fclose(arquivo);

    return true;

}

#endif