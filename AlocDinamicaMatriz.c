#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int linhas, colunas, a, b;

    srand(time(NULL));

    printf("Digite o numero de linhas: ");
    scanf(" %d", &linhas);

    int **matriz;
    matriz = malloc(linhas * sizeof(int));

    if (matriz == NULL){
        printf("\nMemoria Insuficiente.\n");
        return 0;
    }

    for (a = 0; a < linhas; a++){
        printf("\nLinha %d Quantidade de colunas: ", a);
        scanf(" %d", &colunas);
        //Alocar as colunas na linha indidcada por a, e um espaço que vai dizer o final da coluna (9999)
        matriz[a] = malloc((colunas + 1)* sizeof(int));
        if (matriz == NULL){
            printf("\nMemoria Insuficiente.\n");
            return 0;
        }
        //Popular a coluna
        for (b = 0; b < colunas; b++){
            matriz[a][b] = rand() % 100;
        }
        matriz[a][colunas] = 9999;
    }
    printf("\n\n");
    //Imprimir saída
    for (a = 0; a < linhas; a++){
        printf("\nEnd %x - ", &matriz[a]);
        b = 0;
        while (matriz[a][b] != 9999){
            printf(" %d", matriz[a][b]);
            b++;
        }
    }
    free(matriz);
    return 0;
}
