#ifndef TADSTRING_H_INCLUDED
#define TADSTRING_H_INCLUDED
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


void inicializeList(StringList *strList);


void inputList(StringList *strList, char elem);


void resetList(StringList *strList);


int sizeStrList(StringList *strList);


void copyList(StringList *strList, StringList *strList2);


StringList concatList(StringList *strList, StringList *strList2);


void removeIn(StringList *strList, int qtd, int start);


void insertAnyPosition(StringList *strList, char *elem, int pos);


bool isLess(StringList *strList, StringList *strList2);


bool isEqual(StringList *strList, StringList *strList2);


int stringPosition(StringList *strList, char *elem);

#endif // TADSTRING_H_INCLUDED
