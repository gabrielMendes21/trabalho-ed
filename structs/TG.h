#ifndef TG_H
#define TG_H

#define MAX_NOME 60
typedef struct
{
    int codigo;
    int codigo_autor;
    int codigo_orientador;
    char titulo[MAX_NOME];
    int qtde_votos;
} TG;

#endif