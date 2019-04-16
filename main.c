#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
    transformedDNA = Push(transformedDNA, 3);
    transformedDNA = Push(transformedDNA, 5);

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
