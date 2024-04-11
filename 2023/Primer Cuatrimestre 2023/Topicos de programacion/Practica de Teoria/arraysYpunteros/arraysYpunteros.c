#include "arraysYpunteros.h"

char *strcpy1(char *dest, const char *orig)
{
    char *aux = dest;

    while (*orig)
    {
        *dest = *orig;
        dest++;
        orig++;
    }
    *dest = '\0';

    return aux;
}
