#include <stdio.h>
#include <stdlib.h>

typedef struct typestr{
    char elem;
    struct typestr *prox;
}Typestr;


//1
Typestr* cria_str_vazia(int tamanho) {
    Typestr *str = calloc(tamanho, sizeof(Typestr));
    str->elem = '\0';
    str->prox = NULL;

    return str;
}


//2
void reinicia_str(Typestr **str){
    *str = NULL;
}



//3
void imprime_str(Typestr *str){
    Typestr *aux = str;
    while(aux != NULL){
       printf("%c", aux->elem);
       aux = aux->prox;
    }
}


int tam_str(Typestr *str){
    Typestr *aux = str;
    int count = 0;
    while(aux != NULL){
        count++;
        aux = aux->prox;
    }
    return count;
}


int main() {
    Typestr *str = cria_str_vazia(10);

    Typestr *aux = str;
    for(int i = 0; i < 10; i++){
        aux->prox = (aux+1);
        aux = aux->prox;
    }

    aux = str;
    aux->elem = 't';
    aux = aux->prox;
    aux->elem = 'e';
    aux = aux->prox;
    aux->elem = 's';
    aux = aux->prox;
    aux->elem = 't';
    aux = aux->prox;
    aux->elem = 'a';
    aux = aux->prox;
    aux->elem = 'n';
    aux = aux->prox;
    aux->elem = 'd';
    aux = aux->prox;
    aux->elem = 'o';
    aux->prox = NULL;

    printf("String: ");
    imprime_str(str);
    printf("\n");

    int x = tam_str(str);
    printf("Tamanho da string: %d\n",x);

    reinicia_str(&str);

    printf("String apos reinciar: ");
    imprime_str(str);
    printf("\n");

    return 0;
}