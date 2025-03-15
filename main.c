#include "TADString.h"

int main()
{
    StringList strList, strList2, strList3;

    inicializeList(&strList2);
    char elem[] = "char";
    int sizeChar = strlen(elem);
    for(int i = 0; i < sizeChar; i++){
        inputList(&strList2,elem[i]);
    }

    printList(&strList2);
    printf("\n");
    //resetList(&strList);
    //printList(&strList);
    //sprintf("\n");

    char elem2[] = "SUPERPALAVRA";
    int sizeWord = strlen(elem2);
    inicializeList(&strList);
    for(int i = 0; i < sizeWord; i++){
        inputList(&strList,elem2[i]);
    }
    printList(&strList);
    printf("\n");

    int sizeL = sizeStrList(&strList);
    printf("size of word in list 1: %d",sizeL);
    printf("\n");


    copyList(&strList,&strList2);
    printf("List 2 before receiver itens of list 1: \n");
    printList(&strList2);


    inicializeList(&strList3);

    strList3 = concatList(&strList,&strList2);
    printf("\n");
    printf("Concatenated lists with result in list 3: \n");
    printList(&strList3);

    printf("\n");
    removeIn(&strList,4,4);
    printList(&strList);

    printf("\n");
    char word[] = "Int";
    insertAnyPosition(&strList,word,3);
    printf("Before Insertion: \n");
    printList(&strList);


    printf("\n");
    if(isLess(&strList,&strList2)){
        printf("List 1 is less than List 2\n");
    }else{
        printf("List 1 is not less than List 2\n");
    }

    printf("\n");
    if(isEqual(&strList,&strList2)){
        printf("Lists is equals\n");
    }else{
        printf("Lists is not equals\n");
    }


    printf("\n");
    char auxStr[] = "UP";
    int pos  = stringPosition(&strList,auxStr);
    printf("Position where the substring appears, considering that the position starts at 1: %d\n",pos);

}
