#include "functions.h"

int main()
{
    List dnaList = GenerateEquivalentList();

    List aux = dnaList;
    while(aux->next != NULL) {
        aux = aux->next;
        printf("%d", aux->data);
    }
    aux = NULL;
}
