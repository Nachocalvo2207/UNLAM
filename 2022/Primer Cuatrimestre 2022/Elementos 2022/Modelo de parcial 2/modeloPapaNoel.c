#include<stdio.h>

struct santa {
    int codigo;
    char descripcion [25];
    int cantidad;
};

int leeYvalida (int,int);
int busq(struct santa [],int,int);
void generarArchivo (struct Santa[],int);

int main(){
    struct santa reg;
    struct santa vreg[32000];

    int i,x,cont,cod,zona,m,h,cantH=0,cantM=0,cantPedidos,cantRechazados,maxZona,posZona;
    char nombre,direccion,sexo;
    float porcM,porcH,porcRech;
    int vzona[1000];

    FILE*arch;
    arch=fopen("juguetes.dat","rb");

    if(arch == NULL){
        printf ("Error");
        getch ();
        exit(1);
    }

    i=0;
    fread(&reg,sizeof(reg),1,arch);
    while(!feof(arch)){
        vreg[i] = reg;
        i++;
    }
    fclose(arch);
    cont=i;

    //*Ingreso por teclado*

    printf ("Ingrese el codigo del juguete: ");

    while (cod != 0);

    x=busq(vreg,cod,cont);
    cantPedidos++;

    if(x!= -1){
        vreg[x].cantidad --;

        printf ("Ingrese el nombre del ni�o: ");
        fflush(stdin);
        gets(nombre);

        printf ("Ingrese la direccion: ");
        fflush(stdin);
        gets(direccion);

        printf ("Ingrese la zona: ");
        zona = leeYvalida(1,1000);
        vzona[zona-1]++;

        printf ("Ingrese el sexo: ");
        do{
            scanf ("%c",sexo);
        }while (sexo != m || sexo != h);

        if(sexo == m)
            cantM++;
        else
            cantH++;
    }
    else {
        printf ("No existe ese codigo de juguete: ");
        cantRechazados++;
    }

    //Punto B

    for(i=0; i<1000; i++){
        if(vzona[i]>maxZona || i==0){
            maxZona= vzona[i];
            posZona = i;
        }
    }

    printf ("La zona con mas pedidos es: %d",posZona+1);

    //Punto C

    porcH = (cantH /cantPedidos) * 100.0;
    porcM = (cantM / cantPedidos) * 100.0;
    porcRech = (cantRechazados/cantPedidos) * 100.0;

    printf ("El porcentaje de hombres que solicitaron regalos es: %d",porcH);
    printf ("El porcentaje de mujeres que solicitaron regalos es: %d",porcM);
    printf ("El porcentaje de rechazados es: %d",porcRech);

    return 0;

    generarArchivo(vreg,cont)
}

int busq (struct santa vreg[],int cod,int contador){
    int i=0,pos = -1;

    while (i<contador && pos == -1){
        if(cod == vreg[i].codigo)
            pos = i;
        else
            i++;
    }
}

void generarArchivo(struct santa vreg[],int cont){

    struct  santa vreg;
    int i;

    FILE*arch;
    arch = fopen("juguetesAct","wb");
    if(arch == NULL){
        printf ("Error");
        getch();
        exit(1);
    }

    for (i=0;i<cont;i++){
        fwrite(&vreg,sizeof(vreg),1,arch);
    }
    fclose(arch);

}
