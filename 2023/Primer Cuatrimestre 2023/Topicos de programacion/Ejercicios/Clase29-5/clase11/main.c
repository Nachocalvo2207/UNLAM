#include <stdio.h>
#include <stdlib.h>

#include "tipos.h"
#include "ordenamientos.h"
#include "funciones.h"


#define TAM_VEC 5

int main()
{
    t_alumno alumnos[] =
    {
    {45005883, "Juan Perez",{17,05,1998}},
    {41163000, "Ignacio Calvo",{17,05,1998}}
    };

    int cant_elementos = sizeof(alumnos) / sizeof (t_alumno);

    buuble_sort (alumnos, cant_elementos, sizeof(t_alumno), compara_alumnos);

    //show(alumnos, muestra_alumnos);


    return 0;
}
