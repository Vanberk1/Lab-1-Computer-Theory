#include "functions.h"

int main()
{
	char flag;	

	do{
		List dnaList = GenerateEquivalentList();
   
   		int initialState = 0;
   		int actualState = 0;
   		int finalState = 4;

   		HumanOrMutant(dnaList,initialState,actualState,finalState);

  		printf("Desea probar otro archivo S/N?\n");
  		scanf(" %c", &flag);

    }while(flag == 'S' || flag == 's');

	return 0;
}

    /*List aux = dnaList;
    while(aux->next != NULL) {
        aux = aux->next;
        printf("%d", aux->data);
    }

    printf("\n");*/

    //aux = NULL;
