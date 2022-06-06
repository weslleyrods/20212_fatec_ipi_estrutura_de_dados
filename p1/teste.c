int verifica_repeticoes (int *vetor, int tamanho) {
    int i, j;
    for (i=0; i<tamanho; i++) {
        for (j=i+1; j<tamanho; j++){
            if (vetor[i] == vetor[j]) {
                printf("\nForam encontrados numeros repetidos.");
                break;
            }
        }

    }
    printf("Nao ha numeros repetidos.");

}