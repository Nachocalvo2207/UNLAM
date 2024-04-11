#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraysYpunteros.h"

int main()
{
    char destino [20],
         original[] = {"Hola"},
         *aux;

    aux = strcpy1(destino, original);

    printf("La cadena original es: \"%s\" \n",original);
    printf("La cadena destino es: \"%s\" \n", destino);

    return 0;
}
