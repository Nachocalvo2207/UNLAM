#include <stdio.h>

struct producto {
    int nArt;
    char descripcion [80];
    int stock;
    float precioU;
};

int LEE_CONTROL(int,int);
int MAYORCERO();
int leeYvalida(int,int);
int busq(struct producto[],int,int);

int main () {
    int a, b,i,x,cont,cliente,articulo,uvendidas;
    float facturacion[]={0};
    struct producto prod;
    struct producto vprod[500];


    FILE*arch;
    FILE*rechazados;
    arch = fopen("PINTURAS.dat","wb");

    if(arch == NULL){
        printf ("Error");
        getch();
        exit(1);
    }
    i=0;

    fread (arch,sizeof(arch),1,arch);

    while(!feof){
        vprod[i]=prod;
        i++;
        fread (&arch,sizeof(arch),1,arch);
    }
    cont= i;

    fopen("FALTASTOCK.dat","wb");
    fwrite(&rechazados,sizeof(rechazados),1,rechazados);

    printf ("Ingrese el numero de cliente: ");
    cliente = LEE_CONTROL(-1,100);

    printf ("Ingrese la cantidad de unidades vendidas: ");
    uvendidas = MAYORCERO ();


    printf ("Ingrese el numero de articulo: ");
    articulo = LEE_CONTROL(10000,99999);

    x=busq(vprod,articulo,uvendidas,cont);

        if(x != -1){

            printf ("Ingrese la cantidad de unidades vendidas: ");
            uvendidas = MAYORCERO ();

            if(uvendidas > vprod[x].stock){
                if(rechazados == NULL){
                    printf ("Error");
                    getch();
                    exit(1);
                }
                fclose(rechazados);
                }
                else{
                    vprod[x].stock -= uvendidas;
                    facturacion [x] += uvendidas * vprod[x].precioU;
                }
            }

        }
}

int busqueda (struct producto vprod[],int articulo ,int uvendidas ,int cont){
    int pos = -1; int i=0;

    while (i<cont && pos = -1){
        if (uvendidas < vprod[i].stock && articulo == vprod[i].nArt){
            pos = i;

    }
}
