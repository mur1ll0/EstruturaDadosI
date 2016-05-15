#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *vetor, int qntd){
    int j, i, chave;

    for(j = 1; j < qntd; j++){
        chave = vetor[j];
        i = j - 1;
        while(i >= 0 && vetor[i] > chave){
            vetor[i+1] = vetor[i];
            i = i - 1;
        }
        vetor[i+1] = chave;
    }
}

void bubbleSort(int *vetor, int qntd){
    int trocou, aux, i;
    do{
        trocou = 0;
        for(i = 1; i < qntd; i++){
            if(vetor[i-1] > vetor[i]){
                aux = vetor[i];
                vetor[i] = vetor[i-1];
                vetor[i-1] = aux;
                trocou = 1;
            }
        }
    }while(trocou == 1);
}


int main()
{
    int *vetor, qntd, num;
    char c;

    vetor = (int *)malloc(sizeof(int));
    qntd = 1;

    printf("\nDigite o vetor de numeros: ");
    do{
        scanf(" %d%c", &num, &c);
        vetor[qntd-1] = num;

        if(c != 10){
            qntd++;
            vetor = realloc(vetor, qntd * sizeof(int));
        }

    }while(c != 10);

    printf("\nDigite:\n1 - insertSort\n2 - bubbleSort\n");
    scanf(" %d", &num);
    getchar();

    if(num == 1) insertionSort(vetor, qntd);
    else if(num == 2) bubbleSort(vetor, qntd);

    printf("\n\nVetor ordenado: ");

    for(num = 0; num < qntd; num++){
        printf(" %d", vetor[num]);
    }

    return 0;
}
