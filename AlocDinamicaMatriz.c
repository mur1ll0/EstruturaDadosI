#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* uniao(int *v1, int n1, int *v2, int n2);

int main()
{
    int elem1, elem2, i, *vet2, *vet3;

    srand(time(NULL));

    printf("Digite a quantidade de elementos do vetor 1: ");
    scanf(" %d", &elem1);

    int vet1[elem1 + 1];

    printf("\nVetor 1:");
    for (i = 0; i < elem1; i++){
        vet1[i] = rand() % 100;
        printf(" %d", vet1[i]);
    }


    printf("\n\nDigite a quantidade de elementos do vetor 2: ");
    scanf(" %d", &elem2);

    if ((vet2 = malloc((1 + elem2) * sizeof(int))) == NULL){
        printf("\nMemoria insuficiente\n");
        return 0;
    }

    printf("\nVetor 2:");
    for (i = 0; i < elem2; i++){
        vet2[i] = rand() % 100;
        printf(" %d", vet2[i]);
    }

    vet3 = uniao(vet1, elem1, vet2, elem2);

    printf("\n\nVetor 3: ");
    for (i = 0; i< elem1+elem2; i++){
        printf(" %d", vet3[i]);
    }

    free(vet1);
    free(vet2);
    free(vet3);

    return 0;
}

int* uniao(int *v1, int n1, int *v2, int n2){
    int *vetor3, cont;

    if((vetor3 = malloc((n1+n2+1) * sizeof(int))) == NULL){
        printf("\nMemoria insuficiente\n");
        return 0;
    }

    for (cont = 0; cont <= n1+n2; cont++){
        if (cont < n1){
            vetor3[cont] = v1[cont];
        }
        else if (cont < n1+n2){
            vetor3[cont] = v2[cont-n1];
        }
    }
    return vetor3;
}
