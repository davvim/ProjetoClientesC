void showMenu() {
    printf("\n1. Registrar Cliente\n");
    printf("2. Registrar Documento\n");
    printf("3. Deletar Cliente\n");
    printf("4. Consultar Documento\n");
    printf("5. Mostrar Total de Documentos de um Cliente Específico\n");
    printf("6. Sair do Programa\n");
}

int escolhaMenu() {
    int escolha;
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

