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

void HumanOrMutant(List list,int state1,int state2,int state3){

    int length = 0;
    int value = 0;
    int i = 0;
    int transitionMatrix [11][4] = {{5,0,1,10},
                                     {5,0,3,0},
                                     {8,4,2,2},
                                     {8,4,3,3},
                                     {8,4,3,3},
                                     {7,0,1,10},
                                     {6,6,6,6},
                                     {6,0,1,1},
                                     {9,4,8,8},
                                     {6,4,8,8},
                                     {5,0,0,2}};


    length = ListLength(list);
    
    for(i=0;i<length;i++){
        value = ValueAt(list,i);

        if(i == 0){
            state2 = transitionMatrix [state1][value];
        }
        else{
            state2 = transitionMatrix [state2][value];
        }
    }

    if(state2 == state3){
        
        printf("El individuo es: <Mutante>\n");
    }
    else{
        printf("El individuo es: <Humano>\n");
    }
}