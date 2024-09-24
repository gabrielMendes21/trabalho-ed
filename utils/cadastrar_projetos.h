#ifndef CADASTRAR_PROJETOS_H
#define CADASTRAR_PROJETOS_H

#include <stdbool.h>

#include "../structs/TG.h"

bool cadastrar_projetos(TG listaProjetos[], Aluno alunos[], char *cursos[], int *qtde_projetos, int qtde_alunos);

#endif