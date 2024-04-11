#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OK 2
#defiNE TAM 100
#define TAM2 61
#define TAM_FECHA 8



int binario_a_texto(FILE*pbin,FILE*ptxt);
int texto_variable_a_binario(FILE*pbin,FILE*ptxt);

#endif // ARCHIVOS_H_INCLUDED
