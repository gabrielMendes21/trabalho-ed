#ifndef CPF_JA_VOTOU_H
#define CPF_JA_VOTOU_H

#include <stdbool.h>

#include "../structs/Eleitor.h"

bool cpf_ja_votou(Eleitor comissao[], char cpf[], int qtde_eleitores);

#endif