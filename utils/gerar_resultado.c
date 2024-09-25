#include <stdio.h>
#include <stdbool.h>

#include "./gerar_resultado.h"
#include "../structs/aluno.h"
#include "../structs/TG.h"
#include "../structs/Eleitor.h"
#include "../structs/professor.h"

bool gerar_resultado(TG projetos[], Eleitor comissao[], Aluno formandos[], Professor prof[], int tamanho_proj, int tamanho_eleitor, int tamanho_aluno, int tamanho_professor)
{
   
   TG projeto_mais_votado = projetos[0];

   int mais_votado = 0;

    // Procura projeto mais votado
    for (int i = 0; i < tamanho_proj; i++) {
        if (projetos[i].qtde_votos > mais_votado) 
        {
            mais_votado = projetos[i].qtde_votos;
        }
    }

    // Abre o arquivo
    FILE *arquivo = fopen("arquivos_de_saida/resultado.txt", "w");
    //verifica se o arquivo foi criado
    if (arquivo == NULL){
        printf("Erro ao criar o arquivo\n");
        return false;
    }

    for (int i = 0; i < tamanho_proj; i++) {
        if (projetos[i].qtde_votos == mais_votado) {
            projeto_mais_votado = projetos[i];

            Eleitor presentes[tamanho_eleitor];
            Eleitor ausentes[tamanho_eleitor];
            int num_presentes = 0;
            int num_ausentes = 0;
            // procura eleitores presentes e ausentes
            for (int j = 0; j < tamanho_eleitor; j++) {
                if (comissao[j].votou) {
                    presentes[num_presentes++] = comissao[j]; // Armazena o eleitor presente
                } else {
                    ausentes[num_ausentes++] = comissao[j]; // Armazena o eleitor ausente
                }
            }

            Aluno aluno_vencedor = formandos[0];

            // Procura o aluno vencedor pelo código
            for(int k = 0; k < tamanho_aluno; k++){
                if(projeto_mais_votado.codigo_autor == formandos[i].matricula){
                    aluno_vencedor = formandos[k];
                }
            } 

            Professor professor_vencedor = prof[0];

            // Procura orientador do projeto vencedor pelo código
            for(int c = 0; c < tamanho_professor; c++) {
                if(projeto_mais_votado.codigo_orientador == prof[c].codigo){
                    professor_vencedor = prof[c];
                }
            }

            fprintf(arquivo, "PI VENCEDOR\n");
            fprintf(arquivo, "Codigo: %d\n", projeto_mais_votado.codigo);
            fprintf(arquivo, "Titulo: %s\n", projeto_mais_votado.titulo);
            fprintf(arquivo, "Aluno: %s\n", aluno_vencedor.pes.nome);
            fprintf(arquivo, "Curso aluno: %s\n", aluno_vencedor.dpto);
            fprintf(arquivo, "Orientador: %s\n", professor_vencedor.pes.nome);
            fprintf(arquivo, "Depto orientador: %s\n", professor_vencedor.dpto);

            fprintf(arquivo, "\nEleitores presentes:\n");
            for(int l = 0; l < num_presentes; l++){
                fprintf(arquivo, "%s\n",presentes[l].cpf);
            }

            fprintf(arquivo, "\n");

            fprintf(arquivo, "Eleitores ausentes:\n");
            for(int m = 0; m < num_ausentes; m++){
                fprintf(arquivo, "%s\n", ausentes[m].cpf);
            }

            fprintf(arquivo, "\n");
            fprintf(arquivo, "\n");
            fprintf(arquivo, "\n");
        }

    }

    fclose(arquivo);    

    return true;

}