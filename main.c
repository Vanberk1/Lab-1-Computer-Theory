#include "functions.h"

int main()
{
	char flag;

	do{
        system("clear||cls");
		List dnaList = GenerateEquivalentList();

   		int initialState = 0;
   		int finalState = 4;

   		HumanOrMutant(dnaList, initialState, finalState);

  		printf("Desea probar otro archivo S/N?\n");
  		scanf(" %c", &flag);

    }while(flag == 'S' || flag == 's');

	return 0;
}
