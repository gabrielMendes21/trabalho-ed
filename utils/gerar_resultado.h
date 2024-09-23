#include <stdio.h>
#include <stdbool.h>

#ifndef GERAR_RESULTADO_H
#define GERAR_RESULTADO_H

#include "../structs/aluno.h"
#include "../structs/TG.h"
#include "../structs/Eleitor.h"
#include "../structs/professor.h"

bool gerar_resultado(TG projetos[], Eleitor comissao[], Aluno formandos[], Professor prof[], int tamanho_proj, int tamanho_eleitor, int tamanho_aluno, int tamanho_professor)
{
   
   TG projeto_mais_votado = projetos[0];
    // procura projeto mais votado
    for (int i = 1; i < tamanho_proj; i++) {
        if (projetos[i].qtde_votos > projeto_mais_votado.qtde_votos) {
            projeto_mais_votado = projetos[i];
        }
    }

    Eleitor presentes[tamanho_eleitor];
    Eleitor ausentes[tamanho_eleitor];
    int num_presentes = 0;
    int num_ausentes = 0;
    // procura eleitores presentes e ausentes
    for (int i = 0; i < tamanho_eleitor; i++) {
        if (comissao[i].votou) {
            presentes[num_presentes++] = comissao[i]; // Armazena o eleitor presente
        } else {
            ausentes[num_ausentes++] = comissao[i]; // Armazena o eleitor ausente
        }
    }

    Aluno aluno_vencedor = formandos[0];
    //procura o aluno vencedor pelo código
    for(int i = 1; i < tamanho_aluno; i++){
        if(projeto_mais_votado.codigo_autor == formandos[i].matricula){
            aluno_vencedor = formandos[i];
        }
    } 

    Professor professor_vencedor = prof[0];
    // procura orientador do projeto vencedor pelo código
    for(int i = 1; i< tamanho_professor; i++){
        if(projeto_mais_votado.codigo_orientador==prof[i].codigo){
            professor_vencedor = prof[i];
        }
    }

    //abre o arquivo
    FILE *arquivo = fopen("resultado.txt", "w");
    //verifica se o arquivo foi criado
    if (arquivo == NULL){
        printf("Erro ao criar o arquivo\n");
        return false;
    }

    fprintf(arquivo, "PI VENCEDOR\n");
    fprintf(arquivo, "Codigo: %d\n", projeto_mais_votado.codigo);
    fprintf(arquivo, "Titulo: %s\n", projeto_mais_votado.titulo);
    fprintf(arquivo, "Aluno: %s\n", aluno_vencedor.pes.nome);
    fprintf(arquivo, "Curso aluno: %s\n", aluno_vencedor.dpto);
    fprintf(arquivo, "Orientador: %s\n", professor_vencedor.pes.nome);
    fprintf(arquivo, "Depto orientador: %s\n", professor_vencedor.dpto);

    for(int i = 0; i < num_presentes; i++){
      fprintf(arquivo, "Eleitores presentes: %s\n",presentes[i].cpf);
    }
     for(int i = 0; i < num_ausentes; i++){
      fprintf(arquivo, "Eleitores ausentes: %s\n",ausentes[i].cpf);
    }


    fclose(arquivo);

    return true;

}

#endif