#include "../cJSON/cJSON.h"
#include "../json/carregar.h"
#include "../esquemas/esquemas.h"
#include <stdio.h>
#include <stdlib.h>


void salvarClientes(const char *filename, Cliente clientes[], int posicaoCliente) {
    // Cria o JSON principal
    cJSON *json = cJSON_CreateObject();
    cJSON *jsonClientes = cJSON_CreateArray();
    cJSON_AddItemToObject(json, "clientes", jsonClientes);

    for (int i = 0; i < posicaoCliente; i++) {
        cJSON *jsonCliente = cJSON_CreateObject();
        cJSON_AddItemToArray(jsonClientes, jsonCliente);

        cJSON_AddNumberToObject(jsonCliente, "codigoCliente", clientes[i].codigoCliente);
        cJSON_AddStringToObject(jsonCliente, "nome", clientes[i].nome);
        cJSON_AddStringToObject(jsonCliente, "telefone", clientes[i].telefone);
        cJSON_AddStringToObject(jsonCliente, "endereco", clientes[i].endereco);
        cJSON_AddNumberToObject(jsonCliente, "_contadorDeDocumentos", clientes[i]._contadorDeDocumentos);

        // Adiciona os documentos
        cJSON *jsonDocumentos = cJSON_CreateArray();
        cJSON_AddItemToObject(jsonCliente, "documentos", jsonDocumentos);

        for (int j = 0; j < clientes[i]._contadorDeDocumentos; j++) {
            cJSON *jsonDocumento = cJSON_CreateObject();
            cJSON_AddItemToArray(jsonDocumentos, jsonDocumento);

            cJSON_AddNumberToObject(jsonDocumento, "numeroDocumento", clientes[i].documentos[j].numeroDocumento);
            cJSON_AddNumberToObject(jsonDocumento, "codigoCliente", clientes[i].documentos[j].codigoCliente);

            cJSON *jsonDataVencimento = cJSON_CreateObject();
            cJSON_AddItemToObject(jsonDocumento, "dataVencimento", jsonDataVencimento);
            cJSON_AddNumberToObject(jsonDataVencimento, "ano", clientes[i].documentos[j].dataVencimento.ano);
            cJSON_AddNumberToObject(jsonDataVencimento, "mes", clientes[i].documentos[j].dataVencimento.mes);
            cJSON_AddNumberToObject(jsonDataVencimento, "dia", clientes[i].documentos[j].dataVencimento.dia);

            cJSON *jsonDataPagamento = cJSON_CreateObject();
            cJSON_AddItemToObject(jsonDocumento, "dataPagamento", jsonDataPagamento);
            cJSON_AddNumberToObject(jsonDataPagamento, "ano", clientes[i].documentos[j].dataPagamento.ano);
            cJSON_AddNumberToObject(jsonDataPagamento, "mes", clientes[i].documentos[j].dataPagamento.mes);
            cJSON_AddNumberToObject(jsonDataPagamento, "dia", clientes[i].documentos[j].dataPagamento.dia);

            cJSON_AddNumberToObject(jsonDocumento, "valor", clientes[i].documentos[j].valor);
            cJSON_AddNumberToObject(jsonDocumento, "valorJuros", clientes[i].documentos[j].valorJuros);
        }
    }

    // Escreve o JSON no arquivo
    char *string = cJSON_Print(json);
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fputs(string, file);
        fclose(file);
    }

    free(string);
    cJSON_Delete(json);
}
