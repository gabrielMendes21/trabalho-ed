#ifndef VALIDARCPF_h
#define VALIDARCPF_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h> // Para usar strlen()

bool validar_CPF(char cpf[15]) {
    // Verifica o tamanho do CPF (formato 123.456.789-00, total 14 caracteres)
    if (strlen(cpf) != 14) {
        printf("CPF inválido! Insira com a formatação correta! \n");
        return false;
    }

    // Verifica os dígitos nas posições corretas
    for (int i = 0; i < 14; i++) {
        if (i == 3 || i == 7) {
            // Posições 3 e 7 devem ser pontos '.'
            if (cpf[i] != '.') {
                printf("CPF sem a formatação correta! \n");
                return false;
            }
        } else if (i == 11) {
            // Posição 11 deve ser hifen '-'
            if (cpf[i] != '-') {
                printf("CPF sem a formatação correta! \n");
                return false;
            }
        } else {
            // Todas as outras posições devem ser dígitos
            if (!isdigit(cpf[i])) {
                printf("CPF sem a formatação correta! \n");
                return false;
            }
        }
    }

    char cpfSomenteNumeros[11];// Para armazenar os 9 primeiros dígitos do CPF mais os dois verificadores
    int j = 0;// Contador
    int contDv1 = 10;// Contador de multiplicação para DV1
    int contDv2 = 11;// Contador de multiplicação para DV2
    int dv1 = 0, dv2 = 0;// Variáveis para armazenar os resultados

    // Obtém os 9 primeiros dígitos do CPF (sem formatação)
    for (int i = 0; i < 14; i++) {
        if (isdigit(cpf[i]) && j < 11) {  // Pega todos os números (9 + 2 dígitos verificadores)
            cpfSomenteNumeros[j] = cpf[i];
            j++;
        }
    }
    
    // Calcula o primeiro dígito verificador (dv1)
    for (int i = 0; i < 9; i++) {
        dv1 += (cpfSomenteNumeros[i] - '0') * contDv1;
        printf("dv1: %d + %d * %d \n", dv1, cpfSomenteNumeros[i] - '0', contDv1);
        contDv1--;
    }

    // Ajusta o valor de dv1 conforme regra de CPF
    dv1 = (dv1 % 11 < 2) ? 0 : 11 - (dv1 % 11);
    printf("\nPrimeiro dígito verificador (dv1): %d\n", dv1);

    // Inclui o DV1 no array de números do CPF para o cálculo do DV2
    cpfSomenteNumeros[9] = dv1 + '0'; // Converte DV1 para caractere e armazena

    // Calcula o segundo dígito verificador (dv2)
    for (int i = 0; i < 10; i++) {
        dv2 += (cpfSomenteNumeros[i] - '0') * contDv2;
        printf("dv2: %d + %d * %d \n", dv2, cpfSomenteNumeros[i] - '0', contDv2);
        contDv2--;
    }

    // Ajusta o valor de dv2 conforme regra de CPF
    dv2 = (dv2 % 11 < 2) ? 0 : 11 - (dv2 % 11);
    printf("\nSegundo dígito verificador (dv2): %d\n", dv2);

    // Comparar dv1 e dv2 com os dois últimos dígitos do CPF fornecido
    if (dv1 == (cpfSomenteNumeros[9] - '0') && dv2 == (cpfSomenteNumeros[10] - '0')) {
        printf("CPF válido!\n");
    } else {
        printf("CPF inválido!\n");
        return false;
    }

    return true;
}


// int main() {
//     char cpf[15];

//     // Entrada do CPF com pontos e hífen
//     printf("Digite seu CPF (formato XXX.XXX.XXX-XX): ");
//     scanf("%s", cpf);

//     validar_CPF(cpf);

//     return 0;
// }

#endif