#include<stdio.h>

struct banco {
    int nCuenta;
    char apYnom [51];
    float saldo;
};

int busqueda (struct banco [],int, int );

int main (){
    struct banco reg;
    struct banco vSal[2000];

    FILE*arch;
    int cta,cop,dia,i,cant,x;
    float imp;

    int vDep[2000] = {0};
    int vExt[2000] = {0};

    arch = fopen("saldante.dat","rb");

    if(arch == NULL){
        printf ("Error");
        getch ();
        exit (1);
    }

    i=0;

    fread (&reg, sizeof(reg),1,arch);
    while (!feof(arch)){
        vSal[i] = reg;
        i++;
        fread (&reg, sizeof(reg),1,arch);
    }
    cant = i;
    fclose (arch);

    printf ("Ingrese numero de cuenta: ");
    scanf ("%d",&cta);

    while (cta != 0){
        x = busqueda (vSal,cta, cant);

        if (x != 1){
            printf ("Ingrese codigo de operacion: ");
            scanf ("%d",&cop);

            printf ("Ingrese el importe: ");
            scanf ("%f",&imp);

            if (cop == 1){
                vSal[x].saldo += imp;
                vDep[x]++;
            }
            else {
                vSal[x].saldo -= imp;
                vExt[x]++;
            }
        }
        else {
            printf ("Cuenta inexistente");
        }

        printf ("Ingrese numero de cuenta: ");
        scanf ("%d",&cta);
    }

    printf ("Cuentas sin movimiento: ");

    for (i=0;i<cant; i++){
        if (vDep[i]==0 && vExt[i]==0){
            printf ("%d",vSal[i].nCuenta);
        }
    }

}
