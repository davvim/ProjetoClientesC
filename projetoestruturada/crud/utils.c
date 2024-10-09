#include <stdio.h>
#include "../esquemas/esquemas.h"

int posicaoCliente(Cliente clientes[], int maxClientes){
    int codigoCliente;

    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigoCliente);

    for (int i = 0; i < maxClientes; i++) {
        if (clientes[i].codigoCliente == codigoCliente) {
            printf("Cliente selecionado: %s\n", clientes[i].nome);
            return i;
        }
    }
    printf("Não foi possível encontrar um cliente com o código %d\n", codigoCliente);
    return -1;
}

Documento selecionarDocumento(Cliente cliente, int maxDocumentos){
    int numeroDocumento;
    Documento documento, novoDocumento;

    printf("Digite o código do documento: ");
    scanf("%d", &numeroDocumento);

    for (int i = 0; i < maxDocumentos; i++) {
        documento = cliente.documentos[i];
        printf("Documento: %d\n", documento.numeroDocumento);
        if (documento.numeroDocumento == numeroDocumento) {
            printf("Documento selecionado: %d\n", cliente.documentos[i].numeroDocumento);
            return cliente.documentos[i];
        }
    }
    printf("Não foi possível encontrar um documento com o código %d\n", numeroDocumento);

    novoDocumento.numeroDocumento = -1;
    return novoDocumento;
}



float calcularJuros(Documento documento){
    float juros = 0;
    if(
        documento.dataPagamento.dia > documento.dataVencimento.dia 
        && documento.dataPagamento.mes >= documento.dataVencimento.mes 
        && documento.dataPagamento.ano >= documento.dataVencimento.ano
    ){
        juros = documento.valor * 0.05;
    }
    
    return juros;
}