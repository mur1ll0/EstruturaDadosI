#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int *vet, int tamanho);
int partition(int *vetor, int p, int q);
void quickSort(int *vetor, int p, int q);
void insertionSort(int *vetor, int qntd);
void bubbleSort(int *vetor, int qntd);
void merge(int *vetorA, int inicio, int meio, int fim);
void mergeSort(int *vetor, int inicio, int fim);
void combSort(int *vetor, int tamanho);
void cocktailSort(int *vetor, int tamanho);
void gnomeSort(int *vetor, int tamanho);
void radixSort(int *vetorA, int tamanho);

int main(){
    srand((unsigned)time(NULL));
	int tamanho, i;
	clock_t tempo;

	//DEFINIR TAMANHO DO VETOR
	tamanho = 50000;

	int vetor[tamanho], vetorC[tamanho];

	for(i=0; i<tamanho; i++){
		vetor[i] = rand() %1000;
	}

    printf("\nTAMANHO DO VETOR: %d\n\n", tamanho);
	//----------------------------------------------------------------------------
	//SHELL SORT

	for(i=0; i<tamanho; i++){
		vetorC[i] = vetor[i];
	}
    tempo = clock();
	shellSort(vetorC, tamanho);
	tempo = clock() - tempo;
	printf("\nShell Sort Tempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));


    //----------------------------------------------------------------------------
    //QUICK SORT

    for(i=0; i<tamanho; i++){
		vetorC[i] = vetor[i];
	}
    tempo = clock();
	quickSort(vetorC, 0, tamanho-1);
	tempo = clock() - tempo;
	printf("\nQuick Sort Tempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));


	//----------------------------------------------------------------------------
	//INSERTION SORT

    for(i=0; i<tamanho; i++){
		vetorC[i] = vetor[i];
	}
	tempo = clock();
    insertionSort(vetorC, tamanho);
    tempo = clock() - tempo;
    printf("\nInsertion Sort Tempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));


    //----------------------------------------------------------------------------
    //BUBBLE SORT

    for(i=0; i<tamanho; i++){
		vetorC[i] = vetor[i];
	}
	tempo = clock();
    bubbleSort(vetorC, tamanho);
    tempo = clock() - tempo;
    printf("\nBubble Sort Tempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));


    //----------------------------------------------------------------------------
    //MERGE SORT

    for(i=0; i<tamanho; i++){
		vetorC[i] = vetor[i];
	}
	tempo = clock();
    mergeSort(vetorC, 0, tamanho-1);
    tempo = clock() - tempo;
    printf("\nMerge Sort Tempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));


    //----------------------------------------------------------------------------
    //COMB SORT

    for(i=0; i<tamanho; i++){
		vetorC[i] = vetor[i];
	}
	tempo = clock();
    combSort(vetorC, tamanho);
    tempo = clock() - tempo;
    printf("\nComb Sort Tempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));


    //----------------------------------------------------------------------------
    //COCKTAIL SORT

    for(i=0; i<tamanho; i++){
		vetorC[i] = vetor[i];
	}
	tempo = clock();
    cocktailSort(vetorC, tamanho);
    tempo = clock() - tempo;
    printf("\nCocktail Sort Tempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));


    //----------------------------------------------------------------------------
    //GNOME SORT

    for(i=0; i<tamanho; i++){
		vetorC[i] = vetor[i];
	}
	tempo = clock();
    gnomeSort(vetorC, tamanho);
    tempo = clock() - tempo;
    printf("\nGnome Sort Tempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));


    //----------------------------------------------------------------------------
    //RADIX SORT

    for(i=0; i<tamanho; i++){
		vetorC[i] = vetor[i];
	}
	tempo = clock();
    radixSort(vetorC, tamanho);
    tempo = clock() - tempo;
    printf("\nRadix Sort Tempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));


    //----------------------------------------------------------------------------
    printf("\n\nFim\n");
	return 0;
}

void shellSort(int *vet, int tamanho) {
    int i , j , valor;
    int h = 1;
    do {
        h = 3*h+1;
    } while(h < tamanho);
    do {
        h /= 3;
        for(i = h; i < tamanho; i++) {
            valor = vet[i];
            j = i - h;
            while (j >= 0 && valor < vet[j]) {
                vet[j + h] = vet[j];
                j -= h;
            }
            vet[j + h] = valor;
        }
    } while( h > 1);
}

int partition(int *vetor, int p, int q){
    int pivo = vetor[p], i = p, j = q, aux;

    while(i < j){
        while(vetor[i] < pivo && i < q) i++;
        while(vetor[j] > pivo && j > p) j--;
        if (vetor[i] > vetor[j]){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
		else if (vetor[i] == vetor[j]) j--;
    }
    return i;
}

void quickSort(int *vetor, int p, int q){
    int r;

	r = partition(vetor, p, q);
	if(r-1 > p) quickSort(vetor, p, r-1);
	if(r+1 < q) quickSort(vetor, r+1, q);
}

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

void merge(int *vetorA, int inicio, int meio, int fim){
    int vetorB[fim+1], i, j, k;

    i = k = inicio;
    j = meio+1;

    while (i <= meio && j <= fim) {
        if (vetorA[i] <= vetorA[j]){
            vetorB[k] = vetorA[i];
            i++;
        }
        else{
            vetorB[k] = vetorA[j];
            j++;
        }
        k++;
    }
    while (i <= meio) vetorB[k++] = vetorA[i++];
    while (j <= fim) vetorB[k++] = vetorA[j++];

    for (i = inicio; i <= fim; i++) vetorA[i] = vetorB[i];
}

void mergeSort(int *vetor, int inicio, int fim){
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void combSort(int *vetor, int tamanho){
    float divisor = 1.3;
    int gap = tamanho, swapped = 1, aux, i;

    while ((gap > 1) || swapped == 1) {
        if (gap > 1) gap = gap / divisor;
        swapped = 0;
        i = 0;

        while ((gap + i) < tamanho) {
            if (vetor[i] > vetor[i + gap]) {
                aux = vetor[i];
                vetor[i] = vetor[i + gap];
                vetor[i + gap] = aux;
                swapped = 1;
            }
            i++;
        }
    }
}

void cocktailSort(int *vetor, int tamanho){
    int inicio = 0, fim = tamanho-1, swapped = 0, i, aux;

    while(swapped == 0 && inicio < fim){
        swapped = 1;

        for(i = inicio; i < fim; i++){
            if(vetor[i] > vetor[i + 1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                swapped = 0;
            }
        }
        fim--;
        for(i = fim; i > inicio; i--){
            if(vetor[i] < vetor[i - 1]){
                aux = vetor[i];
                vetor[i] = vetor[i-1];
                vetor[i-1] = aux;
                swapped = 0;
            }
        }
        inicio++;
    }
 }

void gnomeSort(int *vetor, int tamanho){
   int i = 1, aux;

   while(i < tamanho){
       if(vetor[i-1] <= vetor[i]) i++;
       else{
           aux = vetor[i];
           vetor[i] = vetor[i-1];
           vetor[i-1] = aux;
           i--;
           if(i == 0) i = 1;
       }
   }
}

void radixSort(int *vetorA, int tamanho){
    int *vetorB, i, exp = 1, maior = vetorA[0];

    vetorB = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetorA[i] > maior)
    	    maior = vetorA[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++){
    	    bucket[(vetorA[i] / exp) % 10]++;
    	}
    	for (i = 1; i < 10; i++){
    	    bucket[i] += bucket[i - 1];
    	}
    	for (i = tamanho - 1; i >= 0; i--){
    	    vetorB[--bucket[(vetorA[i] / exp) % 10]] = vetorA[i];
    	}
    	for (i = 0; i < tamanho; i++) vetorA[i] = vetorB[i];
    	exp *= 10;
    }

    free(vetorB);
}
