#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../structs/TG.h"
#include "./cadastrar_projetos.h"

#define MAX 50
#define CURSOS 7

// Função para cadastrar projetos
bool cadastrar_projetos(TG listaProjetos[], char *cursos[], int *qtde_projetos) {
    for (int i = 0; i < CURSOS; i++)
    {
        // Passar por cada arquivo `PI_XXX.txt` e cadastrar os projetos
        char *prefixo = "arquivos_de_entrada/PI_";
        char *sufixo = cursos[i];
        char *tipo = ".txt";
        char *nome_do_arquivo = calloc(100, sizeof(char));

        strcat(nome_do_arquivo, prefixo);
        strcat(nome_do_arquivo, sufixo);
        strcat(nome_do_arquivo, tipo);

        printf("%s\n", nome_do_arquivo);

        FILE *projeto = fopen(nome_do_arquivo, "r");

        if (projeto == NULL)
        {
            printf("Erro ao abrir %s\n", nome_do_arquivo);
            continue;
        }

        int codigo, codigo_autor, codigo_orientador;
        char titulo[MAX];

        // Lê o número de projetos no arquivo
        int num_projetos;
        fscanf(projeto, "%d", &num_projetos);

        // Para cada projeto no arquivo
        for (int i = 0; i < num_projetos; i++) {
            fscanf(projeto, "%d %d %d %[^\n]s", &codigo, &codigo_autor, &codigo_orientador, titulo);

            if (*qtde_projetos >= MAX) {
                printf("Limite máximo de projetos cadastrados atingido.\n");
                return false;
            }

            // Armazena os dados no array de projetos
            listaProjetos[*qtde_projetos].codigo = codigo;
            listaProjetos[*qtde_projetos].codigo_autor = codigo_autor;
            listaProjetos[*qtde_projetos].codigo_orientador = codigo_orientador;
            strcpy(listaProjetos[*qtde_projetos].titulo, titulo);

            (*qtde_projetos)++;
        }

        fclose(projeto);
    }

    return true;
}