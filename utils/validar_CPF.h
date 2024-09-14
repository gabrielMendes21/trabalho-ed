#ifndef VALIDARCPF_h
#define VALIDARCPF_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h> // Para usar strlen()

bool verificarCPF(char cpf[15]) {
    // Verifica o tamanho do CPF (formato 123.456.789-00, total 14 caracteres)
    if (strlen(cpf) != 14) {
        return false;
    }

    // Verifica os dígitos nas posições corretas
    for (int i = 0; i < 14; i++) {
        if (i == 3 || i == 7) {
            // Posições 3 e 7 devem ser pontos '.'
            if (cpf[i] != '.') {
                return false;
            }
        } else if (i == 11) {
            // Posição 11 deve ser hifen '-'
            if (cpf[i] != '-') {
                return false;
            }
        } else {
            // Todas as outras posições devem ser dígitos
            if (!isdigit(cpf[i])) {
                return false;
            }
        }
    }

    // Se todas as verificações passaram, o CPF é válido
    return true;
}

#endif