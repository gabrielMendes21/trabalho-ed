#ifndef GERAR_RESULTADO_H
#define GERAR_RESULTADO_H

#include <stdio.h>
#include <stdbool.h>

#include "../structs/aluno.h"
#include "../structs/TG.h"
#include "../structs/Eleitor.h"
#include "../structs/professor.h"

bool gerar_resultado(TG projetos[], Eleitor comissao[], Aluno formandos[], Professor prof[], int tamanho_proj, int tamanho_eleitor, int tamanho_aluno, int tamanho_professor);

#endif