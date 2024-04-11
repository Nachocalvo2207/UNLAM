#include<stdio.h>

struct productos {
    int codigo;
    char descripcion [30];
    int puntoDePedido;
    int stock;
};

void  mostrar (struct vprod, int);
int busq(struct vprod,int, int );
int PUNTO_C ();
int leeYvalida(int, int);
int leeYvalida2(int, int);


int main () {
    int i,x,cont,codigo,unidades,cliente,dia,pMax,posMax;
    int VP [5000]= {0};
    int VD [30] = {0};
    struct productos prod;
    struct productos vprod[5000];

    FILE*arch;
    arch = fopen("STOCK.dat","rb");

    if(arch == NULL){
        printf ("Error");
        getch ();
        exit(1);
    }

    i=0;
    fread (&vprod,sizeof(vprod),1,arch);
    while (!feof(arch)){
        i++;
        vprod[i] = prod;
        fread(&vprod,sizeof(vprod),1,arch);
    }
    fclose(arch);
    cont= i;

    //Ingreso datos por teclado:

    printf ("Ingrese un codigo de producto: ");
    codigo = leeYvalida(0,10000);

    while(codigo != 0){

        x= busq (vprod,codigo,cont);

        if(x != -1){

        printf ("Ingres la cantidad de unidades pedidas: ");
        scanf ("%d",&unidades);
        vprod[x].stock -= unidades;

        VP[x] += unidades; //Aca

        printf ("Ingrese el numero de cliente: ");
        cliente = leeYvalida2(1,3000);

        printf ("Ingrese el dia: ");
        dia = leeYvalida2(1,30);
        VD[dia-1] += unidades; //Aca tuve error


        printf ("Ingrese un codigo de producto: ");
        codigo = leeYvalida(0,10000);
        }
    }

    //PUNTO A

    for (i=0; i<cont;i++){
        if (VP[i] = 0 || VP[i] > pMax){
            pMax = VP[i];
            posMax = i;
        }
    }

    printf ("El codigo del producto mas vendido es: %d",vprod[posMax].codigo);

    //PUNTO B

    for (i=0; i<cont; i++){
        if(vprod[i].stock < vprod[i].puntoDePedido){
            printf ("/n Se debe pedir stock de los siguientes productos: &d /t",vprod[i].codigo);
        }
    }

    //PUNTO C

    mostrar (VD,unidades,10000);

    //PUNTO D

    arch=fopen("STOCKACT.dat","wb");

    if(arch == NULL){
        printf ("Error");
        getch ();
        exit(1);
    }

    for (i=0,i<cont, i++){

        fwrite (&vprod,sizeof(vprod),1,arch);
    }
    fclose(arch);

    return 0;
}

//PUNTO C
void mostrar (int VD [],int cantProductos,int n){
    int i;

    printf ("Dia: / Cantidad Productos");
    for (i=0,i<30,i++){
            if(VD[i] > n){
                printf ("/n %d /t /n %d",i+1, VD[i] );
            }
    }
}






int leeYvalida(int li,int ls){
    int x;

    do{
        scanf ("%d",&x);
    }while (x!=li || (x<1000 && x>ls));

    return (x);
}
