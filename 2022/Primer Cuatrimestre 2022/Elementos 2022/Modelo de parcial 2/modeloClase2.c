#include<stdio.h>

struct empleados {
    int legajo;
    float valorHora;
    char apYnom [30];
    float totalHs;
    float sueldo;
    int dia;
    int mes;

};

int leeYvalida(int,int);
float leeYvalida2(float,float);

int main () {
    struct empleados emp;
    struct empleados vEmp [500];
    int i,x, leg,cont, cantRechazados = 0, cantTotal=0;
    float hsTrabajadas, rechazados;

    FILE*arch;
    arch = fopen("personal.dat","rb");
    if (arch == NULL){
        printf ("Ha ocurrido un error");
        getch();
        exit (1);
    }

    i=0;
    fread (&emp,sizeof(emp),1,arch);
    while (!feof(arch)){
        vEmp[i] = emp;
        i++;
        fread (&emp,sizeof(emp),1,arch);

    }

    cont = i;
    fclose (arch);

    printf ("Ingrese su legajo: ");
    leg = leeYvalida (99,2500);

    while (leg != 99){
        x= busq (vEmp,leg,cont);
         cantTotal ++;

        if (x != -1){
            printf ("Ingrese la cantidad de horas trabajadas: ");
            hsTrabajadas = leeYvalida2_(0.5,24);
            vEmp[x].totalHs += hsTrabajadas;
            vEmp[x].sueldo += hsTrabajadas * vEmp[x].valorHora;
            vEmp[x].dia = 1;
            vEmp[x].mes = 6;
        }
        else {
            cantRechazados ++;
        }

        printf ("Ingrese su legajo: ");
        leg = leeYvalida (99,2500);
    }

    rechazados = (cantRechazados/cantTotal) * 100;

    printf ("El porcentaje es empleados no encontrados es: %.2f",rechazados);

    generarArchivo(vEmp,cont);

    return 0;

}

void generarArchivo (struct empleados vEmp [],int n){
    int i;
    struct empleados v;
    FILE*arch;
    arch = fopen("personal2.dat","wb");

    for (i=0;i<n;i++){
        fwrite (&vEmp[i],sizeof(v),1,arch);
    }
    fclose (arch);
}



