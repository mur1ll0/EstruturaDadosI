#include <stdio.h>
#include <stdlib.h>


int binaria(int vetor[], int valor, int inicio, int fim){
	int meio = 0;

	while(inicio <= fim){
        meio = (inicio+fim)/2;
		if (inicio == fim){
            if (vetor[meio] > valor){
                return meio;
            }
            else if (vetor[meio] < valor){
                inicio = ++meio;
            }
		}
		else {
            if (vetor[meio] > valor){
                fim = meio;
            }
            else if (vetor[meio] < valor){
                inicio = meio + 1;
            }
		}
	}
	return meio;
}

void insercao(int v[],int n){
	int i, j, k;
	int aux;

	for(i=1; i<n; i++){
		j = binaria(v, v[i], 0, i-1);
		aux = v[i];

		for(k=i; k>j; k--){
			v[k] = v[k-1];
		}
		v[j] = aux;
	}
}

int main(){
	int *vetor, tamanho, i, valor;

	tamanho = 10;

	vetor = (int *)malloc(tamanho*(sizeof(int)));

	for(i=0; i<tamanho; i++){
		scanf(" %d%*c", &valor);
		vetor[i] = valor;
	}

	insercao(vetor, tamanho);

	printf("\n\nVetor Ordenado:");
	for(i=0; i<tamanho; i++){
		printf(" %d", vetor[i]);
	}

	printf("\n\nFim\n");
	return 0;
}

