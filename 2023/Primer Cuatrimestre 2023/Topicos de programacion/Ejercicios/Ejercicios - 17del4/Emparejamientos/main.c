#include <stdio.h>
#include <stdlib.h>
#include <ordenamiento.h>

int main()
{
    int vector[TAM] = [9,5,1,3,8];

    muestra_vector (vector);
    ordena_burbujeo (vector);
    ordena_seleccion (vector);
    return 0;
}
