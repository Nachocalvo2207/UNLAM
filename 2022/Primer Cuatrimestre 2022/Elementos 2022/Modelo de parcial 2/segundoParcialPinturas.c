#include <stdio.h>
#define N 10
typedef struct
{
	int 	arti;
	char 	desc[81];
	int 	stock;
	float 	precio;
}pintura;

typedef struct
{
	int cliente;
	int arti;
	int cantidad;
}cliente;
int lee_control(int, int);
int mayorcero(int);
int leerArchivo(pintura [], int);
int busqueda(pintura [], int, int);
void puntoa(float[], int);///factXCliente
void puntob(int[], int);///cantComprasXCliente
void puntoc(float[], int [], int);///factXCliente y cantComprasXCliente
void puntod(pintura[], int [], int);///articuloNoVendido
void puntoe(pintura[], int);

///pendiente para probar la carga
void cargaInicial();
void mostrarContenido(pintura [], int);


int main()
{
	pintura pint[500];
	int cant;
	float importe;
	cliente auxCli;

	float 	factXCliente[N] = {0};///punto a
	int 	cantComprasXCliente[N] = {0};///punto b

	///punto c uso un for de 0 a 99 + factXCliente +  cantComprasXCliente

	int 	articuloNoVendido[500] = {0};///punto d


	FILE * pf;
	int i, pos;

	// ahora lo grabo a un archivo
	pf = fopen("faltastock.dat" , "wb");
	if (pf == NULL)
	{
		printf("No se pudo crear el archivo.");
		getch();
		exit (1);
	}


	///cargaInicial();


	///paso a memoria el archivo
	cant = leerArchivo(pint, 500);
	mostrarContenido(pint, cant);

	///muestro el contenido, no es necesario
	leerArchivo(pint, cant);

	///realizar venta
	printf("\nCliente, ");
	auxCli.cliente = lee_control(0,N);

	while(auxCli.cliente > 0)
	{
		printf("\nArticulo, ");
		auxCli.arti = lee_control(10000, 99999);

		///primero busco si existe el articulo en mi vector
		pos = busqueda(pint, cant, auxCli.arti);
		if(pos > -1)
		{
			printf("\nCantidad, ");
			auxCli.cantidad = mayorcero(0);

			///ahora me fijo si tengo stock suficiente para vender
			if(auxCli.cantidad > pint[pos].stock)
			{
				///informo que no se pudo vender
				printf("\nEl articulo %d no tiene suficiente stock, solo %d ", pint[pos].stock);

				///no puedo vender, con lo cual grabo en disco
				fwrite(&auxCli, sizeof(cliente), 1, pf);

				///punto d, lo marco como q no lo pude vender
				articuloNoVendido[pos] = 1;
			}
			else
			{
				///realizo el proceso principal
				///punto a (y de paso dejo armado parte del c)
				importe = auxCli.cantidad * pint[pos].precio;
				factXCliente[auxCli.cliente-1]+= importe;

				///punto b (y de paso dejo armado parte del c)
				cantComprasXCliente[auxCli.cliente-1]++;


				///resto lo vendido (para todo principalmente y punto e )
				pint[pos].stock -= auxCli.cantidad ;

			}

		}
		else
		{
			printf("\nEl articulo %d no existe ", auxCli.arti);
		}

		printf("\nCliente, ");
		auxCli.cliente = lee_control(0,N);
	}


	fclose(pf);

	puntoa(factXCliente, N);
	puntob(cantComprasXCliente, N);
	puntoc(factXCliente, cantComprasXCliente, N);
	puntod(pint, articuloNoVendido, cant);
	puntoe(pint, cant);
	return 1;

}
int lee_control(int li, int ls)
{
	int valor;
	printf("Ingrese numero entre %d y %d ", li, ls);
	scanf("%d", &valor);
	return valor;
}
int mayorcero(int li)
{
	int valor;
	printf("Ingrese numero mayor a %d: ", li);
	scanf("%d", &valor);
	return valor;
}
int leerArchivo(pintura vpint[], int cant)
{
    FILE * pf;
    int i = 0;
    pintura aux;

    pf = fopen("segundoParcialPinturas.dat", "rb");
    if (pf == NULL)
    {
        printf("No se pudo abrir el archivo.");
        getch();
        exit (1);
    }

    fread(&aux, sizeof(pintura), 1, pf);
    while(i < cant && !feof(pf))
    {
		vpint[i] = aux;
        i++;
        fread(&aux, sizeof(pintura), 1, pf);
    }
    fclose(pf);

    return i;
}
void puntoa(float v[], int cant)
{
	int i;
	printf("\nCliente\tMonto\n");
	for(i = 0; i < cant; i++)
	{
		printf("\n%d\t%.2f", i+1, v[i]);
	}
}
void puntob(int v[], int cant)
{
	int 	i;
	int 	clienteMax;
	float 	montoMaximo = 0;
	int 	b 			= 0;

	printf("\nCliente\tCantidad de compras\n");
	for(i = 0; i < cant; i++)
	{
		printf("\n%d\t%.2f", i+1, v[i]);
	}

	for(i = 0; i < cant; i++)
	{
		if(b == 0 || v[i] > montoMaximo)
		{
			montoMaximo = v[i];
			b 			= 1;
			clienteMax 	= i;
		}
	}
	printf("\nCliente : %d\t realizó %d compras y es el maximo", clienteMax+1, montoMaximo);
}
void puntoc(float vmonto[], int vcant[], int cant)
{
	int i;
	printf("\nCliente\tMonto\tCantidad de compras\n\n");
	for(i = 0; i < cant; i++)
	{
		printf("\n%d\t%.2f\t%d", i+1, vmonto[i], vcant[i]);
	}
}
void puntod(pintura pint[], int v[], int cant)
{
	int i;
	printf("\nArticulos que no se pudieron vender por falta de stock");
	for(i = 0; i < cant; i++)
	{
		if(v[i] == 1)
		{
			printf("\n%d", pint[i].arti);
		}
	}
}
void puntoe(pintura vpint[], int cant)
{
	FILE * pf;
	int i;

	// ahora lo grabo a un archivo
	pf = fopen("segundoParcialPinturas.dat" , "wb");
	if (pf == NULL)
	{
		printf("No se pudo crear el archivo.");
		getch();
		exit (1);
	}
    for(i = 0; i < cant; i++)
    {
        fwrite(&vpint[i], sizeof(pintura), 1, pf);
    }
    fclose(pf);

}
int busqueda(pintura vector[], int datoABuscar, int cant)
{
    int pos = -1, i = 0;

    while(pos == -1 && i<cant)
    {
        if(vector[i].arti == datoABuscar)
            pos = i;

        i++;
    }
    return pos;
}
void cargaInicial()
{
	FILE * pf;
	pintura aux;

	// ahora lo grabo a un archivo
	pf = fopen("segundoParcialPinturas.dat" , "wb");
	if (pf == NULL)
	{
		printf("No se pudo crear el archivo.");
		getch();
		exit (1);
	}

	printf("\nArticulo (100000 para finalizar), ");
	aux.arti = lee_control(10000, 100000);

	while(aux.arti != 100000)
    {
		printf("\nIngrese descripcion : ");
		fflush(stdin);
		gets(aux.desc);

		printf("\nStock, ");
		aux.stock = mayorcero(0);

		printf("\nIngrese precio : ");
		scanf("%f", &aux.precio);

        fwrite(&aux, sizeof(pintura), 1, pf);

        printf("\nArticulo (100000 para finalizar), ");
		aux.arti = lee_control(10000, 100000);
    }
    fclose(pf);
}

void mostrarContenido(pintura vpint[], int cant)
{
	int i;
	printf("\nArt\tDesc\tStock\tPrecio ");
	for(i = 0; i < cant; i++)
	{
		printf("\n%d\t%10s\t%d\t%f",vpint[i].arti, vpint[i].desc, vpint[i].stock, vpint[i].precio);
	}
}
