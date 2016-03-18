#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum boolean{
    true = 1, false = 0
};
typedef enum boolean bool;


//VARIAVEIS PARA CONTROLAR O TAMANHO DA PILHA
int tamanho;



bool pilhaVazia(int topo){
    return (topo == -1);
}

bool pilhaCheia(int topo){
    return (topo == tamanho);
}


bool pilhaPush(char *Pilha, int *topo, char valor){        //EMPILHAR
    int top;
    if (pilhaCheia(*topo)) return false;
    else{
        top = *topo;
        //*topo nao pode ser incrementado, da erro. Entao incrementa top depois atribui o valor a *topo.
        top++;
        *topo = top;
        Pilha[*topo] =  valor;
    }
    return true;
}

bool pilhaPop(char *Pilha, int *topo, char *valor){         //DESEMPILHAR
    int top;
    if (pilhaVazia(*topo)) return false;
    else{
        *valor = Pilha[*topo];
        Pilha[*topo] =  NULL;
        top = *topo;
        top--;
        *topo = top;
    }
    return true;
}

bool popPalavra(char *Pilha1, int *topo1, char *Pilha2, int *topo2){
    int a, b, contador = 0, top, valor;
    char *palavra;

    if ((palavra = (char *)malloc(sizeof(char))) == NULL){
        printf("\nMemoria Insuficiente\n");
        return false;
    }

    while (*topo1 > -1){
        top = *topo1;
        contador = 0;
        while ((Pilha1[top] != 32) && (top != -1)){
            contador++;
            top--;
        }

        for (a = 0; a < contador; a++){
            if ((palavra = realloc(palavra, contador*sizeof(char))) == NULL){
                printf("\nMemoria Insuficiente.\n");
                return false;
            }
            pilhaPop(Pilha1, topo1, &valor);
            palavra[a] = valor;
        }


        for (a = contador - 1; a > -1; a--){
            pilhaPush(Pilha2, topo2, palavra[a]);
        }

        //**EMPILHAR O ESPAÇO**
        if (Pilha1[*topo1] == 32){
            pilhaPop(Pilha1, topo1, &valor);
            pilhaPush(Pilha2, topo2, valor);
        }
    }

    return true;
}



int main()
{
    int a, topo1 = -1, topo2 = -1;
    char *texto, c, *pilha1, *pilha2;

    if ((texto = (char *)malloc(sizeof(char))) == NULL){
        printf("\nMemoria Insuficiente\n");
        return 0;
    }

    tamanho = 0;

    printf("Digite o texto:\n");

    while((c = getchar()) != 10){       //Recebe um char até ser diferente do ENTER
        if ((texto = realloc(texto, (tamanho + 1)*sizeof(char))) == NULL){
            printf("\nMemoria Insuficiente\nTamanho: %d\n", (tamanho + 1)*sizeof(char));
            return 0;
        }
        texto[tamanho] = c;
        tamanho++;
    }
    texto[tamanho] = '\0';

    if ((pilha1 = (char *)malloc((tamanho) * sizeof(char))) == NULL){
        printf("\nMemoria Insuficiente\n");
        return 0;
    }

    for (a = 0; a < tamanho; a++){
        pilhaPush(pilha1, &topo1, texto[a]);
    }

    if ((pilha2 = (char *)malloc(tamanho * sizeof(char))) == NULL){
        printf("\nMemoria Insuficiente\n");
        return 0;
    }

    popPalavra(pilha1, &topo1, pilha2, &topo2);


    printf("\nSaida: ");
    while (topo2 > -1){
        pilhaPop(pilha2, &topo2, &c);
        printf("%c", c);
    }

    printf("\n\n");
    return 0;
}
