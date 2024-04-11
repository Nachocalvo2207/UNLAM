#include <stdio.h>
#include "ejercicio8.h"

int sumaDivisores(int n)
{
    int i;
    int suma = 0;

    for (i = 1; i<n; i++)
    {
        if (n%i == 0)
            suma += i;
    }

    if(suma == n){
        printf ("Su clasificacion es: Perfecta \n");
        return 1;
    }

    if(suma < n){
        printf ("Su clasificacion es: Deficiente \n");
        return 0;
    }

    if(suma>n)
    {
        printf ("Su clasificacion es: Abundante \n");
        return 0;
    }
}
