#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int info;
    struct _node *next;
    struct _node *prev;

}node;

typedef struct _lista{
    node *elemento;
    struct _lista *next;
    struct _lista *prev;
}lista;


lista * addConjunto(lista *Lista);
node *ordenarRol(node *conjunto);
int listar(lista *Lista);
int uniao(lista *Lista);
int interseccao(lista *Lista);
int diferenca(lista *Lista);
lista *delConjunto(lista *Lista);
lista *modificaConjunto(lista *Lista);
node *addElemento(node *Conjunto);
node *delElemento(node *Conjunto);



int main()
{
    lista *Lista;
    int menu;

    Lista = NULL;


    while (1){
        printf("\n###########################\n"
               "#       Trabalho NP1      #\n"
               "#     Murillo e Felipe    #\n"
               "###########################\n\n"
               "| 1 - Adicionar conjunto  |\n"
               "| 2 - Excluir conjunto    |\n"
               "| 3 - Alterar conjunto    |\n"
               "| 4 - Exibir Interseccao  |\n"
               "| 5 - Exibir Uniao        |\n"
               "| 6 - Exibir Diferenca    |\n"
               "| 7 - Listar conjuntos    |\n\n"
               "| Escolha: ");
        scanf(" %d", &menu);
        getchar();

        switch(menu){
            case 1:
                Lista = addConjunto(Lista);
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                break;
            case 2:
                Lista = delConjunto(Lista);
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                break;
            case 3:
                modificaConjunto(Lista);
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                break;
            case 4:
                interseccao(Lista);
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                break;
            case 5:
                uniao(Lista);
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                break;
            case 6:
                diferenca(Lista);
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                break;
            case 7:
                listar(Lista);
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                break;
            default:
                printf("\nO programa sera fechado.\n");
                return 0;
        }
    }
    return 0;
}

//######################################################
//#                                                    #
//#                      FUNÇÔES                       #
//#                                                    #
//######################################################

lista * addConjunto(lista *Lista){
    node *conjunto = NULL, *addCon, *last;
    lista *addLista, *lerLista;
    int valor;
    char c;

    printf("\n----------------------------------\n"
           "|       Adicionar Conjunto       |\n"
           "----------------------------------\n");

    if (Lista == NULL){
        Lista = (lista *)malloc(sizeof(lista));
        Lista->elemento = NULL;
        Lista->next = NULL;
        Lista->prev = NULL;
    }
    else{
        lerLista = Lista;
        while (lerLista->next != NULL) lerLista = lerLista->next;
        addLista = (lista *)malloc(sizeof(lista));
        addLista->elemento = NULL;
        addLista->next = NULL;
        addLista->prev = lerLista;
        lerLista->next = addLista;
    }
    printf("\nConjunto criado.\nAdicionar elementos (S/N)? ");
    c = getchar();
    getchar();

    if(c == 's' || c == 'S'){
        printf("\nConjunto: ");
        while(c != 10){
            scanf("%d%c", &valor, &c);

            if(conjunto == NULL){
                conjunto = (node *)malloc(sizeof(node));
                conjunto->info = valor;
                conjunto->next = NULL;
                conjunto->prev = NULL;
                last = conjunto;
            }
            else{
                addCon = (node *)malloc(sizeof(node));
                addCon->info = valor;
                addCon->next = NULL;
                addCon->prev = last;
                last->next = addCon;
                last = addCon;
            }
        }
        conjunto = ordenarRol(conjunto);
        lerLista = Lista;
        while (lerLista->next != NULL) lerLista = lerLista->next;
        lerLista->elemento = conjunto;

    }
    printf("\nConjunto criado com sucesso!\n");
    return Lista;
}

int listar(lista *Lista){
    node *conjunto;
    int contador = 0;

    printf("\n\n---------------------------------\n"
           "|       Lista de Conjuntos      |\n"
           "---------------------------------\n\n");

    if (Lista == NULL){
        printf("\nLista Vazia.\n");
        return 0;
    }

    while(Lista != NULL){
        conjunto = Lista->elemento;
        contador++;
        printf("Conjunto %d:", contador);
        if (conjunto == NULL){
            printf(" - NULL");
        }else{
            while(conjunto != NULL){
                printf(" %d", conjunto->info);
                conjunto = conjunto->next;
            }
        }
        printf("\n");
        Lista = Lista->next;
    }
    printf("\nFim da lista.\n");
    return 1;
}

node *ordenarRol(node *conjunto){
    node *lerConjunto, *prev, *next, *rol, *addElemento, *last;
    int menor, chave;

    rol = (node *)malloc(sizeof(node));
    rol->next = NULL;

    last = rol;

    while (conjunto != NULL){
        lerConjunto = conjunto;
        menor = conjunto->info;
        while(lerConjunto != NULL){
            if (lerConjunto->info <= menor){
                menor = lerConjunto->info;
                prev = lerConjunto->prev;
                next = lerConjunto->next;
            }
            lerConjunto = lerConjunto->next;
        }

        lerConjunto = rol->next;
        chave = 1;
        while(lerConjunto != NULL){
            if (lerConjunto->info == menor) chave = 0;
            lerConjunto = lerConjunto->next;
        }
        //if (chave == 0) continue;
		
		if (chave == 1){
			addElemento = (node *)malloc(sizeof(node));
			addElemento->info = menor;
			addElemento->next = NULL;
			addElemento->prev = NULL;

			addElemento->prev = last;
			last->next = addElemento;
			last = addElemento;

		}	    
		//Deletar elemento de 'conjunto'
	    if(prev == NULL && next == NULL){
	        free(conjunto);
	        conjunto = NULL;
	    }
	    else if(next == NULL){
	        prev->next = NULL;
	    }
	    else if(prev == NULL){
	        next->prev = NULL;
	        conjunto = next;
	    }
	    else{
	        prev->next = next;
	        next->prev = prev;
	    }
    }


    rol = rol->next;
    rol->prev = NULL;
    return rol;
}

int uniao(lista *Lista){
    node *nUniao = NULL, *lerUniao, *anterior = NULL, *conjunto, *lerConjunto;
    lista *lerLista = Lista;

    if (Lista == NULL){
        printf("\nLista Vazia.\n");
        return 0;
    }

    int addInfo;

    while(lerLista != NULL){
	if (lerLista->elemento == NULL){
	    lerLista = lerLista->next;
	    continue;
	}
        lerConjunto = lerLista->elemento;
        while(lerConjunto != NULL){
            //Percorrer o conjunto e testar elemento por elemento se a nUniao ja possui o elemento;
	    if (nUniao == NULL){
		nUniao = (node *)malloc(sizeof(node));
		nUniao->next = NULL;
		nUniao->prev = NULL;
		nUniao->info = lerLista->elemento->info;
	    }
	    else{
            	addInfo = 1;
            	lerUniao = nUniao;
            	while (lerUniao != NULL){
	            if (lerUniao->info == lerConjunto->info){
                    	addInfo = 0;
                    	break;
                    }
                anterior = lerUniao;
                lerUniao = lerUniao->next;
            	}
            	if (addInfo == 1){
                    node *addElemento;
                    addElemento = (node *)malloc(sizeof(node));

                    addElemento->info = lerConjunto->info;
                    addElemento->next = NULL;
                    addElemento->prev = anterior;

                    anterior->next = addElemento;
                }


                lerConjunto = lerConjunto->next;
	    }
        }
        lerLista = lerLista->next;
    }
    printf("\nUniao:");
    if (nUniao == NULL) printf(" - NULL");

    else{
    	nUniao = ordenarRol(nUniao);
    	lerUniao = nUniao;
    	while (lerUniao != NULL){
    	    printf(" %d", lerUniao->info);
    	    lerUniao = lerUniao->next;
    	}
    }
    return 1;
}

int interseccao(lista *Lista){
    node *conjunto, *conjuntoTeste, *interseccao, *last, *addElemento;
    int chave;
    lista *lerLista;

    if (Lista == NULL){
        printf("\nLista Vazia.\n");
        return 0;
    }

    interseccao = (node *)malloc(sizeof(node));
    last = interseccao;

    conjuntoTeste = Lista->elemento;    //Conjunto teste recebe o primeiro conjunto;
    while (conjuntoTeste != NULL){
        lerLista = Lista;
        lerLista = lerLista->next;    //Avançar para proximo conjunto;
        while (lerLista != NULL){
            conjunto = lerLista->elemento;
            chave = 0;
            while (conjunto != NULL){
                if (conjunto->info == conjuntoTeste->info){
                    chave = 1;
                    break;
                }
                conjunto = conjunto->next;
            }
            if (chave == 0) break;
            lerLista = lerLista->next;
        }
        if (chave == 1){
            addElemento = (node *)malloc(sizeof(node));
            addElemento->info = conjuntoTeste->info;
            addElemento->next = NULL;
            addElemento->prev = last;

            last->next = addElemento;
            last = addElemento;
        }
        conjuntoTeste = conjuntoTeste->next;
    }
    if (last == interseccao){
        printf("\nNao ha interseccao dos elementos.\n");
        return 0;
    }
    interseccao = interseccao->next;
    interseccao->prev = NULL;
    interseccao = ordenarRol(interseccao);
    printf("\nInterseccao:");
    while (interseccao != NULL){
        printf(" %d", interseccao->info);
        interseccao = interseccao->next;
    }
    return 1;
}

int diferenca(lista *Lista){
    node *conjunto, *conjuntoTeste, *diferenca, *last, *addElemento;
    int chave;
    lista *lerLista;

    if (Lista == NULL){
        printf("\nLista Vazia.\n");
        return 0;
    }

    diferenca = (node *)malloc(sizeof(node));
    last = diferenca;

    conjuntoTeste = Lista->elemento;    //Conjuntoteste recebe o primeiro conjunto;

    while (conjuntoTeste != NULL){
        //Avançar para proximo conjunto;
        lerLista = Lista->next;
        chave = 0;
        while (lerLista != NULL){
            conjunto = lerLista->elemento;

            while (conjunto != NULL){
                if (conjunto->info == conjuntoTeste->info){
                    chave = 1;
                    break;
                    conjuntoTeste = conjuntoTeste->next;
                    continue;
                }
                conjunto = conjunto->next;
            }
            lerLista = lerLista->next;
        }
        if (chave == 0){
            addElemento = (node *)malloc(sizeof(node));
            addElemento->info = conjuntoTeste->info;
            addElemento->next = NULL;
            addElemento->prev = last;

            last->next = addElemento;
            last = addElemento;
        }
        conjuntoTeste = conjuntoTeste->next;
    }
    if (last == diferenca){
        printf("\nNao ha diferenca dos elementos.\n");
        return 0;
    }
    diferenca = diferenca->next;
    diferenca->prev = NULL;
    diferenca = ordenarRol(diferenca);
    printf("\nDiferenca:");
    while (diferenca != NULL){
        printf(" %d", diferenca->info);
        diferenca = diferenca->next;
    }
    return 1;
}

lista *delConjunto(lista *Lista){
    int deletar, contador = 1;
    lista *lerLista = Lista, *listaDelete, *anterior = NULL;

    printf("-----------------------------\n"
           "|      Deletar Conjunto     |\n"
           "-----------------------------\n\n"
           "Digite o numero correspondente ao conjunto a ser deletado\n"
           "Deletar: ");
    scanf(" %d", &deletar);
    getchar();

    while(lerLista != NULL){
        if (contador == deletar){
            listaDelete = lerLista;

            lerLista = lerLista->next;
            if (lerLista == NULL && anterior == NULL) Lista = NULL;

            else if(lerLista == NULL) anterior->next = lerLista;

            else if(anterior == NULL){
                lerLista->prev = anterior;
                Lista = lerLista;
            }
            else {
                anterior->next = lerLista;
                lerLista->prev = anterior;
            }

            free(listaDelete);
            printf("\n\nConjunto %d excluido com sucesso.\n", deletar);
            return Lista;
        }
        anterior = lerLista;
        contador++;
        lerLista = lerLista->next;
    }
    printf("\n\nERRO: Conjunto nao existe.\n");
    return Lista;
}

lista *modificaConjunto(lista *Lista){
    int menu, conjunto, cont;
    lista *lerLista;

        printf("\n****************************\n"
               "*     Modificar Conjunto   *\n"
               "****************************\n\n"
               "* 1- Adicionar elemento    *\n"
               "* 2- Excluir elemento      *\n\n"
               "* Escolha: ");
        scanf(" %d", &menu);
        getchar();

        switch(menu){
        case 1:
            if (listar(Lista) == 0){
                printf("\nAdicione um conjunto primeiro.\n");
                return Lista;
            }
            printf("\nDigite o numero do conjunto a ser modificado: ");
            scanf(" %d", &conjunto);
            getchar();

            cont = 1;
            lerLista = Lista;
            while(lerLista->next != NULL){
                if(cont == conjunto){
                    break;
                }
                lerLista = lerLista->next;
                cont++;
            }
            if (conjunto > cont || conjunto < cont){
                printf("\nERRO: conjunto nao existe.\n");
                //printf("\nPressione qualquer tecla para continuar.");
                //getchar();
                break;
            }
            else if (conjunto == cont){
                lerLista->elemento = addElemento(lerLista->elemento);
                listar(Lista);
            }
        break;
        case 2:
            if (listar(Lista) == 0){
                printf("\nAdicione um conjunto primeiro.\n");
                return Lista;
            }
            printf("\nDigite o numero do conjunto a ser modificado: ");
            scanf(" %d", &conjunto);
            getchar();

            cont = 1;
            lerLista = Lista;
            while(lerLista->next != NULL){
                if(cont == conjunto){
                    break;
                }
                lerLista = lerLista->next;
                cont++;
            }
            if (conjunto > cont || conjunto < cont){
                printf("\nERRO: conjunto nao existe.\n");
                //printf("\nPressione qualquer tecla para continuar.");
                //getchar();
                break;
            }
            else if (conjunto == cont){
                lerLista->elemento = delElemento(lerLista->elemento);
            }

            break;
        default:
            return Lista;
        }
    return Lista;
}

node *addElemento(node *Conjunto){
    int num;
    node *lerConjunto = Conjunto, *addCon, *last;

    printf("\nDigite o valor a ser adicionado: ");
    scanf(" %d", &num);
    getchar();

    while(lerConjunto != NULL){
        if (lerConjunto->info == num){
            printf("\nERRO: Valor ja existe no conjunto.\n");
            printf("\nPressione qualquer tecla para continuar.");
            getchar();
            return Conjunto;
        }
        lerConjunto = lerConjunto->next;
    }

    if(Conjunto == NULL){
        Conjunto = (node *)malloc(sizeof(node));
        Conjunto->info = num;
        Conjunto->next = NULL;
        Conjunto->prev = NULL;
        last = Conjunto;
    }
    else{
        last = Conjunto;
        addCon = (node *)malloc(sizeof(node));
        addCon->info = num;
        addCon->next = last;
        addCon->prev = NULL;
        last->prev = addCon;
        Conjunto = addCon;
    }
    Conjunto = ordenarRol (Conjunto);

    printf("\nValor %d adicionado com sucesso.\n", num);
    printf("\nPressione qualquer tecla para continuar.");
    getchar();
    return Conjunto;
}

node *delElemento(node *Conjunto){
    int pos, num, cont;
    node *delElem, *lerConjunto, *prev;

    printf("\n\nDigite a posicao do elemento que deseja excluir: ");
    scanf(" %d", &pos);
    getchar();

    cont = 1;
    lerConjunto = Conjunto;
    while(lerConjunto != NULL){
        if (pos == cont){
            delElem = lerConjunto;
            if (delElem->next == NULL && delElem->prev == NULL){
                Conjunto = NULL;
            }
            else if(delElem->next == NULL){
                delElem->prev->next = NULL;
            }
            else if(delElem->prev == NULL){
                delElem->next->prev = NULL;
                Conjunto = Conjunto->next;
            }
            else {
                delElem->prev->next = delElem->next;
                delElem->next->prev = delElem->prev;
            }
            free(delElem);
            printf("\nElemento excluido com sucesso.\n");
            return Conjunto;
        }
        lerConjunto = lerConjunto->next;
        cont++;
    }
    printf("\nERRO: Posicao nao existe.");
    return Conjunto;
}
