#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _lista{
    int valor;
    struct _lista *next;
    struct _lista *prev;
}lista;

void insertionSort(lista *lst, int qntd){
    int chave;
    lista *lerLst, *anterior, *aux;

    lerLst = lst->next;
    while(lerLst != NULL){
        chave = lerLst->valor;
        anterior = lerLst->prev;
        while(anterior != NULL && anterior->valor > chave){
            anterior->next->valor = anterior->valor;
            aux = anterior;
            anterior = anterior->prev;
        }
        if(anterior == NULL) aux->valor = chave;
        else anterior->next->valor = chave;
        lerLst = lerLst->next;
    }
}

void bubbleSort(lista *lst, int qntd){
    int trocou, aux, i;
    lista *lerLst;
    do{
        trocou = 0;
        lerLst = lst->next;
        while(lerLst != NULL){
            if(lerLst->prev->valor > lerLst->valor){
                aux = lerLst->valor;
                lerLst->valor = lerLst->prev->valor;
                lerLst->prev->valor = aux;
                trocou = 1;
            }
            lerLst = lerLst->next;
        }
    }while(trocou == 1);
}


int main()
{
    int qntd, num, i;
    lista *lst, *last, *head;
    clock_t tempo;

    srand((unsigned)time(NULL));

    lst = (lista *)malloc(sizeof(lista));
    lst->next = NULL;
    lst->prev = NULL;
    last = lst;
    head = lst;

    qntd = rand() % 20000;

    for(i=0; i<qntd; i++){
        num = rand() % 200;
        lst = (lista *)malloc(sizeof(lista));
        lst->valor = num;
        lst->next = NULL;
        lst->prev = last;
        last->next = lst;
        last = lst;
    }
    head = head->next;
    head->prev = NULL;

    printf("\nDigite:\n1 - insertSort\n2 - bubbleSort\n");
    scanf(" %d", &num);
    getchar();

    if(num == 1){
        tempo = clock();
        insertionSort(head, qntd);
        tempo = clock() - tempo;
    }
    else if(num == 2){
        tempo = clock();
        bubbleSort(head, qntd);
        tempo = clock() - tempo;
    }

    printf("\n\nLista ordenada: ");

    lst = head;
    while(lst != NULL){
        printf(" %d", lst->valor);
        lst = lst->next;
    }

    printf("\nTempo de execucao: %lf s", ((double)tempo)/((CLOCKS_PER_SEC/1)));
    printf("\n\nFim\n");

    return 0;
}
