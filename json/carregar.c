#include "../cJSON/cJSON.h"
#include "../json/carregar.h"
#include "../esquemas/esquemas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void carregarClientes(const char *filename, Cliente clientes[], int *posicaoCliente) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo JSON.\n");
        return;
    }

    // Ler o arquivo inteiro
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (length == 0) {
        printf("Arquivo JSON está vazio.\n");
        fclose(file);
        return;
    }

    char *data = malloc(length + 1);
    fread(data, 1, length, file);
    data[length] = '\0';  // Garantir que a string está terminada com '\0'
    fclose(file);

    // Parse JSON
    cJSON *json = cJSON_Parse(data);
    free(data);

    if (json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            printf("Erro ao analisar o JSON: %s\n", error_ptr);
        } else {
            printf("Erro desconhecido ao analisar o JSON.\n");
        }
        return;
    }

    // Ler os clientes
    cJSON *jsonClientes = cJSON_GetObjectItem(json, "clientes");
    int numClientes = cJSON_GetArraySize(jsonClientes);
    for (int i = 0; i < numClientes; i++) {
        cJSON *jsonCliente = cJSON_GetArrayItem(jsonClientes, i);

        clientes[i].codigoCliente = cJSON_GetObjectItem(jsonCliente, "codigoCliente")->valueint;
        strcpy(clientes[i].nome, cJSON_GetObjectItem(jsonCliente, "nome")->valuestring);
        strcpy(clientes[i].telefone, cJSON_GetObjectItem(jsonCliente, "telefone")->valuestring);
        strcpy(clientes[i].endereco, cJSON_GetObjectItem(jsonCliente, "endereco")->valuestring);
        clientes[i]._contadorDeDocumentos = cJSON_GetObjectItem(jsonCliente, "_contadorDeDocumentos")->valueint;

        // Ler os documentos do cliente
        cJSON *jsonDocumentos = cJSON_GetObjectItem(jsonCliente, "documentos");
        int numDocumentos = cJSON_GetArraySize(jsonDocumentos);
        for (int j = 0; j < numDocumentos; j++) {
            cJSON *jsonDocumento = cJSON_GetArrayItem(jsonDocumentos, j);
            clientes[i].documentos[j].numeroDocumento = cJSON_GetObjectItem(jsonDocumento, "numeroDocumento")->valueint;
            clientes[i].documentos[j].codigoCliente = cJSON_GetObjectItem(jsonDocumento, "codigoCliente")->valueint;

            cJSON *jsonDataVencimento = cJSON_GetObjectItem(jsonDocumento, "dataVencimento");
            clientes[i].documentos[j].dataVencimento.ano = cJSON_GetObjectItem(jsonDataVencimento, "ano")->valueint;
            clientes[i].documentos[j].dataVencimento.mes = cJSON_GetObjectItem(jsonDataVencimento, "mes")->valueint;
            clientes[i].documentos[j].dataVencimento.dia = cJSON_GetObjectItem(jsonDataVencimento, "dia")->valueint;

            cJSON *jsonDataPagamento = cJSON_GetObjectItem(jsonDocumento, "dataPagamento");
            clientes[i].documentos[j].dataPagamento.ano = cJSON_GetObjectItem(jsonDataPagamento, "ano")->valueint;
            clientes[i].documentos[j].dataPagamento.mes = cJSON_GetObjectItem(jsonDataPagamento, "mes")->valueint;
            clientes[i].documentos[j].dataPagamento.dia = cJSON_GetObjectItem(jsonDataPagamento, "dia")->valueint;

            clientes[i].documentos[j].valor = cJSON_GetObjectItem(jsonDocumento, "valor")->valuedouble;
            clientes[i].documentos[j].valorJuros = cJSON_GetObjectItem(jsonDocumento, "valorJuros")->valuedouble;
        }
    }

    *posicaoCliente = numClientes;

    cJSON_Delete(json);
}
