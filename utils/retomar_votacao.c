#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "./retomar_votacao.h"
#include "../structs/TG.h"
#include "../structs/Eleitor.h"
#include "../structs/professor.h"
#include "../structs/aluno.h"
#include "./cadastrar_alunos.h"
#include "./cadastrar_professores.h"
#include "./cadastrar_projetos.h"
#include "./cadastrar_comissao.h"

#define MAX_CPF 15

// Função para retomar a votação
bool retomar_votacao(FILE *parcial_arquivo, TG listaPIs[], Eleitor comissao[], int *qtde_TGs, int *qtde_eleitores) 
{
    if (parcial_arquivo == NULL) {
        printf("Erro ao abrir o arquivo de votos parciais.\n");
        return false;
    }

    int num_votos = 0;

    fscanf(parcial_arquivo, "%d\n", &num_votos);

    for (int i = 0; i < num_votos; i++)
    {
        char cpf[MAX_CPF];
        int codigo_projeto;

        fscanf(parcial_arquivo, "%s %d", cpf, &codigo_projeto);

        for (int j = 0; j < *qtde_TGs; j++)
        {
            if (listaPIs[j].codigo == codigo_projeto)
            {
                listaPIs[j].qtde_votos++;
            }
        }

        for (int k = 0; k < *qtde_eleitores; k++)
        {
            if (strcmp(comissao[k].cpf, cpf) == 0)
            {
                comissao[k].votou = true;
                comissao[k].codigo_TG = codigo_projeto;
            }
        }
    }

    fclose(parcial_arquivo);
    return true;
}