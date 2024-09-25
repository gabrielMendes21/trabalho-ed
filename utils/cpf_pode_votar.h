#ifndef CPF_PODE_VOTAR_H
#define CPF_PODE_VOTAR_H

#include <stdio.h>
#include <stdbool.h>

#include "../structs/Eleitor.h"

bool cpf_pode_votar(char *cpf, Eleitor comissao[], int qtde_eleitores);

#endif