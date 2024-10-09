#ifndef UTILS_CRUD_H
#define UTILS_CRUD_H
#include "../esquemas/esquemas.h"

int posicaoCliente(Cliente clientes[], int maxClientes);
Documento selecionarDocumento(Cliente cliente, int maxDocumentos);
float calcularJuros(Documento documento);

#endif