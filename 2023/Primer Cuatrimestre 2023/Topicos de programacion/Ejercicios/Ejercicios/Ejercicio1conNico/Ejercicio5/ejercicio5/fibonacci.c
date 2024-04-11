#include "fibonacci.h"

int fibonacci(n)
{
   int a = 0;
    int b = 1;
    int c = a + b;

    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }

    if (c == n) {
        printf("El número %d es parte de la secuencia de Fibonacci.\n", n);
        return 1;
    } else {
        printf("El número %d NO es parte de la secuencia de Fibonacci.\n", n);
        return 0;
    }

}
