#include <stdio.h>
#include <stdlib.h>

int pesquisaBinaria(int *vet, int inicio, int fim, int valor){
    int meio;
    while (inicio <= fim){
        meio = (inicio + fim)/2;
        if(valor == vet[meio]){
            return meio;
        }
        else if(valor < vet[meio]){
            fim = meio - 1;
        }
        else if(valor > vet[meio]){
            inicio = meio + 1;
        }
    }
    return -1;
}

int pesquisaBinariaRecursiva(int *vet, int inicio, int fim, int valor){
    int meio;
    if (inicio <= fim){
        meio = (inicio + fim)/2;
        if(valor == vet[meio]){
            return meio;
        }
        else if(valor < vet[meio]){
            fim = meio - 1;
            return pesquisaBinariaRecursiva(vet, inicio, fim, valor);
        }
        else if(valor > vet[meio]){
            inicio = meio + 1;
            return pesquisaBinariaRecursiva(vet, inicio, fim, valor);
        }
    }
    return -1;
}


int main()
{
    int vetor[15], i, result;

    for (i=0; i<15; i++){
        vetor[i] = (i*2);
    }

    for (i=0; i<15; i++){
        printf("\n%d", vetor[i]);
    }

    //result = pesquisaBinaria(vetor, 0, 14, 12);
    result = pesquisaBinariaRecursiva(vetor, 0, 14, 20);

    printf("\nRetorno: %d\n", result);

    return 0;
}
