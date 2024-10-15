#include <stdio.h>
#include "../esquemas/esquemas.h"
#include "utils.h"


Cliente criarCliente(int *posicaoCliente, Cliente clientes[], int tamanhoVetor) {
    Cliente cliente;


    while (1) {
        printf("Digite o codigo do cliente: ");
        scanf("%d", &cliente.codigoCliente);

        if (validarIdCliente(cliente.codigoCliente, clientes, tamanhoVetor))
            break;

        printf("Codigo do cliente ja existe. Por favor escolha outro\n");
    }


    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]s", cliente.nome);
    
    printf("Digite o telefone do cliente: ");
    scanf(" %[^\n]s", cliente.telefone);
    
    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]s", cliente.endereco);

    cliente._contadorDeDocumentos = 0;
    clientes[*posicaoCliente] = cliente;
    (*posicaoCliente)++; 
    return cliente;
}