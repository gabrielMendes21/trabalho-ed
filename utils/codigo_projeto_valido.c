#include <stdbool.h>

#include "../structs/TG.h"
#include "./codigo_projeto_valido.h"

bool codigo_projeto_valido(TG projetos[], int tamanho_vet, char *codigo_projeto)
{
    // converte char para inteiro
    int codigo_proj = atoi(codigo_projeto);
    // compara os valores de código projeto com todos os valores armazenados
    
    for(int i = 0; i < tamanho_vet; i++){
        if(codigo_proj == projetos[i].codigo){
            return true;
        }
    }
    return false;
}