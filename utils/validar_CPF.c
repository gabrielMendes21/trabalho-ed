#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

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
            // Posição 11 deve ser hífen '-'
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

    char cpfSomenteNumeros[11];  // Para armazenar os 9 primeiros dígitos do CPF mais os dois verificadores
    int j = 0;                   // Contador
    int contDv1 = 10;             // Contador de multiplicação para DV1
    int contDv2 = 11;             // Contador de multiplicação para DV2
    int dv1 = 0, dv2 = 0;         // Variáveis para armazenar os resultados

    // Obtém os 9 primeiros dígitos do CPF (sem formatação)
    for (int i = 0; i < 14; i++) {
        if (isdigit(cpf[i]) && j < 11) {  // Pega todos os números (9 + 2 dígitos verificadores)
            cpfSomenteNumeros[j] = cpf[i];
            j++;
        }
    }
    
    //armazenando os digitos verificadores que foram inseridos na entrada(original)
    int priDigitoEntrada = cpfSomenteNumeros[9] - '0';
    int segDigitoEntrada = cpfSomenteNumeros[10] - '0';

    // Calcula o primeiro dígito verificador (dv1)
    for (int i = 0; i < 9; i++) {
        dv1 += (cpfSomenteNumeros[i] - '0') * contDv1;
        contDv1--;
    }

    // Novo ajuste do valor de dv1 conforme regra de CPF 
    if (dv1 % 11 < 2) {
        dv1 = 0;
    } else {
        dv1 = 11 - (dv1 % 11);
    }
    printf("\nPrimeiro dígito verificador (dv1): %d\n\n", dv1);

    // Inclui o DV1 no array de números do CPF para o cálculo do DV2
    cpfSomenteNumeros[9] = dv1 + '0'; // Converte DV1 para caractere e armazena

    // Calcula o segundo dígito verificador (dv2)
    for (int i = 0; i < 10; i++) {
        dv2 += (cpfSomenteNumeros[i] - '0') * contDv2;
        contDv2--;
    }
        
    dv2 = dv2 % 11;
    
    // // Ajusta o valor de dv2 conforme regra de CPF 
    if (dv2 < 2) {
        dv2 = 0;
    } else {
        dv2 = 11 - dv2 ;
    }

    
    // Comparar dv1 e dv2 com os dois últimos dígitos do CPF fornecido
    if ((dv1 == priDigitoEntrada) && (dv2 == (segDigitoEntrada))) {
        printf("CPF valido!\n");
    } else {
        printf("CPF invalido!\n");
        return false;
    }

    return true;
}