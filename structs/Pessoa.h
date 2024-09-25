#ifndef PESSOA_H
#define PESSOA_H

#define MAX_NOME 60

typedef struct
{
    char nome[MAX_NOME];
    int idade;
} Pessoa;

#endif