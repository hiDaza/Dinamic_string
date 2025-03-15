#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



typedef struct StringList{
    struct StringList *first;
    struct StringList *last;
}StringList;



typedef struct Node{
    char elem;
    struct Node *prox;
}Node;


///ex 1
void inicializeList(StringList *strList){
    strList->first = NULL;
    strList->last = NULL;
}

///ex5
void inputList(StringList *strList, char elem){
    Node *node = (Node*) malloc(sizeof(Node));
    node->elem = elem;
    node->prox = NULL;

    if(strList->first == NULL){
        strList->first = node;
        strList->last = node;
        return;
    }
    Node *aux = strList->first;
    Node *prev = NULL;


    while(aux != NULL){
        prev = aux;
        aux = aux->prox;
    }
    prev->prox = node;
}

///ex 3
void printList(StringList *strList){
    if(strList->first == NULL){
        printf("Lista vazia \n");
        return;
    }
    Node *aux = strList->first;
    while(aux != NULL){
        printf("%c",aux->elem);
        aux = aux->prox;
    }

}


///ex 2
void resetList(StringList *strList){
    Node *aux = strList->first;
    while(aux != NULL){
        memset(&aux->elem, 0, sizeof(Node));
        Node *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    strList->first = NULL;
    strList->last = NULL;
}


///ex 4
int sizeStrList(StringList *strList){
    Node *aux = strList->first;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}


///ex 6
/// /// use function input in other function needs a pointer pointer ** // //
void copyList(StringList *strList, StringList **strList2){
    if(strList == NULL){
        printf("NULL LIST");
        return;
    }
    Node *aux = strList->first;
    while(aux != NULL){
        inputList(strList2,aux->elem);
        aux = aux->prox;
    }
}


///ex 7
StringList concatList(StringList *strList, StringList *strList2){
        StringList strList3;
        inicializeList(&strList3);

        copyList(strList,&strList3);
        copyList(strList2,&strList3);

        return strList3;
}



///ex 8
void removeIn(StringList *strList, int qtd, int start){
    Node *aux = strList->first;
    Node *prev = NULL;
    int cont = 0;
    int temp = 0;
    if(start == 0){

    }
    while(aux != NULL){
            if(start == 0){
                Node *delet = aux;
                aux = aux->prox;
                free(delet);
                temp++;
                if(temp == qtd){
                    strList->first = aux;
                    return;
                }
            }
        prev = aux;
        aux = aux->prox;
        cont++;

        if(cont == start){
                while(aux != NULL){
                Node *delet = aux;
                aux = aux->prox;
                free(delet);
                temp++;

                if(temp == qtd){
                    prev->prox  = aux;
                    return;
                }
            }
        }
    }
}


///ex 9
void insertAnyPosition(StringList *strList, char *elem, int pos){
        Node *aux = strList->first;
        Node *prev = NULL;
        int cont = 0;
        int size = strlen(elem);
        StringList strTemp;
        inicializeList(&strTemp);
        for(int i = 0; i < size; i++){
            inputList(&strTemp,elem[i]);
        }

        while(aux != NULL){
            aux = aux->prox;
            cont++;
        }
        if(pos == cont){
            concatList(&strTemp,&strList);
            return;
        }
        //reset
        aux = strList->first;
        cont = 0;
        Node *temp = strTemp.first;

        while(aux != NULL){
                if(pos == 0){
                    strList->first = temp;
                    while(temp->prox != NULL){
                        temp = temp->prox;
                    }
                    temp->prox = aux;
                    return;
            }
            prev = aux;
            aux = aux->prox;
            cont++;
            if(cont == pos){
                prev->prox = temp;
                while(temp->prox != NULL){
                    temp = temp->prox;
                }

                temp->prox = aux;
                return;
        }
    }
}


///ex 10
bool isLess(StringList *strList, StringList *strList2){
    Node *aux = strList->first;
    Node *aux2 = strList2->first;
    int cont = 0, cont2 = 0;
    while(aux != NULL){
        aux = aux->prox;
        cont++;
    }

    while(aux2 != NULL){
        aux2 = aux2->prox;
        cont2++;
    }

    if(cont < cont2){
        return true;
    }else{
    return false;
    }

}


///ex 11
bool isEqual(StringList *strList, StringList *strList2){
    Node *aux = strList->first;
    Node *aux2 = strList2->first;

    while(aux != NULL && aux2 != NULL){
        if(aux->elem == aux2->elem){
            aux = aux->prox;
            aux2 = aux2->prox;
        }else{
        return false;
        }
    }
    if(aux != NULL || aux2 != NULL){
        return false;
    }
    return true;
}


///ex 12
int stringPosition(StringList *strList, char *elem){
    int sizeStr = strlen(elem);
    int cont = 0, pos = 0;
    Node *aux = strList->first;

    while(aux != NULL){
        if(aux->elem == elem[0]){
            cont = 0;
            for(int i = 0; i < sizeStr; i++){
                if(aux->elem == elem[i]){
                    cont++;
                    aux = aux->prox;

                }
            }

        }else{
        aux = aux->prox;
        pos++;
        }
        if(cont == sizeStr){
            return pos+1;
        }
    }
}







