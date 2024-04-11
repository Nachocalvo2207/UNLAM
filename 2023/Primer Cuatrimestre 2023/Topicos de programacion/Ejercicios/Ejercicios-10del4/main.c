#include <stdio.h>
#include <stdlib.h>
#define TAM 4
int mat1[TAM][TAM];
struct alumno{
        char nombre[30];
        char DNI[10];
        int edad;
        float altura;
};

//RECORRE TODA LA MATRIZ
/*
void recorrer_mat(int mat1[TAM][TAM]){
    int i,j;

    for (i=0;i<=TAM-1;i++){
        for(j=0;j<=TAM-1;j++){
            printf("%d\n",mat1[i][j]);
        }
    }
}
*/

/*void recorrer_mat2(int mat1[TAM][TAM]){
    int i,j;

    for (i=1;i<=TAM-1;i++){
        for(j=0;j<=TAM-1;j++){
            printf("%d\n",mat1[i][j]);
        }
    }
}
*/

/* Lo comente para que main2 no me tire error
int main()
{
    int mat1[TAM][TAM] ={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}

};
    recorrer_mat2(mat1);

struct alumno alu1;

    return 0;
}
*/
