/*4.15. Un negocio de artículos de computación vende DVDs según la siguiente escala de precios:
• sueltos, entre 1 y 9 a $15 c/u.
• la caja de 10 cuesta $120.
• la caja de 50 cuesta $500.

Si la compra excede las 100 unidades se efectúa un descuento del 10%.
NOTA: se aceptan compras entre 1 y 500 DVDs.
Se pide que se ingrese una cantidad de DVDs que se quiere comprar y calcule e informe el importe a pagar.
*/

#include<stdio.h>
#define pi 3.1416

/*#define dvdSuelto 15
#define caja10 120
#define caja50 500*/


int main (){
    int dvd,dvdSuelto,caja10,caja50,resto50,resto10,total;

    dvdSuelto = 15;
    caja10 = 120;
    caja50 = 500;
    total = 0;

    printf ("Ingrese la cantidad de DVD's que desea comprar: ");
    scanf ("%d",&dvd);

    if(dvd<1 || dvd > 500){
        printf ("No se puede comprar esta cantidad de DVD's");

    }else
        if(dvd > 1 && dvd < 500){
            caja50 = caja50 * (dvd/50);
            resto50 = dvd%50;
            caja10 = caja10 * (resto50/10);
            resto10 = dvd % 10;
            dvdSuelto = dvdSuelto * resto10;
            total = caja50 + caja10 + dvdSuelto;

            printf ("El total de Dvd's es: %d",total);

        }

return 0;
}

