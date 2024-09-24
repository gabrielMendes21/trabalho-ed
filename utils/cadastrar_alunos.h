#ifndef CADASTRAR_ALUNOS_H
#define CADASTRAR_ALUNOS_H

#define MAX_NOME 60

#include <stdbool.h>
#include "../structs/aluno.h"

bool cadastrar_alunos(Aluno alunos[], int *qtde_alunos, char *cursos[]);
#endif