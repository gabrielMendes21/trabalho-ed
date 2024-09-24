#ifndef SUSPENDER_VOTACAO_H
#define SUSPENDER_VOTACAO_H

#include <stdio.h>
#include <stdbool.h>

#include "../structs/Eleitor.h"

bool suspender_votacao(Eleitor comissao[], int *qtde_eleitores);

#endif