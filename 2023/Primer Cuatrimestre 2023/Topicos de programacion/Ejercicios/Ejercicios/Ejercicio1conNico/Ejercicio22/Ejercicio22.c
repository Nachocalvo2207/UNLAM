#include <stdio.h>
#include "Ejercicio22.h"

/*void nuevoVector(int*v,int pos,int num)
{
    *(v+pos-1) = num;


}*/

void mostrarVector(int *v,int *t)
{
    int i;
    for(i=0; i<*t; i++)
    {
        printf("\nPosicion %d: %d", i+1, v[i]);
    }


}


/*void agregarAlVector (int *v, int TAM, int num)
{
    int i=0;
    int aux;

    while (i<TAM)
    {
        if(num >= *(v+i))
        {
            aux = *(v+i);
            *(v+i) = num;
            num = aux;

        }
    i++;
    }
}*/

void agregarAlVector(int *vec,int num,int *t)
{
    int i,aux,aux2,bandera=0;
    for(i=0; i<*t ; i++)
    {

        /*
        if(bandera == 1)
        {
            aux2 = *vec;
            *vec = aux;
            aux = aux2;
        }
        if(num <= *vec && bandera != 1)
        {
            aux = *vec;
            *vec = num;
            *t+=1;
            bandera =1;
        */
        }
        vec++;
        *t--;
    }
}


