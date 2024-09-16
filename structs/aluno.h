#ifndef ALUNO_h
#define ALUNO_h

// Ano letivo do aluno 
#define ANO_LETIVO 3

typedef struct Aluno
{
    Pessoa pes;
    int matricula;
    int ano_letivo;
    char dpto[MAX_SIGLA];
} Aluno;

#endif