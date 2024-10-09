#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "menu/menu.h"
#include "crud/criarCliente.h"
#include "crud/criarDocumento.h"
#include "crud/deletarCliente.h"
#include "crud/lerDocumento.h"
#include "esquemas/esquemas.h"


#define MAX_CLIENTES 15
#define MAX_DOCUMENTOS 30

// Cliente cliente1 = {1, "João da Silva", "1234-5678", "Rua das Flores, 123"};
// Documento documento1 = {1, 1, {2024, 1, 1}, {2024, 1, 10}, 100.0, 0.1};

int main() {
    int escolha, posicaoCliente = 0;
    Cliente clientes[MAX_CLIENTES];
    
    setlocale(LC_ALL, "Portuguese");

    do {
        showMenu();
        escolha = escolhaMenu();    
        
        switch (escolha) {
            case 1:
                criarCliente(&posicaoCliente, clientes);
                break;
            case 2:
                cadastrarDocumento(clientes, MAX_CLIENTES);
                break;
            case 3:
                deletarCliente(clientes, MAX_CLIENTES);
                break;
            case 4:
                lerDocumento(clientes, MAX_CLIENTES, MAX_DOCUMENTOS);
                break;
            case 5:
                documentosPorCliente(clientes, MAX_CLIENTES);
                break;
            case 6:
                break;
            default:
                printf("Escolha inválida. Tente novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}

