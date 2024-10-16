#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> 
#include "menu/menu.h"
#include "crud/criarCliente.h"
#include "crud/criarDocumento.h"
#include "crud/deletarCliente.h"
#include "crud/lerDocumento.h"
#include "esquemas/esquemas.h"
#include "cJSON/cJSON.h"
#include "json/carregar.h"
#include "json/salvar.h"


#define MAX_CLIENTES 15
#define MAX_DOCUMENTOS 30


int main() {
    int escolha, posicaoCliente = 0;
    Cliente clientes[MAX_CLIENTES];
    char filename[20] = "exemplo.json";

    memset(clientes, 0, sizeof(clientes));
    setlocale(LC_ALL, "Portuguese");

    carregarClientes(filename, clientes, &posicaoCliente);

    do {
        showMenu();
        escolha = escolhaMenu();    
        
        switch (escolha) {
            case 1:
                criarCliente(&posicaoCliente, clientes, MAX_CLIENTES);
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
                salvarClientes(filename, clientes, posicaoCliente);
                break;
            default:
                printf("Escolha invalida. Tente novamente.\n");
        }
    } while (escolha != 6);

    return 0;
}

