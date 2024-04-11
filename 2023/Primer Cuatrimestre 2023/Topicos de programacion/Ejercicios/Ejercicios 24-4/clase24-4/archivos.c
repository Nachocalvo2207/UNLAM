#include <archivos.h>

typedef struct {
int dia;
int mes;
int año;
}t_fecha

typedef struct {
        int id;
        char nya [50];
        t_fecha f_nac;
}t_dato;

int binario_a_texto(FILE*pbin,FILE*ptxt)
{
    t_dato vper[] = {{998,"jonathan",{22,7,2020}},
                    {12,"Lucas",{3,1,2021}},
                    {998,"jonathan",{22,7,2020}}
                    }
    fwrite(&vper,sizeof(vper),1,pbin);

    t_dato per;

    while(fread(&per,sizeof(t_dato),1,pbin))
    {
        fprintf(ptxt,"%d %s %d %d %d",per.id,per.nya,per.f_nac.dia,per.f_nac.mes,per.f_nac.año);

        return OK;
    }
}


int binario_a_texto(FILE*pbin,FILE*ptxt)
{

}


//PARTE 2

int texto_variable_a_binario(FILE*pbin,FILE*pxtx)
{
    char cadena [TAM];
    t_dato per;
    while(fgets(cadena,TAM,ptxt))
    {
        sscanf(cadena,"%d | %[] | %d/%d%d",per.id,per.nya,per.f_nac.dia,per.f_nac.mes,per.f_nac.año);

        fwrite(&per,sizeof(t_dato),1,pbin);
    }

    return OK;
}

int texto_fijo_a_binario(FILE*pbin,FILE*pxtx)
{
    char cadena [TAM],pcad;
    t_dato per;
    pcad = cadena;

    while(fgets(cadena,TAM,ptxt))
    {
        *(pcad + strlen(pcad)-1) = '\0';
        sscanf(pcad +strlen(pcad)-TAM_FECHA,"%2d %2d %2d",per.f_nac.dia,per.f_nac.mes,per.f_nac.año)

        fwrite(&per,sizeof(t_dato),1,pbin);
    }

    return OK;
}
