#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CPF 15
#define MAX_NOME 60
#define MAX_SIGLA 10
#define MAX 50

// Menus
#include "./menus/menu1.h"
#include "./menus/menu2.h"

// Utils
#include "./utils/validar_CPF.h"
#include "cpf_pode_votar.h"
#include "codigo_projeto_valido.h"

// Structs
#include "./structs/Pessoa.h"
#include "./structs/Professor.h"
#include "./structs/Aluno.h"
#include "./structs/Projeto_integrador.h"
#include "./structs/TG.h"
#include "./structs/Eleitor.h"


Professor docentes[MAX];
int qtde_docentes;

Aluno formandos[MAX];
int qtde_formandos;

Projeto_integrador listaPIs[MAX];
int qtde_TGs;

Eleitor comissao[MAX];
int qtde_eleitores;

int main(void) 
{
    char menu1_op, menu2_op;

    // Mostra o menu enquanto o usuário não digitar a opção correta
    do
    {
        // Mostrar o menu1
        menu1();
        scanf("%c", &menu1_op);
    } while(menu1_op != 'A' && menu1_op != 'a' && menu1_op != 'B' && menu1_op != 'b');

    if (menu1_op == 'a' || menu1_op == 'A')
    {
        // Caso a opção seja a `a) Iniciar nova votação`:
        do 
        {
            // Mostre o menu2
            menu2();
            scanf("%c", &menu2_op);
        } while(menu2_op != 'A' && menu2_op != 'a' && menu2_op != 'B' && menu2_op != 'b' && menu2_op != 'C' && menu2_op != 'c');

        if (menu2_op == 'a' || menu2_op == 'A')
        {
            // Caso a opção seja `a) Entrar com voto`:

            // TODO:
            // Solicitar o CPF
            char cpf;

            FILE *comissao = fopen("comissao.txt", "r");

            if (comissao == NULL)
            {
                printf("Arquivo `comissao.txt` não existe. Crie o arquivo, insira os CPF's que podem votar e tente novamente\n");
                return 1;
            }

            // Solicitar o CPF
            do 
            {
                printf("Digite o CPF: ");
                scanf("%s", &cpf);
            } while(!validar_CPF(cpf) || !cpf_pode_votar(cpf, comissao));

            // Se o CPF for válido, peça para o usuário digitar o código do projeto no qual ele quer votar

            // Solicitar o código do projeto
            char *codigo_projeto;
            
            do
            {
                printf("Digite o código do projeto: ");
                scanf("%s", codigo_projeto);
            } while (!codigo_projeto_valido(codigo_projeto));
            

            // Checar se o código do projeto é válido
            if (codigo_projeto_valido(codigo_projeto))
            {
                // TODO: Caso seja válido, o projeto recebe mais um voto e o voto dado por esse CPF é registrado em `parcial.txt`
            }
        }
        else if (menu2_op == 'b' || menu2_op == 'B')
        {
            // Caso a opção seja `b) Suspender votação`:

            // TODO:
            // Gere o arquivo `parcial.txt` com todos os votos até o momento
        } 
        else if (menu2_op == 'c' || menu2_op == 'C')
        {
            // Caso a opção seja `c) Concluir votação`:
            
            // TODO:
            // Gere o arquivo `resultado.txt` com o resultado baseado nos votos até o momento
        }

        
        
        
    } 
    else if (menu1_op == 'b' || menu1_op == 'B')
    {
        // TODO: caso a opção seja a `b) Continuar votação gravada`:
            // Leia o arquivo `parcial.txt`
            // Se ele não existir, informe o problema e volte para o menu1
    }
}