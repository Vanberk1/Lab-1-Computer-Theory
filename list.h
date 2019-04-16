#include <stdio.h>
#include <stdlib.h>

/*
    List node data struct;
*/
typedef struct node {
    int data;
    struct node* next;
} Node;

typedef Node* List; // List is a type value that has a group of nodes


/*
    AddNode function recives an integer and creates a node
    with its data as x parameter and the next pointer to null.
    Returns the complete node with List type value.
*/
List AddNode(int x)
{
    List aux;
    aux = (Node*)malloc(sizeof(Node));

    aux->data = x;
    aux->next = NULL;

    return aux;
}
// e.g. List list = AddNode(0) --> This line of code inialize a list with a node that has a 0 in its data.

/*
    Push function recives a List and an integer, then creates a node
    and puts it at the end of the List.
    Returns the same List modified.
*/
List Push(List list, int x) {
    List aux, nNode;
    nNode = AddNode(x);
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
/* e.g. List list = NULL;
        list = Push(list, 0) --> These lines of code add a node to the end od the list with a 0 in its data.
*/
/*
    ListLength
*/
int ListLength(List list) {
    int count = 0;
    List aux = list;

    while(aux != NULL) {
        count++;
        aux = aux->next;
    }

    return count;
}
// e.g. int listLenth = ListLength(list) --> This line of code stores in a variable the number of nodes that the list has.

/*
    ValueAt function recives a List and an integer what is it a position in the List.
    Returns the value of the data field in the correspondent node to the index parameter.
*/
int ValueAt(List list, int index) {
    List aux = list;
    int i = 0;

    while(i < index) {
        aux = aux->next;
        i++;
    }

    return aux->data;
}
// e.g. int number = ValueAt(list, 2) --> This line of code stores in a variable de data of the node at the third position of the list.






