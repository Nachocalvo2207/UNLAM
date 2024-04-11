#include<stdio.h>

struct producto {
    int articulo;
    int stock;
    float precioU;
};

int leeYvalida;
int busqueda (struct producto [],int,int);
int generarArchivo(struct producto[],int);

int main () {
    int i,cont,nCliente,mes,art,artVendidos;
    int VM[12];
    struct producto prod;
    struct producto vprod[1500];

    FILE*arch;
    arch=fopen("stockA.dat","rb");

    if(arch == NULL){
        printf ("Error");
        getch();
        exit(1);
    }

    i=0;
    fread(&prod,sizeof(prod),1,arch);

    while(!feof(arch)){
        vprod[i] = vprod;
        i++;
        fread(&prod,sizeof(prod),1,arch);
    }
    cont = i;
    fclose(arch);

    printf ("Ingrese el numero de cliente: ");
    nCliente = leeYvalida(0,99);

    while (nCliente != 0){
        printf ("Ingrese el numero de articulo: ");
        scanf ("%d",&art);

        x=busq(vprod,art,cont);

        if (x!= -1){
            printf ("Ingrese el mes de la venta: ");
            mes=leeYvalida(1,12);

            printf ("Ingrese la cantidad de unidades vendidas:");
            scanf ("%d",&artVendidos);
            VM[mes-1]++;

        }

}
