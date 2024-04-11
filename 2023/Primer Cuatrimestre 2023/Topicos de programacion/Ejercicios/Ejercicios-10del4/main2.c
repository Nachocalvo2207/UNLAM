
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef struct {
        int dia;
        int mes;
        int anio;
}tfecha;


void cargar_fecha(tfecha* fecha){
    scanf("%d",&fecha->dia);
    scanf("%d",&fecha->mes);
    scanf("%d",&fecha->anio);

}

int fecha_correcta(tfecha* fecha){
    if(fecha->anio >= 1970)
        if(fecha->mes >=1 && fecha->mes <= 12)
            if(fecha->dia >=1 && cant_dia_mes(fecha->anio,fecha ->mes))
                return OK;

}

int main()
{
    tfecha fecha1;


    return 0;
}
