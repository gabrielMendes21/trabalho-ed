#ifndef COMPUTAR_VOTO_H
#define COMPUTAR_VOTO_H

#include <stdbool.h>

#include "../structs/Eleitor.h"
#include "../structs/TG.h"


bool computar_voto(TG projetos[], int *qtd_projetos, Eleitor *eleitor, char *codigo_projeto);

#endif