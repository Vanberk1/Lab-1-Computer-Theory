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

List GenerateEquivalentList() {
    List transformedDNA = NULL;
    FILE* dnaFile;

    do {
        dnaFile = SelectFile();
    } while(dnaFile == NULL);

    char nBase;
    int nBaseEqui;
    int validCharacter;
    while((nBase = fgetc(dnaFile)) != EOF) {
        validCharacter = 0;
        /*
            Nitrogen Base Equivalence:

            a = 0
            c = 1
            g = 2
            t = 3
        */
        switch(nBase) {
        case 'a':
        case 'A':
            nBaseEqui = 0;
            validCharacter = 1;
            break;
        case 'c':
        case 'C':
            nBaseEqui = 1;
            validCharacter = 1;
            break;
        case 'g':
        case 'G':
            nBaseEqui = 2;
            validCharacter = 1;
            break;
        case 't':
        case 'T':
            nBaseEqui = 3;
            validCharacter = 1;
            break;
        }
        if(validCharacter)
            transformedDNA = Push(transformedDNA, nBaseEqui);
    }
    fclose(dnaFile);

    return transformedDNA;
}
