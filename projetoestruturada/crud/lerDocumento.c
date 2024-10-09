#include <stdio.h>
#include "../esquemas/esquemas.h"
#include "utils.h"



void lerDocumento(Cliente clientes[], int maxClientes, int maxDocumentos){
    
    int posicao = posicaoCliente(clientes, maxClientes);
    if(posicao == -1){
        return;
    }

    Cliente cliente = clientes[posicao];
    Documento documento = selecionarDocumento(cliente, maxDocumentos);
    if(documento.numeroDocumento == -1){
        return;
    }

    printf("Documento de número: %d\n", documento.numeroDocumento);
    printf("Documento associado ao cliente de código: %d\n", documento.codigoCliente);
    printf("Data de vencimento: %d/%d/%d\n", documento.dataVencimento.dia, documento.dataVencimento.mes, documento.dataVencimento.ano);
    printf("Data de pagamento: %d/%d/%d\n", documento.dataPagamento.dia, documento.dataPagamento.mes, documento.dataPagamento.ano);
    printf("Valor do documento: R$%.2f\n", documento.valor);
    printf("Valor dos juros: R$%.2f\n", documento.valorJuros);

}


void documentosPorCliente(Cliente clientes[], int maxClientes){
    int posicao = posicaoCliente(clientes, maxClientes);
    if(posicao == -1){
        return;
    }

    Cliente cliente = clientes[posicao];
    printf("O cliente de código %d possui %d documentos cadastrados.\n", cliente.codigoCliente, cliente._contadorDeDocumentos);
}