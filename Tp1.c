#include<stdlib.h>
#include<stdio.h>
#include<string.h>

float calculoTotal(float precio, int cantidad);
void informeSemanal(float total, float gasto, char maxTipo[], int maxCant);
//void informeMensual(float, float);

main() {
	//Variables para precio de productos
	float precioHarina, precioEspagueti, precioTallarin, precioFusilli, precioLecheEnt, precioLecheDes;

	//Variables para ingreso de ventas
	int harina = 0, espagueti = 0, tallarin = 0, fusilli = 0, lecheEnt = 0, lecheDes = 0;  
	
	float gastoReposicion = 0;   

	//Variables acumuladores
	float totalSemanal = 0, totalMensual = 0;

	//Variable contador
	int i;

	//Variables para seleccion (caracter)
	char tipoFideo;

	//Variables para seleccion (cadena de caracter)
	char opc[3], opcLeche[4];
	
	//Variables para control de maximos
	int semanaMax, lecheMax;
	float totalSemanaMax;
	char lecheMaxTipo[11];
	
	//

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
			printf("'E' = Espagueti\t'T' = Tallarin\t'F' = Fusilli\n");
			scanf("%c", &tipoFideo);

			switch(tipoFideo) {

				case 'E':

					printf("\nIngrese la cantidad de unidades de fideos espagueti vendidos:\n");
					scanf("%d", &espagueti);

					break;

				case 'T':

					printf("\nIngrese la cantidad de unidades de fideos tallarin vendidos:\n");
					scanf("%d", &tallarin);

					break;

				case 'F':

					printf("\nIngrese la cantidad de unidades de fideos fusilli vendidos:\n");
					scanf("%d", &fusilli);

					break;
			}

			fflush(stdin);
			printf("\nSi se vendieron mas tipos de fideo ingrese SI, de lo contrario ingrese NO:\n");
			scanf("%s", opc);

		} while(strcmp(opc, "SI") == 0);

		fflush(stdin);
		printf("Seleccione que tipo de leche se vendio:\n");
		printf("ENT = Entera\tDES = Descremada\n");
		scanf("%s", opcLeche);

		if (strcmp(opcLeche, "ENT") == 0) {

			printf("\nIngrese la cantidad de unidades de leche entera vendidas:\n");
			scanf("%d", &lecheEnt);
			lecheMax = lecheEnt;

		} else {

			printf("\nIngrese la cantidad de unidades de leche descremada vendidas:\n");
			scanf("%d", &lecheDes);
			lecheMax = lecheDes;

		}
		
		fflush(stdin);
		printf("\nSi se vendieron mas tipos de leche ingrese SI, de lo contrario ingrese NO:\n");
		scanf("%s", opc);

		if (strcmp(opc,"SI") == 0) {

			if (strcmp(opcLeche,"ENT") == 1) {

				printf("\nIngrese la cantidad de unidades de leche entera vendidas:\n");
				scanf("%d", &lecheEnt);
				
				if (lecheMax < lecheEnt){
					lecheMax = lecheEnt;
				}

			} else {

				printf("\nIngrese la cantidad de unidades de leche descremada vendidas:\n");
				scanf("%d", &lecheDes);
				
				if (lecheMax < lecheDes){
					lecheMax = lecheDes;
				}

			}

		}
		
		if(lecheMax == 0){
			
			strcpy(lecheMaxTipo, "ninguna");
			
		} else {
			
			if(lecheMax == lecheEnt) {
			
				strcpy(lecheMaxTipo, "Entera");
			
			} else {
			
				strcpy(lecheMaxTipo, "Descremada");
			
			}
		}

		
		totalSemanal += calculoTotal(precioHarina, harina);
		totalSemanal += calculoTotal(precioEspagueti, espagueti);
		totalSemanal += calculoTotal(precioTallarin, tallarin);
		totalSemanal += calculoTotal(precioFusilli, fusilli);
		totalSemanal += calculoTotal(precioLecheEnt, lecheEnt);
		totalSemanal += calculoTotal(precioLecheDes, lecheDes);
		
		if(i == 1) {
			
			semanaMax = i;
			totalSemanaMax = totalSemanal;
			
		} else if(totalSemanaMax < totalSemanal){
			
			semanaMax = i;
			totalSemanaMax = totalSemanal;
			totalSemanaMax
			
		}
		
		gastoReposicion = (totalSemanal * 0.8);
		
		informeSemanal(totalSemanal, gastoReposicion, lecheMaxTipo, lecheMax);
		
		//Reseteo de valores
		
		
		system("pause");

	}

	system("pause");

}

float calculoTotal(float precio, int cantidad){
	
	float total;
	
	total = precio * cantidad;
	
	return total;	
	
}

void informeSemanal(float total, float gasto, char maxTipo[], int maxCant){
	float totalFinal;
	totalFinal = total - gasto;
	system("cls");
	
	printf("El total semanal previo a reposicion fue: \t$%.2f\nEl gasto de reposicion fue: \t\t$%.2f\n", total, gasto);
	printf("El total semanal luego de reponer es: \t\t$%.2f\n", totalFinal);
	
	printf("------------------------------------------\n");
	
	if(strcmp(maxTipo,"ninguna") == 0){
		
		printf("Esta semana no hubo ventas de leche.");
	
	} else {
		
		printf("El tipo de leche mas vendido fue: \t\t%s\nCon un total de %d unidades vendidas.", maxTipo, maxCant);
	
	}
	
}
