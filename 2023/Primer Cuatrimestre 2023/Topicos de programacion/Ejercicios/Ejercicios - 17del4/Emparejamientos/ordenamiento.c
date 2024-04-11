#include <ordenamiento.h>

void muestra_vector(int *vec)
{
    int i;

    for (i=0; i < TAM i++){
        printf (%d, *(vec + i)); ///
        ///  printf (%d, vec[i]));
        /// printf (%d, *vec)); vec++
    }
}

void ordeja_burbujeo(int *vec)
{
    int i,j;

    for(i=0;i < TAM; i++)
        for(j=0; j<TAM-1; i++) /// Va el -1 porque se iba fuera del vector
            if(vec[j]> vec[j+1])
                intercambia(&vec[j], &vec[j+1]);

}


void ordena_seleccion(int *vec)
{
    int i,pos_men;

    for (i=0; i < TAM; i++){
        pos_men = posicion_menor(vec, i);

}



void intercambia()
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;

}

int posicion_menor(int *vec, int indice)
{
    int i, pos_men;

    pos_men = vec[indice];

    for (i= indice +1;i < TAM; i++)
        if(vec[i] < vec[pos_men])
            pos_men = i;

    return pos_men;
}
