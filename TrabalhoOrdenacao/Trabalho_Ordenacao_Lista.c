#include <stdio.h>
#include <stdlib.h>

typedef struct _lista{
    int valor;
    struct _lista *next;
    struct _lista *prev;
}lista;

void insertionSort(lista *lst, int qntd){
    int chave;
    lista *lerLst, *anterior;

    lerLst = lst->next;
    while(lerLst != NULL){
        chave = lerLst->valor;
        anterior = lerLst->prev;
        while(anterior->prev != NULL && anterior->valor > chave){
            anterior->next->valor = anterior->valor;
            anterior = anterior->prev;
        }
        anterior->next->valor = chave;
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
    int qntd, num;
    lista *lst, *last, *head;
    char c;

    lst = (lista *)malloc(sizeof(lista));
    lst->next = NULL;
    lst->prev = NULL;
    last = lst;
    head = lst;
    qntd = 0;

    printf("\nDigite a lista de numeros: ");
    do{
        scanf(" %d%c", &num, &c);

        lst = (lista *)malloc(sizeof(lista));
        lst->valor = num;
        lst->next = NULL;
        lst->prev = last;
        last->next = lst;
        last = lst;
        qntd++;

    }while(c != 10);

    head = head->next;
    head->prev = NULL;

    printf("\nDigite:\n1 - insertSort\n2 - bubbleSort\n");
    scanf(" %d", &num);
    getchar();

    if(num == 1) insertionSort(head, qntd);
    else if(num == 2) bubbleSort(head, qntd);

    printf("\n\nLista ordenada: ");

    lst = head;
    while(lst != NULL){
        printf(" %d", lst->valor);
        lst = lst->next;
    }
    printf("\n\nFim\n");

    return 0;
}
