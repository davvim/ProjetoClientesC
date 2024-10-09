#include <stdio.h>
#include "../esquemas/esquemas.h"


Cliente criarCliente(int *posicaoCliente, Cliente clientes[]) {
    Cliente cliente;

    printf("Digite o codigo do cliente: ");
    scanf("%d", &cliente.codigoCliente);

    printf("Digite o nome do cliente: ");
    scanf("%s", cliente.nome);
    
    printf("Digite o telefone do cliente: ");
    scanf("%s", cliente.telefone);
    
    printf("Digite o endereco do cliente: ");
    scanf("%s", cliente.endereco);

    cliente._contadorDeDocumentos = 0;
    clientes[*posicaoCliente] = cliente;
    *posicaoCliente++;
    return cliente;
}


