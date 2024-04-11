#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED
#include "tipos.h"

typedef struct {
    int dia, mes, anio;
}t_fecha;

typedef struct {
    long dni;
    char apyn[30];
    t_fecha fecha_nac;
}t_alumno;



#endif // TIPOS_H_INCLUDED
