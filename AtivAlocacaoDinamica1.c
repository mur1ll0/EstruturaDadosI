#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char num[32];
    int pos = 0, a = 0, numero, chave = 0;
    int *p;

    if ((p = (int *) calloc(5, sizeof(int))) == NULL){
        printf("\nMemoria Insuficiente\n");
        return 0;
    }

    do{
        printf("Digite um numero inteiro, ou uma letra para sair: ");
        scanf("%s", num);

        a = 0;

        while(num[a] != '\0'){
            if (num[a] >= 48 && num[a] <= 57){
                a++;
            }
            else{
                chave = 1;
                break;
            }
        }



        if (pos > 5){
            if ((p = (int *) realloc(p, pos + sizeof(int))) == NULL){

                printf("\nMemoria Insuficiente\n");
                return 0;
            }
        }
        if (chave != 1){
            numero = atoi(num);
            p[pos] = numero;
            pos++;
        }
    }while (chave == 0);

    for (a=0; a<pos; a++){
        printf("\n%d", p[a]);
    }
    printf("\nQuantidade de numeros inteiros: %d\n", pos);

    //p = (int *) realloc(p, 0);
    free(p);

    return 0;
}
