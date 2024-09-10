#ifndef ALUNO_h
#define ALUNO_h

// Ano letivo o aluno 
#define ANO_LETIVO 3

typedef struct
{
    Pessoa pes;
    int matricula;
    int ano_letivo;
    char dpto[MAX_SIGLA];
} Aluno;

#endif