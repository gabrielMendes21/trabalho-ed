#ifndef ALUNO_h
#define ALUNO_h

// Ano letivo o aluno 
#define ANO_LETIVO 3

typedef struct
{
    int codigo;
    int ano_letivo;
    char curso[3];
    int departamento;
    char *nome;
} aluno;

#endif