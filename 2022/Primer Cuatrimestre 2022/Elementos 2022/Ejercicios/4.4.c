#include <stdio.h>

int main () {
        int a,b,c;

        printf ("Ingrese 3 numeros diferentes: ");
        scanf ("%d%d%d",&a,&b,&c);

        if(a>b && a>c){
            printf ("El mayor numero es: %d",a);
        }else
            if(b>c && b>a){
                printf ("El mayor numero es: %d",b);
            }else
            if(c>a && c>b){
                printf ("El mayor numero es: %d",c);
            }
return 0;
}
