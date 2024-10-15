#ifndef ESQUEMAS_H
#define ESQUEMAS_H

typedef struct {
    int ano;
    int mes;
    int dia;
} Data;

typedef struct {
    int numeroDocumento;
    int codigoCliente;
    Data dataVencimento;
    Data dataPagamento;
    float valor;
    float valorJuros;
} Documento;

typedef struct {
    int codigoCliente;
    char nome[50];
    char telefone[15];
    char endereco[100];
    Documento documentos[30];
    int _contadorDeDocumentos;
} Cliente;

#endif 
