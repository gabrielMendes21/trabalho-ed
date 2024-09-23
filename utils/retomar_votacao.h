#ifndef RETOMAR_VOTACAO_H
#define RETOMAR_VOTACAO_H

#include <stdio.h>
#include <stdbool.h>

#include "../structs/TG.h"
#include "../structs/Eleitor.h"

bool retomar_votacao(FILE *parcial_arquivo, TG listaPIs[], Eleitor comissao[], int *qtde_TGs, int *qtde_eleitores);

#endif