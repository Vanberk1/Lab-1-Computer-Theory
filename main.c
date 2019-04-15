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

void Push(List list, int x) {
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
    }
}

FILE* SelectFile() {
    char* fileName = (char*) malloc(sizeof(char));
    printf("Ingrese nombre de archivo: ");
    scanf("%s", fileName);

    FILE* file;
    file = fopen(fileName, "r");
    if(file == NULL) {
        printf("El archivo no existe. \n");
    }

    return file;
}

int main()
{
    List transformedDNA = NULL;
    Push(transformedDNA, 3);
    Push(transformedDNA, 5);

    List aux = transformedDNA;
    while(aux != NULL) {
        printf("%d \n", aux->nBaseEqui);
        aux = aux->next;
    }

    FILE* dnaFile;

    do {
        dnaFile = SelectFile();
    } while(dnaFile == NULL);

    char nBase;

    while((nBase = fgetc(dnaFile)) != EOF)
		printf("%c",nBase);




    fclose(dnaFile);
}
