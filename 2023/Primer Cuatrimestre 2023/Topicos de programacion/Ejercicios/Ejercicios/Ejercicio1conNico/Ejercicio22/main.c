#include <stdio.h>
#include <stdlib.h>
#include "Ejercicio22.h"

int main()
{
    int TAM = 5;
    int v[] = {1,2,3,4,5};
    int  num;

    printf ("Ingrese el numero que desea agregar: \n");
    scanf ("%d",&num);

    //printf ("Ingrese la posicion: \n");
    //scanf ("%d",&pos);

    //nuevoVector(&v,pos,num);
    agregarAlVector (v, num, &TAM);
    mostrarVector(v,&TAM);

    return 0;
}
