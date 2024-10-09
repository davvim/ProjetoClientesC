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
    printf("Nao foi possivel encontrar um cliente com o codigo %d\n", codigoCliente);
    return -1;
}

Documento selecionarDocumento(Cliente cliente, int maxDocumentos){
    int numeroDocumento;
    Documento documento, novoDocumento;

    printf("Digite o codigo do documento: ");
    scanf("%d", &numeroDocumento);

    for (int i = 0; i < maxDocumentos; i++) {
        documento = cliente.documentos[i];
        if (documento.numeroDocumento == numeroDocumento) {
            return cliente.documentos[i];
        }
    }
    printf("Nao foi possivel encontrar um documento com o codigo %d\n", numeroDocumento);

    novoDocumento.numeroDocumento = -1;
    return novoDocumento;
}



float calcularJuros(Documento documento){
    float juros = 0;
    if(
        (documento.dataPagamento.dia > documento.dataVencimento.dia && documento.dataPagamento.mes >= documento.dataVencimento.mes && documento.dataPagamento.ano >= documento.dataVencimento.ano)
        || (documento.dataPagamento.mes >= documento.dataVencimento.mes && documento.dataPagamento.ano >= documento.dataVencimento.ano)
        || (documento.dataPagamento.ano >= documento.dataVencimento.ano)
    ){
        juros = documento.valor * 0.05;
    }

    return juros;
}


int validarIdCliente(int id, Cliente clientes[], int tamanhoVetor){

    for (int i = 0; i < tamanhoVetor; i++){
        if (id == clientes[i].codigoCliente)
            return 0;
    }

    return 1;

}

int validarIdDocumento(int id, Documento documentos[], int tamanhoVetor){

    for (int i = 0; i < tamanhoVetor; i++){
        if (id == documentos[i].numeroDocumento)
            return 0;
    }

    return 1;

}