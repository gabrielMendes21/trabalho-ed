#include <stdio.h>
#include <stdbool.h>

bool cpf_pode_votar(char *cpf, FILE *arquivo_comissao) 
{
    int qtd_Cpfs;
    char cpfLido[15]; // Variável para armazenar cada CPF lido

    // Lê a primeira linha com a quantidade de CPFs
    fscanf(arquivo_comissao, "%i", &qtd_Cpfs);
    printf("Quantidade de CPFs: %i\n", qtd_Cpfs);

    // Lê cada CPF do arquivo e compara com o CPF inserido 
    for (int i = 0; i < qtd_Cpfs; i++) {
        fscanf(arquivo_comissao, "%s", cpfLido); // Lê o CPF da linha
        printf("CPF lido: %s\n", cpfLido);       // Exibe o CPF
        // Comparação com um CPF inserido
        if (strcmp(cpf, cpfLido) == 0) {
            printf("CPF encontrado! Pode votar.\n");
            fclose(arquivo_comissao);
            return true;
        }
    }

    printf("CPF nao encontrado.\n");
    fclose(arquivo_comissao);
    return false;
}

// int main() {
//     FILE *file;
//     file = fopen("D:\\Documentos\\LicoesFatec\\ED\\cpf_podevotar\\comissao.txt", "r");

//     if (file == NULL) {
//         printf("Erro ao abrir o arquivo.\n");
//         return 1;
//     }

//     char cpf[15] = "773.459.123-02";

//     cpf_pode_votar(cpf, file);
//     return 0;
// }