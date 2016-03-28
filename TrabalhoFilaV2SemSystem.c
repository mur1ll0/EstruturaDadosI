#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    struct Node *prox;
};
typedef struct Node node;

struct Fila{
    node *front;
    node *back;
};
typedef struct Fila fila;



void printFila(fila *row);
int inicializaFila(int *finalFila, int *tamanho);
int filaCheia(int tamanho, int maxtam);
int filaVazia(int tamanho, int maxtam, int *finalFila);
int pushFila(fila *row, int *finalFila, int maxtam, int *tamanho);
int popFila(fila *row, int *finalFila, int maxtam, int *tamanho);
void filaLibera(fila *row);


int main()
{
    int finalFila, maxtam = 15, numero, tamanho, filaIniciada = 0;
    char c;
    fila *filaListas;

    int menu;

    while(1){
        //system("cls");
        if (filaIniciada != 0) printFila(filaListas);


        if (filaIniciada == 0){
            printf("        TRABALHO FILAS      \n"
                   "1-Iniciar fila\n"
                   "2-Inserir elemento na fila\n"
                   "3-Remover elemento da fila (fila anda)\n"
                   "4-Verifica se fila esta cheia\n"
                   "5-Verifica se fila esta vazia\n\n"
                   "Para sair digite qualquer outro numero.");
        }

        printf("\n\nEscolha: ");
        scanf(" %d", &menu);
        if (filaIniciada == 0 && menu > 1 && menu <= 5){
            printf("\n\nFila ainda nao foi iniciada, por favor inicie a fila!.\nPressione qualquer tecla para continuar.\n");
            //system("pause");
            getch();
            continue;
        }

        switch(menu){
        case 1:
            filaListas = inicializaFila(&finalFila, &tamanho);
            printf("\n\nFila inicializada.\nPressione qualquer tecla para continuar.\n");
            filaIniciada = 1;
            //system("pause");
            getch();
            break;
        case 2:
            pushFila(filaListas, &finalFila, maxtam, &tamanho);
            //system("pause");
            getch();
            break;
        case 3:
            numero = popFila(filaListas, &finalFila, maxtam, &tamanho);
            if (numero != 0) printf("\n\nValor removido: %d\nPressione qualquer tecla para continuar.\n", numero);
            //system("pause");
            getch();
            break;
        case 4:
            if (filaCheia(tamanho, maxtam)) printf("\n\n A fila nao esta cheia.\nPressione qualquer tecla para continuar.\n");
            else printf("\n\n Fila esta cheia.\nPressione qualquer tecla para continuar.\n");
            //system("pause");
            getch();
            break;
        case 5:
            if (filaVazia(tamanho, maxtam, &finalFila)) printf("\n\n Fila esta vazia.\nPressione qualquer tecla para continuar.\n");
            else printf("\n\n Fila nao esta vazia.\nPressione qualquer tecla para continuar.\n");
            //system("pause");
            getch();
            break;
        default:
            return 0;
        }
    }
    filaLibera(filaListas);
    return 0;
}

//
//FUNCOES
//


void printFila(fila *row){
    node *elemento = row->front;

    printf("\nFILA:");

    while(elemento != NULL){
        node *proxElemento = elemento->prox;
        printf(" %d", elemento->num);
        elemento = proxElemento;
    }
    printf("\n\n\n");
}


int inicializaFila(int *finalFila, int *tamanho){
    fila *row;
    row = (fila *)malloc(sizeof(fila));
    if (row == NULL){
        printf("\nMemoria Insuficiente\n");
        exit(1);
    }
    *finalFila = 0;
    *tamanho = 0;


    row->front = NULL;
    row->back = NULL;

    return row;
}

int filaCheia(int tamanho, int maxtam){
    if (tamanho == maxtam) return 0;
    else return 1;
}

int filaVazia(int tamanho, int maxtam, int *finalFila){
    if (tamanho == 0){
        *finalFila = 0;
        return 1;
    }
    else return 0;
}

int pushFila(fila *row, int *finalFila, int maxtam, int *tamanho){
    int size;

    filaVazia(*tamanho, maxtam, finalFila);

    if (filaCheia(*tamanho, maxtam)){
        size = *finalFila;
        size++;
        *finalFila = size;

        size = *tamanho;
        size++;
        *tamanho = size;

        node *elemento;

        elemento = (node *)malloc(sizeof(node));
        if (elemento == NULL){
            printf("\nMemoria Insuficiente\n");
            exit(1);
        }
        elemento->num = *finalFila;
        elemento->prox = NULL;

        if (row->back != NULL){ //Se nao for o primeiro elemento
            node *anterior;

            anterior = row->back;
            anterior->prox = elemento;

            row->back = elemento;
        }
        else{
            row->front = elemento;
            row->back = elemento;
        }
        printf("\n\nElemento adicionado: %d\nPressione qualquer tecla para continuar.\n", elemento->num);
    }
    else {
        printf("\nFila Cheia\nPressione qualquer tecla para continuar.\n");
        return 0;
    }
    return 1;
}

int popFila(fila *row, int *finalFila, int maxtam, int *tamanho){
    node *elemento;
    int num, size;

    if (filaVazia(*tamanho, maxtam, finalFila)){
        printf("\nFila Vazia\nPressione qualquer tecla para continuar.\n");
        return 0;
    }

    size = *tamanho;
    size--;
    *tamanho = size;

    elemento = row->front;
    num = elemento->num;

    row->front = elemento->prox;

    if(row->front == NULL) row->back = NULL;

    free(elemento);
    return num;
}

void filaLibera(fila *row){
    node *elemento = row->front;

    while(elemento != NULL){
        node *proxElemento = elemento->prox;
        free(elemento);
        elemento = proxElemento;
    }
    free(row);
}
