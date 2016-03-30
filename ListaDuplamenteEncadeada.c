#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int data;
    struct Lista *next;
    struct Lista *ant;
};
typedef struct Lista lista;

lista *iniciaLista(){
    lista *inicio;
    inicio = (lista *)malloc(sizeof(lista));

    if (inicio == NULL){
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    inicio->data = 0;
    inicio->next = NULL;
    inicio->ant;

    return inicio;
}

void listaPushInicio(lista *inicio, int num){
    lista *elemento;
    elemento = (lista *)malloc(sizeof(lista));

    if (elemento == NULL){
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }

    elemento->data = num;
    elemento->next = inicio->next;
    elemento->ant = inicio;
    inicio->next = elemento;

    if (elemento->next != NULL){
        elemento->next->ant = elemento;
    }

}

void printLista(lista *listaPrintar){
    lista *elemento = listaPrintar->next;

    printf("\nLISTA:");

    while(elemento != NULL){
        lista *proxElemento = elemento->next;
        printf(" %d", elemento->data);
        elemento = proxElemento;
    }
    printf("\n\n\n");
}

lista *listaPushMeio(lista *listaModificar, int num, int pos){
    int posicao=1;
    lista *novaLista, *elemento;

    elemento = (lista *)malloc(sizeof(lista));

    if (elemento == NULL){
        printf("\nErro de Memoria\n");
        exit(1);
    }
    elemento->data = num;

    novaLista = listaModificar;

    while (posicao != pos){
        novaLista = novaLista->next;
        posicao++;
    }
    elemento->next = novaLista->next;
    novaLista->next = elemento;
    elemento->ant = novaLista;
    elemento->next->ant = elemento;

    novaLista = listaModificar;

    return novaLista;
}

lista *excluir(lista *listaPraExcluir, int pos){
    lista *novaLista, *elementoEliminado;
    int posicao = 1;

    novaLista = listaPraExcluir;

    while (posicao != pos){
        novaLista = novaLista->next;
        posicao++;
    }
    elementoEliminado = novaLista->next;
    novaLista->next = elementoEliminado->next;
    novaLista->next->ant = novaLista;
    free(elementoEliminado);

    novaLista = listaPraExcluir;

    return novaLista;
}

void consultaElemento(lista *consulta, int pos){
    lista *percorrer;
    int posicao = 0;

    percorrer = consulta;

    while (posicao != pos){
        percorrer = percorrer->next;
        posicao++;
    }
    printf("\nElemento na posicao %d:\nValor: %d\nAnterior: %d\nSucessor: %d\n", pos, percorrer->data, percorrer->ant->data, percorrer->next->data);
}

int main(){

    lista *duplaEncadeada;

    duplaEncadeada = iniciaLista();
    printLista(duplaEncadeada);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(duplaEncadeada, 1);
    printLista(duplaEncadeada);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(duplaEncadeada, 2);
    printLista(duplaEncadeada);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(duplaEncadeada, 3);
    printLista(duplaEncadeada);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(duplaEncadeada, 4);
    printLista(duplaEncadeada);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(duplaEncadeada, 5);
    printLista(duplaEncadeada);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(duplaEncadeada, 6);
    printLista(duplaEncadeada);

    consultaElemento(duplaEncadeada, 3);
    consultaElemento(duplaEncadeada, 4);

    printf("\nAdiciona elemento 10 na quarta posicao da lista.");
    duplaEncadeada = listaPushMeio(duplaEncadeada, 10, 4);
    printLista(duplaEncadeada);

    consultaElemento(duplaEncadeada, 3);
    consultaElemento(duplaEncadeada, 4);
    consultaElemento(duplaEncadeada, 5);

    printf("\nExclui elemento na terceira posicao da lista.");
    duplaEncadeada = excluir(duplaEncadeada, 3);
    printLista(duplaEncadeada);

    consultaElemento(duplaEncadeada, 1);
    consultaElemento(duplaEncadeada, 2);
    consultaElemento(duplaEncadeada, 3);
    consultaElemento(duplaEncadeada, 4);
    consultaElemento(duplaEncadeada, 5);



    return 0;
}
