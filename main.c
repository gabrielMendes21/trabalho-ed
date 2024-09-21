#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CPF 15
#define MAX_NOME 60
#define MAX_SIGLA 10
#define MAX 50

// Menus
#include "./menus/menu1.h"
#include "./menus/menu2.h"

// Utils
#include "./utils/validar_CPF.c"
#include "./utils/cpf_pode_votar.c"
// #include "./utils/codigo_projeto_valido.c"
// #include "./utils/computar_voto.c"
// #include "./utils/suspender_votacao.c"
// #include "./utils/gerar_resultado.c"
// #include "./utils/retomar_votacao.c"

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

// Projeto_integrador listaPIs[MAX];
TG listaPIs[MAX];
int qtde_TGs;

Eleitor comissao[MAX];
int qtde_eleitores;

int main(void)
{
    char menu1_op, menu2_op;

    char siglas[7][4] = {"AMS", "ADS", "DSM", "CEX", "EMP", "LOG", "POL",};  

    // Chamar as seguintes funções para ler os arquivos de entrada e cadastrar os dados nos vetores acima
    cadastrar_professores(docentes, &qtde_docentes); // TODO: completar a função
    cadastrar_alunos(formandos, &qtde_formandos); // TODO: completar a função
    cadastrar_projetos(listaPIs, siglas, &qtde_TGs); // TODO: completar a função
    cadastrar_comissao(comissao, &qtde_eleitores); // TODO: completar a função

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

            FILE *comissao_arquivo = fopen("comissao.txt", "r");

            if (comissao_arquivo == NULL)
            {
                printf("Arquivo `comissao.txt` não existe. Crie o arquivo, insira os CPF's que podem votar e tente novamente\n");
                return 1;
            }

            // Solicitar o CPF
            char cpf[15];
            do 
            {
                printf("Digite o CPF: ");
                scanf("%s", &cpf);
            } while(!validar_CPF(cpf) || !cpf_pode_votar(cpf, comissao_arquivo)); // TODO: completar ambas as funções

            // Se o CPF for válido, peça para o usuário digitar o código do projeto no qual ele quer votar

            // Solicitar o código do projeto
            char *codigo_projeto;
            
            do
            {
                printf("Digite o código do projeto: ");
                scanf("%s", codigo_projeto);
            } while (!codigo_projeto_valido(listaPIs, codigo_projeto)); // TODO: completar a função
            
            // Caso o código do projeto seja válido, o projeto recebe mais um voto e o CPF em questão não pode votar novamente
            Eleitor *eleitor;
            for (int i = 0; i < qtde_eleitores; i++)
            {
                if (comissao[i].cpf == cpf)
                {
                    eleitor = &comissao[i];
                }
            }

            computar_voto(listaPIs, eleitor, codigo_projeto); // TODO: completar a função
        }
        else if (menu2_op == 'b' || menu2_op == 'B')
        {
            // Caso a opção seja `b) Suspender votação`:

            // TODO:
            if (!suspender_votacao(comissao)) // TODO: completar a função
            {
                printf("Erro ao suspender votação. Tente novamente.\n");
                return 2;
            }
        } 
        else if (menu2_op == 'c' || menu2_op == 'C')
        {
            // Caso a opção seja `c) Concluir votação`:
            
            // TODO:
            if (!gerar_resultado(listaPIs, comissao, formandos)) // TODO: completar a função
            {
                printf("Erro ao gerar o resultado da votação. Tente novamente.\n");
            }
        }
        
    } 
    else if (menu1_op == 'b' || menu1_op == 'B')
    {
        // TODO: caso a opção seja a `b) Continuar votação gravada`:
        // Leia o arquivo `parcial.txt`
            // Se ele não existir, informe o problema e volte para o menu1
        FILE *parcial_arquivo = fopen("./arquivos_de_saida/parcial.txt", "r");

        if (parcial_arquivo == NULL)
        {
            printf("Erro ao abrir parcial.txt. Certifique-se de que ele existe e tente novamente\n");
            return 1;
        }

        // Gravar os votos do arquivo parcial.txt nas estruturas apresentadas
        retomar_votacao(parcial_arquivo); // TODO: completar a função
    }
}