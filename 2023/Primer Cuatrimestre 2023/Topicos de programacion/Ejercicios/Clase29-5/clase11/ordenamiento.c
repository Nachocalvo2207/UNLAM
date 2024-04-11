#include "ordenamientos.h"

void buuble_sort (void *vec, size_t mem, size_t tamanio, int (*cmp) (void*, void*) )
{
    int (*cmp)(void*, void*)
    {
        int i,j;

        for (i=0; i< nmem; i++)
        {
            for(j=0; j<nmem-1;j++)
            {
                if(cmp(vec+j*tamanio, vec+(j+1)*tamanio))
                    intercambio (vec+j*tamanio, vec + (j+1)*tamanio, tamanio);

            }
        }
    }
}

void intercambio (void *a, void *b, size_t tamanio)
{
    char *aux = malloc (tamanio);

     /*aux = a;
    a = b;
    b = aux; */

    memcpy(aux, a, tamanio);
    memcpy(a, b, tamanio);
    memcpy(b, aux, tamanio);
    free(aux);



}
