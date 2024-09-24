#include <stdbool.h>

#include "./cpf_ja_votou.h"
#include "../structs/Eleitor.h"

bool cpf_ja_votou(Eleitor comissao[], char cpf[], int qtde_eleitores)
{
    for (int i = 0; i < qtde_eleitores; i++)
    {
        if (comissao[i].cpf == cpf)
        {
            if (comissao[i].votou)
            {
                printf("Este cpf já votou. Por favor, digite outro\n");
                return true;
            }
        }
    }

    return false;
}