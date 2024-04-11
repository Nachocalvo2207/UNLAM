#include <stdio.h>
#include <stdlib.h>
#include<archivos.h>


#define ARCHIVOS_BIN "personas.bin"
#define ARCHIVOS_TXT "personas.txt"
#define error_archivo 1
#define OK 2


int main()
{

    /*

    FILE*pbin,*ptxt;
    pbin=fopen(ARCHIVOS_BIN,"rb");

    if(pbin==NULL) // !pbin
    {
        printf ("Error de apertura");

        return error_archivo;
    }

    ptxt = fopen(ARCHIVOS_TXT,"wt");

    if(ptxt == NULL)
    {
        printf ("Error de apertura");

        return error_archivo;
    }


    binario_a_texto (pbin, ptxt);



    fclose (pbin);
    fclose(ptxt);
    return 0;
    */

    FILE*pbin,*ptxt;
    pbin=fopen(ARCHIVOS_BIN,"w");

    if(pbin==NULL) // !pbin
    {
        printf ("Error de apertura");

        return error_archivo;
    }

    ptxt = fopen(ARCHIVOS_TXT,"wt");

    if(ptxt == NULL)
    {
        printf ("Error de apertura");

        return error_archivo;
    }


    binario_a_texto (pbin, ptxt);



    fclose (pbin);
    fclose(ptxt);
    return 0;
}
