#ifndef PROFESSOR_h
#define PROFESSOR_h

#include "./Pessoa.h"
typedef struct
{
    Pessoa pes;
    int codigo;
    char dpto[MAX_SIGLA];
} Professor;

#endif