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
bool retomar_votacao(FILE *parcial_arquivo, TG listaPIs[], Eleitor comissao[], Professor docentes[], Aluno formandos[], int *qtde_TGs, int *qtde_eleitores, int *qtde_docentes, int *qtde_formandos, char *cursos[]) {
    if (parcial_arquivo == NULL) {
        printf("Erro ao abrir o arquivo de votos parciais.\n");
        return false;
    }

    // Recarregar os dados necessários
    cadastrar_professores(docentes, qtde_docentes);
    cadastrar_alunos(formandos, qtde_formandos);
    cadastrar_projetos(listaPIs, cursos, qtde_TGs);
    cadastrar_comissao(comissao, qtde_eleitores);

    char cpf[MAX_CPF];
    int codigo_TG;
    int votos_parciais;

    // Lê os votos parciais do arquivo
    while (fscanf(parcial_arquivo, "%s %d %d", cpf, &codigo_TG, &votos_parciais) != EOF) {
        // Atualiza o voto do eleitor na comissão
        for (int i = 0; i < *qtde_eleitores; i++) {
            if (strcmp(comissao[i].cpf, cpf) == 0 && !comissao[i].votou) {
                comissao[i].votou = true;
                comissao[i].codigo_TG = codigo_TG;
                break;
            }
        }

        // Atualiza a quantidade de votos do TG correspondente
        for (int j = 0; j < *qtde_TGs; j++) {
            if (listaPIs[j].codigo == codigo_TG) {
                listaPIs[j].qtde_votos += votos_parciais;
                break;
            }
        }
    }

    fclose(parcial_arquivo);
    return true;
}