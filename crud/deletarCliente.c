    #include <stdio.h>
    #include "../esquemas/esquemas.h"


void removerElemento(Cliente clientes[], int maxClientes, int posicao) {
    for(int i = posicao; i < maxClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }
}

void deletarCliente(Cliente clientes[], int maxClientes) {
    int codigoCliente;

    printf("Digite o codigo do cliente que deseja deletar: ");
    scanf("%d", &codigoCliente);

    for(int i = 0; i < maxClientes; i++) {
        
        if(clientes[i].codigoCliente == codigoCliente) {
            
            if (clientes[i]._contadorDeDocumentos){
                printf("O cliente com documentos cadastrados nao pode ser deletado.\n");
                return;
            }

            removerElemento(clientes, maxClientes, i);
            printf("Cliente de codigo %d deletado com sucesso.\n", codigoCliente);
            return;
        }
    }
    printf("Cliente de codigo %d nao encontrado.\n", codigoCliente);
}

