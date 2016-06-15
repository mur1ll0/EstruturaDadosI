#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct _contato{
    char nome[40];
    char fone[30];
}TpContato;

typedef struct _lista{
    TpContato *contato;
    struct _lista *next;
    struct _lista *prev;
}TpLista;

TpContato *criarVetor(TpContato *vetor);
TpLista *criarLista(TpLista *lista, int tamanho);
TpContato *copiaVetor(TpContato *vetor);
TpLista *copiaLista(TpLista *lista);
void printVetor(TpContato *vetor);
void printLista(TpLista *lista);
void printMenu(TpContato *vetor, TpLista *lista);
void shellSortVetor(TpContato *vet, int tamanho);
void shellSortLista(TpLista *lst, int tamanho);
int partitionVetor(TpContato *vetor, int p, int q);
void quickSortVetor(TpContato *vetor, int p, int q);
TpLista *partitionLista(TpLista *pLista, TpLista *first, TpLista *last);
void quickSortLista(TpLista *lista, TpLista *noInicio, TpLista *noFim);


int main(){
    srand((unsigned)time(NULL));
    TpContato *vetor = NULL, *vetorCopia = NULL;
    TpLista *lista = NULL, *listaCopia = NULL, *listaFim;
    clock_t tempo;
    int lista_tamanho, menu;

	do{
		printMenu(vetor, lista);
		scanf(" %d", &menu);
		getchar();
		switch(menu){
			case 1:
				printf("Digite o tamanho a lista a ser criada: ");
				scanf(" %d", &lista_tamanho);
				getchar();
				lista = criarLista(lista, lista_tamanho);
				break;
			case 2:
				vetor = criarVetor(vetor);
				break;
			case 3:
			    if(vetor == NULL && lista == NULL) printf("\nERRO: vetor e lista nao foram iniciados\n");
			    else if(vetor == NULL) printf("\nERRO: vetor nao foi iniciado\n");
			    else if(lista == NULL) printf("\nERRO: lista nao foi iniciada\n");
			    else{
                    vetorCopia = copiaVetor(vetor);
                    tempo = clock();
                    shellSortVetor(vetorCopia, 40);
                    tempo = clock() - tempo;
                    printVetor(vetorCopia);
                    printf("\n--------------------\nTempo: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));

                    listaCopia = copiaLista(lista);
                    tempo = clock();
                    shellSortLista(listaCopia, lista_tamanho);
                    tempo = clock() - tempo;
                    printLista(listaCopia);
                    printf("\n--------------------\nTempo: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));
			    }
			    getchar();
				break;
			case 4:
			    if(vetor == NULL && lista == NULL) printf("\nERRO: vetor e lista nao foram iniciados\n");
			    else if(vetor == NULL) printf("\nERRO: vetor nao foi iniciado\n");
			    else if(lista == NULL) printf("\nERRO: lista nao foi iniciada\n");
			    else{
                    vetorCopia = copiaVetor(vetor);
                    tempo = clock();
                    quickSortVetor(vetorCopia, 0, 39);
                    tempo = clock() - tempo;
                    printVetor(vetorCopia);
                    printf("\n--------------------\nTempo: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));

                    listaCopia = copiaLista(lista);
                    listaFim = listaCopia;
                    while(listaFim->next != NULL) listaFim = listaFim->next;

                    tempo = clock();
                    quickSortLista(listaCopia, listaCopia, listaFim);
                    tempo = clock() - tempo;
                    printLista(listaCopia);
                    printf("\n--------------------\nTempo: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));
			    }
			    getchar();
				break;
			case 5:
				return 1;
		}
	}while(1);

    return 0;
}

////////////////////////////////////////////////////////////////////
///////////
//FUNCOES//
///////////

TpContato *criarVetor(TpContato *vetor){
    srand((unsigned)time(NULL));
    int i, j;

	vetor = (TpContato *)malloc(40*sizeof(TpContato));

    for(i=0; i<40; i++){
        vetor[i].nome[0] = 'F';
        vetor[i].nome[1] = 'u';
        vetor[i].nome[2] = 'l';
        vetor[i].nome[3] = 'a';
        vetor[i].nome[4] = 'n';
        vetor[i].nome[5] = 'o';
        vetor[i].nome[6] = ' ';
        vetor[i].nome[7] = 48+(rand()%10);
        vetor[i].nome[8] = 48+(rand()%10);
        vetor[i].nome[9] = 48+(rand()%10);
        vetor[i].nome[10] = '\0';

        vetor[i].fone[0] = 49+(rand()%9);
        for(j=1; j<9; j++){
            vetor[i].fone[j] = 48+(rand()%10);
        }
        vetor[i].fone[9] = '\0';
    }
    return vetor;
}

TpLista *criarLista(TpLista *lista, int tamanho){
    TpLista *addElemento, *last = NULL;
    TpContato *addContato;
    int i, j;

    last = lista;

    for (i=0; i<tamanho; i++){
        addContato = (TpContato *)malloc(sizeof(TpContato));
        addContato->nome[0] = 'F';
        addContato->nome[1] = 'u';
        addContato->nome[2] = 'l';
        addContato->nome[3] = 'a';
        addContato->nome[4] = 'n';
        addContato->nome[5] = 'o';
        addContato->nome[6] = ' ';
        addContato->nome[7] = 48+(rand()%10);
        addContato->nome[8] = 48+(rand()%10);
        addContato->nome[9] = 48+(rand()%10);
        addContato->nome[10] = '\0';

        addContato->fone[0] = 49+(rand()%9);
        for(j=1; j<9; j++){
            addContato->fone[j] = 48+(rand()%10);
        }
        addContato->fone[9] = '\0';

        addElemento = (TpLista *)malloc(sizeof(TpLista));
        addElemento->contato = addContato;
        addElemento->next = NULL;
        addElemento->prev = last;

        if(last == NULL){
            lista = addElemento;
            last = lista;
        }
        else{
            last->next = addElemento;
            last = addElemento;
        }
    }

    return lista;
}

TpContato *copiaVetor(TpContato *vetor){
    srand((unsigned)time(NULL));
    int i, j;
    TpContato *vetor2;

	vetor2 = (TpContato *)malloc(40*sizeof(TpContato));

    for(i=0; i<40; i++){
        vetor2[i].nome[0] = '\0';
        vetor2[i].fone[0] = '\0';
        strcat(vetor2[i].nome, vetor[i].nome);
        strcat(vetor2[i].fone, vetor[i].fone);
    }
    return vetor2;
}

TpLista *copiaLista(TpLista *lista){
    TpLista *lista2 = NULL, *addElemento, *last = NULL, *lerLista;
    TpContato *addContato;
    int i, j;

    last = lista2;

    lerLista = lista;
    while(lerLista != NULL){
        addContato = (TpContato *)malloc(sizeof(TpContato));
        addContato->nome[0] = '\0';
        addContato->fone[0] = '\0';
        strcat(addContato->nome, lerLista->contato->nome);
        strcat(addContato->fone, lerLista->contato->fone);

        addElemento = (TpLista *)malloc(sizeof(TpLista));
        addElemento->contato = addContato;
        addElemento->next = NULL;
        addElemento->prev = last;

        if(last == NULL){
            lista2 = addElemento;
            last = lista2;
        }
        else{
            last->next = addElemento;
            last = addElemento;
        }
        lerLista = lerLista->next;
    }
    return lista2;
}

void printVetor(TpContato *vetor){
	int i, j;

	printf("\nVetor:\n");
	if (vetor == NULL) printf("Vazio");
	else{
		for(i=0; i<40; i++){
			printf("\n--------------------\nNome: ");
			for (j=0; j<11; j++){
				printf("%c", vetor[i].nome[j]);
			}
			printf("\nFone: ");
			for(j=0; j<9; j++){
				printf("%c", vetor[i].fone[j]);
			}
		}
	}
}

void printLista(TpLista *lista){
	int i, j;
	TpLista *lerLista;

    printf("\n\n\nLista:\n");
    if (lista == NULL) printf("Vazio");
	else{
		lerLista = lista;
		while(lerLista != NULL){
			printf("\n--------------------\nNome: ");
			for (j=0; j<11; j++){
				printf("%c", lerLista->contato->nome[j]);
			}
			printf("\nFone: ");
			for(j=0; j<9; j++){
				printf("%c", lerLista->contato->fone[j]);
			}
			lerLista = lerLista->next;
		}
	}
}

void printMenu(TpContato *vetor, TpLista *lista){
	int i, j;
	TpLista *lerLista;

	printVetor(vetor);
	printLista(lista);

    printf("\n\n"
			"1) Criar Lista\n"
			"2) Criar Vetor\n"
            "3) Algoritmo a ser estudado\n"
            "4) Metodo logaritmico\n"
            "5) Sair\n");
}

void shellSortVetor(TpContato *vet, int tamanho){
    int i , j, h = 1;
    char nome[40], fone[40];
    do {
        h = 3*h+1;
    } while(h < tamanho);
    do {
        h /= 3;
        for(i = h; i < tamanho; i++) {
            nome[0] = '\0';
            fone[0] = '\0';
            strcat(nome, vet[i].nome);
            strcat(fone, vet[i].fone);
            j = i - h;
            while(j >= 0 && strcmp(nome, vet[j].nome) < 0){
                vet[j + h].nome[0] = '\0';
                vet[j + h].fone[0] = '\0';
                strcat(vet[j + h].nome, vet[j].nome);
                strcat(vet[j + h].fone, vet[j].fone);
                j -= h;
            }
            vet[j + h].nome[0] = '\0';
            vet[j + h].fone[0] = '\0';
            strcat(vet[j + h].nome, nome);
            strcat(vet[j + h].fone, fone);
        }
    } while( h > 1);
}

void shellSortLista(TpLista *lst, int tamanho){
    int i , j, h = 1, contador = 0;
    char nome[40], fone[40];
    TpLista *lerH, *lerI, *lerJ, *lerJH;

    do {
        h = 3*h+1;
    } while(h < tamanho);
    do {
        h /= 3;
        lerH = lst;
        for (contador = 0; contador < h; contador++){
            lerH = lerH->next;
        }
        i = h;
        for(lerI = lerH; lerI != NULL; lerI = lerI->next){
            nome[0] = '\0';
            fone[0] = '\0';
            strcat(nome, lerI->contato->nome);
            strcat(fone, lerI->contato->fone);
            j = i - h;
            lerJ = lst;
            for (contador = 0; contador < j; contador++){
                lerJ = lerJ->next;
            }
            while(j >= 0 && strcmp(nome, lerJ->contato->nome) < 0){
                lerJH = lst;
                for (contador = 0; contador < j+h; contador++){
                    lerJH = lerJH->next;
                }
                lerJH->contato->nome[0] = '\0';
                lerJH->contato->fone[0] = '\0';
                strcat(lerJH->contato->nome, lerJ->contato->nome);
                strcat(lerJH->contato->fone, lerJ->contato->fone);
                j -= h;
                lerJ = lst;
                for (contador = 0; contador < j; contador++){
                    lerJ = lerJ->next;
                }
            }
            lerJH = lst;
            for (contador = 0; contador < j+h; contador++){
                lerJH = lerJH->next;
            }
            lerJH->contato->nome[0] = '\0';
            lerJH->contato->fone[0] = '\0';
            strcat(lerJH->contato->nome, nome);
            strcat(lerJH->contato->fone, fone);
            i++;
        }
    } while( h > 1);
}

int partitionVetor(TpContato *vetor, int p, int q){
    int i = p, j = q;
    char pivo[40], nome[40], fone[40];

    pivo[0] = '\0';
    strcat(pivo, vetor[p].nome);

    while(i < j){
        while(strcmp(vetor[i].nome, pivo) < 0 && i < q) i++;
        while(strcmp(vetor[j].nome, pivo) > 0 && j > p) j--;
        if (strcmp(vetor[i].nome, vetor[j].nome) > 0){
            nome[0] = '\0';
            fone[0] = '\0';
            strcat(nome, vetor[i].nome);
            strcat(fone, vetor[i].fone);
            vetor[i].nome[0] = '\0';
            vetor[i].fone[0] = '\0';
            strcat(vetor[i].nome, vetor[j].nome);
            strcat(vetor[i].fone, vetor[j].fone);
            vetor[j].nome[0] = '\0';
            vetor[j].fone[0] = '\0';
            strcat(vetor[j].nome, nome);
            strcat(vetor[j].fone, fone);
        }
		else if (strcmp(vetor[i].nome, vetor[j].nome) == 0) j--;
    }
    return i;
}

void quickSortVetor(TpContato *vetor, int p, int q){
    int r;

	r = partitionVetor(vetor, p, q);
	if(r-1 > p) quickSortVetor(vetor, p, r-1);
	if(r+1 < q) quickSortVetor(vetor, r+1, q);
}


TpLista *partitionLista(TpLista *pLista, TpLista *first, TpLista *last) {
	TpLista *noEsquerda = first, *noDireita = last, *pivo = first;
	char nome[40], fone[40];

    while(noEsquerda != NULL && strcmp(noEsquerda->contato->nome, pivo->contato->nome) < 0) noEsquerda = noEsquerda->next;
    while(noDireita != NULL && strcmp(noDireita->contato->nome, pivo->contato->nome) > 0) noDireita = noDireita->prev;

	while (noDireita != NULL && noEsquerda != noDireita && noEsquerda != noDireita->next) {
		nome[0] = '\0';
        fone[0] = '\0';
        strcat(nome, noEsquerda->contato->nome);
        strcat(fone, noEsquerda->contato->fone);
        noEsquerda->contato->nome[0] = '\0';
        noEsquerda->contato->fone[0] = '\0';
        strcat(noEsquerda->contato->nome, noDireita->contato->nome);
        strcat(noEsquerda->contato->fone, noDireita->contato->fone);
        noDireita->contato->nome[0] = '\0';
        noDireita->contato->fone[0] = '\0';
        strcat(noDireita->contato->nome, nome);
        strcat(noDireita->contato->fone, fone);

		do {
            if (noDireita != NULL) noDireita = noDireita->prev;
        } while(noDireita != NULL && strcmp(noDireita->contato->nome, pivo->contato->nome) > 0);

		do {
            if (noEsquerda != NULL) noEsquerda = noEsquerda->next;
        } while(noEsquerda != NULL && strcmp(noEsquerda->contato->nome, pivo->contato->nome) < 0);
	}
	return noDireita;
}
void quickSortLista(TpLista *lista, TpLista *noInicio, TpLista *noFim) {
	TpLista *part;
	if (noFim != NULL && noInicio!= NULL && noInicio != noFim && noInicio != noFim->next) {
		part = partitionLista(lista, noInicio, noFim);
		quickSortLista(lista, noInicio, part);
		quickSortLista(lista, part->next, noFim);
	}
}
