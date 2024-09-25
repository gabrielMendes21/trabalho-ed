#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CPF 15
#define MAX_NOME 60
#define MAX_SIGLA 10
#define MAX 50
#define CURSOS 7

// Menus
#include "./menus/menu1.c"
#include "./menus/menu2.c"

// Utils
#include "./utils/validar_CPF.c"
#include "./utils/cpf_pode_votar.c"
#include "./utils/codigo_projeto_valido.c"
#include "./utils/computar_voto.c"
#include "./utils/suspender_votacao.c"
#include "./utils/retomar_votacao.c"
#include "./utils/gerar_resultado.c"
#include "./utils/cadastrar_projetos.c"
#include "./utils/cadastrar_comissao.c"
#include "./utils/cadastrar_professores.c"
#include "./utils/cadastrar_alunos.c"
#include "./utils/cpf_ja_votou.c"

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

TG listaPIs[MAX];
int qtde_TGs;

Eleitor comissao[MAX];
int qtde_eleitores;

int main(void)
{
    char *cursos[CURSOS] = {"AMS", "ADS", "DSM", "CEX", "EMP", "LOG", "POL"};  
    char menu1_op, menu2_op;

    // Chamar as funções para ler os arquivos de entrada e cadastrar os dados nos vetores
    cadastrar_alunos(formandos, &qtde_formandos, cursos);
    cadastrar_professores(docentes, &qtde_docentes);
    cadastrar_projetos(listaPIs, formandos, cursos, &qtde_TGs, qtde_formandos);
    cadastrar_comissao(comissao, &qtde_eleitores); 

    // Mostrar o menu enquanto o usuário não digitar a opção correta
    do
    {
        do
        {
            // Mostrar o menu1
            menu1();
            scanf(" %c", &menu1_op); // Espaço antes de %c para ignorar caracteres em branco
        } while(menu1_op != 'A' && menu1_op != 'a' && menu1_op != 'B' && menu1_op != 'b');

        if (menu1_op == 'a' || menu1_op == 'A')
        {
            // Loop para o menu2
            do
            {
                // Mostrar o menu2
                menu2();
                scanf(" %c", &menu2_op); // Espaço antes de %c para ignorar caracteres em branco

                if (menu2_op == 'a' || menu2_op == 'A')
                {
                    // Caso a opção seja `a) Entrar com voto`
                    FILE *comissao_arquivo = fopen("arquivos_de_entrada/comissao.txt", "r");

                    if (comissao_arquivo == NULL)
                    {
                        printf("Arquivo `comissao.txt` não existe. Crie o arquivo, insira os CPF's que podem votar e tente novamente\n");
                        return 1;
                    }

                    // Solicitar o CPF
                    char cpf[MAX_CPF];
                    do 
                    {
                        printf("Digite o CPF: ");
                        scanf("%s", cpf);
                    } while(!validar_CPF(cpf) || !cpf_pode_votar(cpf, comissao, qtde_eleitores) || cpf_ja_votou(comissao, cpf, qtde_eleitores));

                    // Solicitar o código do projeto
                    char codigo_projeto[MAX_SIGLA];
                    
                    do
                    {
                        printf("Digite o codigo do projeto: ");
                        scanf("%s", codigo_projeto);
                    } while (!codigo_projeto_valido(listaPIs, qtde_TGs, codigo_projeto)); 
                    
                    // Computar o voto
                    Eleitor *eleitor = NULL; // Inicializa como NULL
                    for (int i = 0; i < qtde_eleitores; i++)
                    {
                        if (strcmp(comissao[i].cpf, cpf) == 0)
                        {
                            eleitor = &comissao[i];
                            break; // Saia do loop assim que encontrar
                        }
                    }

                    if (eleitor != NULL) {
                        computar_voto(listaPIs, &qtde_TGs, eleitor, codigo_projeto); 
                    } else {
                        printf("Eleitor nao encontrado.\n");
                    }
                }
                else if (menu2_op == 'b' || menu2_op == 'B')
                {
                    // Suspender votação
                    if (!suspender_votacao(comissao, &qtde_eleitores))
                    {
                        printf("Erro ao suspender votação. Tente novamente.\n");
                    }
                    return 0;
                } 
                else if (menu2_op == 'c' || menu2_op == 'C')
                {
                    // Concluir votação
                    if (!gerar_resultado(listaPIs, comissao, formandos, docentes, qtde_TGs, qtde_eleitores, qtde_formandos, qtde_docentes)) {
                        printf("Erro ao gerar o resultado da votação. Tente novamente.\n");
                    }
                    return 0;
                }
            } while (true); // Permite que o menu2 seja exibido novamente
        } 
        else if (menu1_op == 'b' || menu1_op == 'B')
        {
            // Continuar votação gravada
            FILE *parcial_arquivo = fopen("./arquivos_de_saida/parcial.txt", "r");

            if (parcial_arquivo == NULL)
            {
                printf("Erro ao abrir parcial.txt. Certifique-se de que ele existe e tente novamente\n");
                continue; // Volta para o início do loop menu1
            }

            // Retomar a votação
            if (retomar_votacao(parcial_arquivo, listaPIs, comissao, &qtde_eleitores, &qtde_TGs)) {
                printf("Votacao retomada com sucesso.\n");
            } else {
                printf("Erro ao retomar a votação.\n");
            }

            // Mostrar novamente o menu2 após retomar a votação
            do
            {
                menu2();
                scanf(" %c", &menu2_op);

                if (menu2_op == 'a' || menu2_op == 'A')
                {
                    // Caso a opção seja `a) Entrar com voto`
                    FILE *comissao_arquivo = fopen("arquivos_de_entrada/comissao.txt", "r");

                    if (comissao_arquivo == NULL)
                    {
                        printf("Arquivo `comissao.txt` não existe. Crie o arquivo, insira os CPF's que podem votar e tente novamente\n");
                        return 1;
                    }

                    // Solicitar o CPF
                    char cpf[MAX_CPF];
                    do 
                    {
                        printf("Digite o CPF: ");
                        scanf("%s", cpf);
                    } while(!validar_CPF(cpf) || !cpf_pode_votar(cpf, comissao, qtde_eleitores) || cpf_ja_votou(comissao, cpf, qtde_eleitores));

                    // Solicitar o código do projeto
                    char codigo_projeto[MAX_SIGLA];
                    
                    do
                    {
                        printf("Digite o codigo do projeto: ");
                        scanf("%s", codigo_projeto);
                    } while (!codigo_projeto_valido(listaPIs, qtde_TGs, codigo_projeto)); 
                    
                    // Computar o voto
                    Eleitor *eleitor = NULL; // Inicializa como NULL
                    for (int i = 0; i < qtde_eleitores; i++)
                    {
                        if (strcmp(comissao[i].cpf, cpf) == 0)
                        {
                            eleitor = &comissao[i];
                            break; // Saia do loop assim que encontrar
                        }
                    }

                    if (eleitor != NULL) {
                        computar_voto(listaPIs, &qtde_TGs, eleitor, codigo_projeto); 
                    } else {
                        printf("Eleitor nao encontrado.\n");
                    }
                }
                else if (menu2_op == 'b' || menu2_op == 'B')
                {
                    // Suspender votação
                    if (!suspender_votacao(comissao, &qtde_eleitores))
                    {
                        printf("Erro ao suspender votação. Tente novamente.\n");
                    }
                    break; // Sai do loop do menu2 após suspender
                } 
                else if (menu2_op == 'c' || menu2_op == 'C')
                {
                    // Concluir votação
                    if (!gerar_resultado(listaPIs, comissao, formandos, docentes, qtde_TGs, qtde_eleitores, qtde_formandos, qtde_docentes)) {
                        printf("Erro ao gerar o resultado da votação. Tente novamente.\n");
                    }
                    return 0; // Sai do loop do menu2 após concluir
                }
            } while (true); // Permite que o menu2 seja exibido novamente após retomar a votação
        }
    } while (true);

    return 0; // Para garantir que o programa termina corretamente
}
