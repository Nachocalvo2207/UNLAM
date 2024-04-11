#include<stdio.h>
#define legajos 5
#define dias 4
void iniciarMatriz (int m[][dias],int cf, int cc);
void horasxDia (int m[][dias],int cf, int cc);
void horasEmpleados (int m[][dias],int cf, int cc);
void mejorEmpleado (int m[][dias],int,int);
void noTrabajo (int m[][dias],int,int);
int leeYvalida(int li,int ls);

int main (){

    int m[legajos][dias]= {{0}};
    iniciarMatriz(m,legajos,dias);
    horasxDia(m,legajos,dias);
    horasEmpleados(m,legajos,dias);
    mejorEmpleado(m,legajos,dias);
    noTrabajo (m,legajos,dias);

return 0;
}

int leeYvalida (int li, int ls){
    int x;

    do{
        scanf ("%d",&x);

    }while (x < li || x>ls);

return (x);
}


//Inicio Matriz
void iniciarMatriz (int m[legajos][dias],int cf, int cc){

    int legajo, dia, horas;

    printf ("Ingrese el legajo: ");
    legajo = leeYvalida(0,legajos);


    while (legajo !=0){

        printf ("Ingrese el dia: ");
        dia = leeYvalida (1,dias);

        printf ("Ingrese las horas trabajadas: ");
        horas = leeYvalida (1,12);

        m[legajo-1][dia-1] = horas;

        printf ("Ingrese el legajo: ");
        legajo = leeYvalida(0,legajos);

    }
}


void horasxDia (int m[legajos][dias],int cf, int cc){
    int i,j,s;

    for(j=0;j<cc;j++){
        s=0;
        for(i=0;i<cf;i++){
            s+=m[i][j];
        }

    printf ("\nEl dia %d se trabajo un total de %d hs\t",j+1,s);
    }
}

void horasEmpleados(int m [legajos][dias],int cf, int cc){
    int i,j,s;

    s=0;

    for(i=0;i<cf;i++){
        for(j=0;j<cc;j++){
            s+=m[i][j];
        }

    }
    printf ("\n El total de horas que se trabajaron fue: %d\t",s);
}

void mejorEmpleado (int m[legajos][dias],int cf,int cc ){

    int i,j,max;

    int v[legajos]={0};

    for (i=0;i<cf;i++){
        for(j=0;j<cc;j++){
           // if(i==0 || j==0 && m[i][j]>max){
            //    max = m[i][j];
           // }
           v[i]+=m[i][j];
        }
        if(i==0 || v[i] >max)
            max=v[i] ;
    }

    for (i=0;i<cf;i++){
            if(max == v[i]){
                printf ("\nEl legajo del empleado que mas trabajo es: %d\t",i+1);
            }
        }
}

void noTrabajo (int m[legajos][dias],int cf, int cc){
    int i,j;

        for (i=0;i<cf;i++){
        for(j=0;j<cc;j++){
            if(m[i][j]== 0){
                printf ("\nEl empleado de legajo %d no trabajo en este periodo.\t",i+1);
            }
        }
    }
}


