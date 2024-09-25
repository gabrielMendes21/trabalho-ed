#include <stdbool.h>

#include "./cpf_ja_votou.h"
#include "../structs/Eleitor.h"

bool cpf_ja_votou(Eleitor comissao[], char cpf[], int qtde_eleitores)
{
    for (int i = 0; i < qtde_eleitores; i++)
    {
        if (strcmp(comissao[i].cpf, cpf) == 0)
        {
            if (comissao[i].votou)
            {
                printf("Este cpf ja votou. Por favor, digite outro\n");
                return true;
            }
        }
    }

    return false;
}