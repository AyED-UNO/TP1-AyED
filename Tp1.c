#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//float calculoTotal(float,float,float,float,float,float,int,int,int,int,int,int);
float calculoTotal(float,int);
void informeSemanal(float, float);
void informeMensual(float, float);

main() {
	//Variables para precio de productos
	float precioHarina, precioEspagueti, precioTallarin, precioFusilli, precioLecheEnt, precioLecheDes;

	//Variables para ingreso de ventas
	int harina, espagueti, tallarin, fusilli, lecheEnt, lecheDes;     

	//Variables acumuladores
	float totalSemanal = 0, totalMensual = 0;

	//Variable contador
	int i;

	//Variables para seleccion (caracter)
	char tipoFideo;

	//Variables para seleccion (cadena de caracter)
	char opc[3], opcLeche[4];

	//Variables bandera
	int semanaMax = 0;

	//Inicio e ingreso de los precios de los productos
	printf("\t\tBienvenido\nPor favor, ingrese los precios de los productos.\n\n");

	printf("Harina:\n");
	scanf("%f", &precioHarina);

	printf("Espagueti:\n");
	scanf("%f", &precioEspagueti);

	printf("Tallarin:\n");
	scanf("%f", &precioTallarin);

	printf("Fusilli:\n");
	scanf("%f", &precioFusilli);

	printf("Leche Entera:\n");
	scanf("%f", &precioLecheEnt);

	printf("Leche Descremada:\n");
	scanf("%f", &precioLecheDes);

	//Inicio del bucle for para el ingreso de datos de venta semanales
	for( i = 1; i < 5 ; i++ ) {

		system("cls");

		printf("\t\tSemana %d\n", i);

		printf("\nIngrese la cantidad de unidades de harina vendidas:\n");
		scanf("%d", &harina);

		do {

			fflush(stdin);
			printf("Seleccione que tipo de fideo se vendio:\n");
			printf("'e' = Espagueti\t't' = Tallarin\t'f' = Fusilli\n");
			scanf("%c", &tipoFideo);

			switch(tipoFideo) {

				case 'e':

					printf("\nIngrese la cantidad de unidades de fideos espagueti vendidos:\n");
					scanf("%d", &espagueti);

					break;

				case 't':

					printf("\nIngrese la cantidad de unidades de fideos tallarin vendidos:\n");
					scanf("%d", &tallarin);

					break;

				case 'f':

					printf("\nIngrese la cantidad de unidades de fideos fusilli vendidos:\n");
					scanf("%d", &fusilli);

					break;
			}

			printf("\nSi se vendieron mas tipos de fideo ingrese SI, de lo contrario ingrese NO:\n");
			scanf("%s", opc);

		} while( strcmp( opc, "SI" ) == 0 );

		printf("Seleccione que tipo de leche se vendio:\n");
		printf("ENT = Entera\tDES = Descremada\n");
		scanf("%s", opcLeche);

		if (strcmp(opcLeche, "ENT") == 0) {

			printf("\nIngrese la cantidad de unidades de leche entera vendidas:\n");
			scanf("%d", &lecheEnt);

		} else {

			printf("\nIngrese la cantidad de unidades de leche descremada vendidas:\n");
			scanf("%d", &lecheDes);

		}

		printf("\nSi se vendieron mas tipos de leche ingrese SI, de lo contrario ingrese NO:\n");
		scanf("%s", opc);

		if ( strcmp( opc, "SI" ) == 0 ) {

			if (!strcmp(opcLeche, "ENT") == 0) {

				printf("\nIngrese la cantidad de unidades de leche entera vendidas:\n");
				scanf("%d", &lecheEnt);

			} else {

				printf("\nIngrese la cantidad de unidades de leche descremada vendidas:\n");
				scanf("%d", &lecheDes);

			}

		}

		//Calculo de ganancias semanales
		//totalSemanal = calculoTotal(precioHarina,precioEspagueti,precioTallarin,precioFusilli,precioLecheEnt,precioLecheDes,harina,espagueti,tallarin,fusilli,lecheEnt,lecheDes);
		
		totalSemanal += calculoTotal(precioHarina, harina);
		totalSemanal += calculoTotal(precioEspagueti, espagueti);
		totalSemanal += calculoTotal(precioTallarin, tallarin);
		totalSemanal += calculoTotal(precioFusilli, fusilli);
		totalSemanal += calculoTotal(precioLecheEnt, lecheEnt);
		totalSemanal += calculoTotal(precioLecheDes, lecheDes);
		
		
		
		
		system("pause");

	}

	system("pause");

}
/*
float calculoTotal(float preHa, float preEs, float preTa, float preFu, float preLeEnt, float preLeDes, int cantHa, int cantEs, int cantTa, int cantFu, int cantLeEnt, int cantLeDes){
	
	float total;
	
	total = preHa * cantHa + preEs * cantEs + preTa * cantTa + preFu * cantFu + preLeEnt * cantLeEnt + preLeDes * cantLeDes;
	
	return total;
	
}
*/

float totalSemanal(float precio, int cantidad){
	
	float total;
	
	total = precio * cantidad;
	
	return total;	
	
}

