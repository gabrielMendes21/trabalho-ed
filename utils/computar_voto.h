#ifndef COMPUTAR_VOTO_H
#define COMPUTAR_VOTO_H

#include <stdbool.h>

#include "Eleitor.h"
#include "TG.h"


bool computar_voto(TG projetos[], int *qtd_projetos, Eleitor *eleitor, int codigo_projeto);

#endif