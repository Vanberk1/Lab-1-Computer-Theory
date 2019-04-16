#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int nBaseEqui;
    struct node* next;
} Node;
typedef Node* List;

List addNode(int x)
{
    List aux;
    aux = (Node*)malloc(sizeof(Node));

    aux->nBaseEqui = x;
    aux->next = NULL;

    return aux;
}

List Push(List list, int x) {
    List aux, nNode;
    nNode = addNode(x);
    if(list == NULL) {
        list = nNode;
    }
    else {
        aux = list;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = nNode;
        aux = NULL;
    }
    nNode = NULL;
    return list;
}
