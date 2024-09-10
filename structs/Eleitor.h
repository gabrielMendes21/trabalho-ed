#ifndef ELEITOR_H
#define ELEITOR_H

typedef struct
{
    char cpf[MAX_CPF];
    bool votou;
    int codigo_TG;
} Eleitor;

#endif