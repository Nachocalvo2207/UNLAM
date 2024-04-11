#include "ejercicio1.h"


int factorial(int n)
{
    int i,total;




    int factorial = 1;

    for(i = 1; i <= n; i++) {
        factorial *= i;
    }

    printf("El total es: %d",factorial);

    return factorial;
}

