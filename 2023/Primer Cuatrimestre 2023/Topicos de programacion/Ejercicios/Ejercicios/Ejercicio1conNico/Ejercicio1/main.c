#include <stdio.h>
#include <stdlib.h>
#include "ejercicio1.h"


int main()
{
    int total,n;

    printf ("Elija un factorial: ");
    scanf("%d",&n);

    total = factorial(n);

    return 0;
}
