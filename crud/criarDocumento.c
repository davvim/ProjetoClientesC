#include <stdio.h>
#include "../esquemas/esquemas.h"
#include "utils.h"


Documento criarDocumento(Cliente cliente, int tamanhoVetor){
    Documento documento;
    documento.codigoCliente = cliente.codigoCliente;

    
    while (1) {
        printf("Digite o numero do documento: ");
        scanf("%d", &documento.numeroDocumento);

        if (validarIdDocumento(documento.numeroDocumento, cliente.documentos, tamanhoVetor))
            break;

        printf("Codigo do documento ja existe. Por favor escolha outro\n");
    }

    printf("Qual a data de vencimento do documento? (dd/mm/aaaa) ");
    scanf("%d/%d/%d", &documento.dataVencimento.dia, &documento.dataVencimento.mes, &documento.dataVencimento.ano);

    printf("Qual a data de pagamento do documento? (dd/mm/aaaa) ");
    scanf("%d/%d/%d", &documento.dataPagamento.dia, &documento.dataPagamento.mes, &documento.dataPagamento.ano);

    printf("Qual o valor do documento? ");
    scanf("%f", &documento.valor);

    documento.valorJuros = calcularJuros(documento);
    return documento;
}

void cadastrarDocumento(Cliente clientes[], int maxClientes){
    int posicao = posicaoCliente(clientes, maxClientes);
    
    if(posicao == -1){
        return;
    }

    Cliente cliente = clientes[posicao];    
    Documento documento = criarDocumento(cliente, maxClientes);
    clientes[posicao].documentos[clientes[posicao]._contadorDeDocumentos] = documento;
    clientes[posicao]._contadorDeDocumentos++;
}


