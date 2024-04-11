#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main()
{
    int n;
    printf("Elija el numero que quiere Fibonacciear: ");
    scanf("%d",&n);
    fibonacci(n);
    return 0;
}
