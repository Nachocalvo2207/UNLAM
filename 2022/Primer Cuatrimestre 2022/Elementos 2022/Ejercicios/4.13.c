/*Un fabricante de repuestos para tractores ha descubierto que ciertos artículos identificados por los
números de catálogo 12121 al 18081; 30012 al 45565 y 67000 al 68000 son defectuosos. Se desea
confeccionar un programa al que informándole el número de catálogo indique si el artículo es o no
defectuoso. Los artículos del catálogo van desde el 1200 al 90000. Si se ingresa otro número informar
“FUERA DE CATALOGO*/

#include<stdio.h>

int main (){
    int catalogo;

    printf ("Ingrese el numero de catalogo: ");
    scanf ("%d",&catalogo);

    if(catalogo < 1200 || catalogo > 90000){
        printf ("FUERA DE CATALOGO");
    }else
        if ((catalogo > 12121 && catalogo < 18081) || (catalogo >30012 && catalogo < 45565) || (catalogo > 67000 && catalogo < 68000)){
            printf ("El catalogo es DEFECTUOSO.");
        }else {
            printf ("El catalogo se encuentra OK");
        }
return 0;
}
