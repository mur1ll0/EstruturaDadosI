#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int data;
    struct Lista *next;
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
    inicio->next = elemento;

}

void printLista(lista *inicio){
    lista *elemento = inicio->next;

    printf("\nLISTA:");

    while(elemento != NULL){
        lista *proxElemento = elemento->next;
        printf(" %d", elemento->data);
        elemento = proxElemento;
    }
    printf("\n\n\n");
}

lista *listaPushMeio(lista *inicio, int num, int pos){
    int posicao=1;
    lista *novaLista, *elemento;

    elemento = (lista *)malloc(sizeof(lista));

    if (elemento == NULL){
        printf("\nErro de Memoria\n");
        exit(1);
    }
    elemento->data = num;

    novaLista = inicio; //Carrega novaLista com os elementos de inicio

    /*
    Quando se usa lista->next, o valor retornado é o endereço de memoria do proximo elemento.
    Utilizando um ponteiro, é possivel modificar esse elemento diretamente sem a necessidade de recria-lo na função.
    É o que acontece em novaLista = novaLista->next
    */

    while (posicao != pos){             //Ate atingir o elemento na posicao desejada
        novaLista = novaLista->next;    //Avanca um elemento
        posicao++;
    }
    elemento->next = novaLista->next;   //Novo elemento recebe com proximo o elemento que estava na sua posição
    novaLista->next = elemento;         //O elemento anterior recebe como proximo o elemento criado;

    novaLista = inicio;                 //novaLista recebe todos os elementos atualizados

    return novaLista;
}

lista *excluir(lista *listaPraExcluir, int pos){
    lista *novaLista, *elementoEliminado;
    int posicao=1;

    novaLista = listaPraExcluir;

    while (posicao != pos){
        novaLista = novaLista->next;
        posicao++;
    }
    elementoEliminado = novaLista->next;
    novaLista->next = elementoEliminado->next;
    free(elementoEliminado);

    novaLista = listaPraExcluir;

    return novaLista;
}

int main(){

    lista *inicio;

    inicio = iniciaLista();
    printLista(inicio);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(inicio, 1);
    printLista(inicio);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(inicio, 2);
    printLista(inicio);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(inicio, 3);
    printLista(inicio);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(inicio, 4);
    printLista(inicio);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(inicio, 5);
    printLista(inicio);

    printf("\nAdiciona elemento no inicio.");
    listaPushInicio(inicio, 6);
    printLista(inicio);

    printf("\nAdiciona elemento 10 na quarta posicao da lista.");
    inicio = listaPushMeio(inicio, 10, 4);
    printLista(inicio);

    printf("\nExclui elemento na terceira posicao da lista.");
    inicio = excluir(inicio, 3);
    printLista(inicio);



    return 0;
}
