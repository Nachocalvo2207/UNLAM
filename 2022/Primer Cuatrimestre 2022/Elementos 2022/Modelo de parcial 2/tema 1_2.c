#include <stdio.h>
struct INF
{
    int COD;
    char DESC[30];
    int PEDIDO;
    int STOCK;
};

///*DECLARO LAS FUNCIONES*///
int BUSQ(struct INF[], int, int);
void MOSTRAR(struct INF[], int, int);
void GENARCHIVO(struct INF[], int);
int lee(int, int);
int lee2(int, int);

int main()
{
    struct INF I; struct INF VI[5000];
    int COD, NC, DIA, CUP, i, c, x, may, prodmax;
    int VP[9000]={0};
    FILE*arch;

    ///*LEO EL ARCHIVO QUE ME DAN Y LO PASO A UN VECTOR DE ESTRUCTURAS*///
    arch=fopen("STOCK.dat","rb");
    if(arch==NULL)
    {
        printf("ERROR EN LA APERTURA DE STOCK.dat");
        getch();
        exit(1);
    }
    i=0;
    fread(&I, sizeof(I), 1, arch);
    while(!feof(arch))
    {
        VI[i]=I;
        i++;
        fread(&I, sizeof(I), 1, arch);
    }
    c=i;
    fclose(arch);

    ///*COMIENZA EL INGRESO POR TECLADO*///
    printf("Ingrese el CODIGO del PRODUCTO:\t");
    COD=lee(0, 10000);
    while(COD!=0)
    {
        x=BUSQ(VI, COD, c);
        if(x!=-1)
        {
            printf("Ingrese la CANTIDAD de UNIDADES PEDIDAS:\t");
            scanf("%d",&CUP);
            VI[x].STOCK-=CUP;

            printf("Ingrese el NRO de CLIENTE:\t");
            NC=lee2(1, 3000);

            printf("Ingrese el DIA:\t");
            DIA=lee2(1, 30);
            VP[COD-1]++;
        }
        printf("Ingrese el CODIGO del PRODUCTO:\t");
        COD=lee(0, 10000);
    }
    for(i=0; i<9000; i++)
    {
        if(i==0||VP[i]>may)
        {
            may=VP[i];
            prodmax=i;
        }
    }
    printf("El CODIGO del PRODUCTO MAS VENDIDO ES:%d\t", prodmax);///PUNTO A

    printf("Los PRODUCTOS que se necesitan reponer son los siguientes:\t");///PUNTO B
   for(i=0; i<9000; i++)
   {
       if(VI[i].PEDIDO < VI[i].STOCK)
       {
           printf("%d\n", VI[i].COD);
       }
   }
    if(CUP>10000)
    {
        MOSTRAR(struct VI[], c, CUP);///PUNTO C
    }

   GENARCHIVO(struct VI[], c);///PUNTO D

   return(0);

}///*TERMINA EL PP*///

///*DESARROLLO LAS FUNCIONES*///
int lee(int li, int ls)
{
    int x;
    do
    {
        scanf("%d",&x);
    } while(x!=li || (x<1000 || x>ls));

    return(x);
}
int lee2(int li, int ls)
{
    int x;
    do
    {
        scanf("%d",&x)
    } while(x<li||x>ls);

    return(x);
}
int BUSQ(struct INF VI[], int valor, int n)
{
    int i=0; int pos=-1;
    while(i<n&&pos==-1)
    {
        if(valor==VI[i].COD)
            pos=i;
        else
            i++;
    }
    return(pos);
}
void MOSTRAR(struct INF VI[], int n, int CUP)
{
    int i;
    printf("DIA /t CANTIDAD PRODUCTOS");
    for(i=0; i<n, i++)
    {
        printf("\n %d \t \n %d", VI[i].DIA, CUP);
    }
}
void GENARCHIVO(struct INF VI[], int n)
{
    FILE*arch;
    struct INF I;
    int i;

    arch=fopen("STOCKactualizado.dat","wb");
    if(arch==NULL)
    {
        printf("ERROR EN LA APERTURA DE STOCKactualizado.dat");
        getch();
        exit(1);
    }
    for(i=0; i<n; i++)
    {
        fwrite(&VI[i], sizeof(I), 1, arch);
    }
    fclose(arch);
}
