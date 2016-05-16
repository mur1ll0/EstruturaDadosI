#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int qntd, num, i;
    clock_t tempo;

    srand((unsigned)time(NULL));

    qntd = rand() % 20000;

    int vetor[qntd];

    for(i=0; i<qntd; i++){
        num = rand() % 200;
        vetor[i] = num;
    }

    printf("\nDigite:\n1 - insertSort\n2 - bubbleSort\n");
    scanf(" %d", &num);
    getchar();

    if(num == 1){
        tempo = clock();
        insertionSort(vetor, qntd);
        tempo = clock() - tempo;
    }
    else if(num == 2){
        tempo = clock();
        bubbleSort(vetor, qntd);
        tempo = clock() - tempo;
    }

    printf("\n\nVetor ordenado: ");

    for(num = 0; num < qntd; num++){
        printf(" %d", vetor[num]);
    }

    printf("\nTempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));
    printf("\n\nFim\n");

    return 0;
}
