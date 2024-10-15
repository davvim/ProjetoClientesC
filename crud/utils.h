#ifndef UTILS_CRUD_H
#define UTILS_CRUD_H
#include "../esquemas/esquemas.h"

Documento selecionarDocumento(Cliente cliente, int maxDocumentos);
float calcularJuros(Documento documento);
int posicaoCliente(Cliente clientes[], int maxClientes);
int validarIdCliente(int id, Cliente clientes[], int tamanhoVetor);
int validarIdDocumento(int id, Documento documentos[], int tamanhoVetor);

#endif