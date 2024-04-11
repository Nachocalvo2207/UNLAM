#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "tipos.h"
#include "funciones.h"

#define ARCH_ALUMNOS "Archivos/alumnos.bin"

int main()
{
    int cant_registros;
    t_indice *indice;

    cant_registros = crea_archivo_alumnos(ARCH_ALUMNOS);
    indice = generar_indice(ARCH_ALUMNOS, cant_registros, compara_alumnos_idx);

    const char opciones [][LENGTH_MENU] = {"MIBAES",
                                        "Mostrar archivo Alumnos",
                                        "Mostrar Alumnos (ordenado)",
                                        "Buscar Alumno",
                                        "Alta Alumno",
                                        "Eliminar Alumno",
                                        "Salir"
                                        };

    char op;

    do{
        op=menu(opciones, "Menu Principal");
        switch (op)
        {
            case 'M':
                show(ARCH_ALUMNOS, muestra_alumnos);
                system("PAUSE");
                break;

            case 'B':
                system("PAUSE");
                break;

            case 'A':
                system("PAUSE");
                break;

            case 'E':
                system("PAUSE");
                break;
        }
    }while(op!='S');

    return 0;
}
