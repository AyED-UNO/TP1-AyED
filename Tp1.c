#include<stdlib.h>
#include<stdio.h>
#include<string.h>

float calculoTotal(float precio, int cantidad);
void informeSemanal(float subtotal, float gasto, float total, char maxTipo[], int maxCant, int tipoVendido);
void informeMensual(float totalFinal, int maxSemana, float mejorSemana);

main() {
	//Variables para precio de productos
	float precioHarina, precioEspagueti, precioTallarin, precioFusilli, precioLecheEnt, precioLecheDes;

	//Variables para ingreso de ventas
	int harina, espagueti, tallarin, fusilli, lecheEnt, lecheDes;  
	
	float gastoReposicion = 0;   

	//Variables acumuladores
	float subtotalSemanal, totalSemanal, totalMensual = 0;

	//Variable contador
	int tiposFideosVendidos;

	//Variables para seleccion (caracter)
	char tipoFideo;

	//Variables para seleccion (cadena de caracter)
	char opc[3], opcLeche[4];
	
	//Variables para control de maximos
	int semanaMax, lecheMax;
	float totalSemanaMax;
	char lecheMaxTipo[11];
	
	int i, flagLeche;

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
	
	printf("\n");
	system("pause");

	//Inicio del bucle for para el ingreso de datos de venta semanales
	for( i = 1; i < 5 ; i++ ) {
		
		//Reseteo de valores
		harina = espagueti = tallarin = fusilli = lecheEnt = lecheDes = subtotalSemanal = totalSemanal = tiposFideosVendidos = 0;

		system("cls");

		printf("\t\tSemana %d\n", i);

		printf("\nIngrese la cantidad de unidades de harina vendidas:\n");
		scanf("%d", &harina);

		do {
			fflush(stdin);
			printf("\nSeleccione que tipo de fideo se vendio:\n");
			printf("'E' = Espagueti\t'T' = Tallarin\t'F' = Fusilli\t'N' = Sin ventas\n");
			scanf("%c", &tipoFideo);

			switch(tipoFideo) {

				case 'E':

					printf("\nIngrese la cantidad de unidades de fideos espagueti vendidos:\n");
					scanf("%d", &espagueti);
					tiposFideosVendidos++;

					break;

				case 'T':

					printf("\nIngrese la cantidad de unidades de fideos tallarin vendidos:\n");
					scanf("%d", &tallarin);
					tiposFideosVendidos++;

					break;

				case 'F':

					printf("\nIngrese la cantidad de unidades de fideos fusilli vendidos:\n");
					scanf("%d", &fusilli);
					tiposFideosVendidos++;

					break;
			}

			fflush(stdin);
			printf("\nSi se vendieron mas tipos de fideo ingrese SI, de lo contrario ingrese NO:\n");
			scanf("%s", opc);

		} while(strcmp(opc, "SI") == 0);

		printf("\nSeleccione que tipo de leche se vendio:\n");
		printf("ENT = Entera\tDES = Descremada\n");
		scanf("%s", opcLeche);

		if (strcmp(opcLeche, "ENT") == 0) {

			printf("\nIngrese la cantidad de unidades de leche entera vendidas:\n");
			scanf("%d", &lecheEnt);
			lecheMax = lecheEnt;
			flagLeche = 0;
			
		} else {

			printf("\nIngrese la cantidad de unidades de leche descremada vendidas:\n");
			scanf("%d", &lecheDes);
			lecheMax = lecheDes;
			flagLeche = 1;
			
		}
		
		printf("\nSi se vendieron mas tipos de leche ingrese SI, de lo contrario ingrese NO:\n");
		scanf("%s", opc);

		if (strcmp(opc,"SI") == 0) {

			if (flagLeche == 1) {

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
			
		} else if (lecheEnt == lecheDes){
			
			strcpy(lecheMaxTipo, "iguales");
		
		} else {
		
			if(lecheMax == lecheEnt) {
			
				strcpy(lecheMaxTipo, "Entera");
			
			} else {
			
				strcpy(lecheMaxTipo, "Descremada");
			
			}
		}
		
		subtotalSemanal += calculoTotal(precioHarina, harina);
		subtotalSemanal += calculoTotal(precioEspagueti, espagueti);
		subtotalSemanal += calculoTotal(precioTallarin, tallarin);
		subtotalSemanal += calculoTotal(precioFusilli, fusilli);
		subtotalSemanal += calculoTotal(precioLecheEnt, lecheEnt);
		subtotalSemanal += calculoTotal(precioLecheDes, lecheDes);
		
		gastoReposicion = (subtotalSemanal * 0.8);
		
		totalSemanal = subtotalSemanal - gastoReposicion;
		
		if(i == 1) {
			
			semanaMax = i;
			totalSemanaMax = totalSemanal;
			
		} else if(totalSemanaMax < totalSemanal){
			
			semanaMax = i;
			totalSemanaMax = totalSemanal;
			
		}
		
		totalMensual += totalSemanal;

		informeSemanal(subtotalSemanal, gastoReposicion, totalSemanal, lecheMaxTipo, lecheMax, tiposFideosVendidos);
		
		system("pause");

	}
	
	informeMensual(totalMensual, semanaMax, totalSemanaMax);

	system("pause");

}

float calculoTotal(float precio, int cantidad){
	
	float total;
	
	total = precio * cantidad;
	
	return total;	
	
}

void informeSemanal(float subtotal, float gasto, float total, char maxTipo[], int maxCant, int tipoVendido){
	system("cls");
	
	printf("\t\tInforme semanal\n\n");
	
	printf("El total semanal previo a reposicion fue: \t$%.2f\nEl gasto de reposicion fue: \t\t\t$%.2f\n", subtotal, gasto);
	printf("El total semanal luego de reponer es: \t\t$%.2f\n", total);
	
	printf("\n*-----------------------------------------------------------------------*\n");
	
	if(strcmp(maxTipo,"ninguna") == 0){
		
		printf("Esta semana no hubo ventas de leche.\n");
	
	} else if (strcmp(maxTipo,"iguales") == 0){
		
		printf("Esta semana se vendieron cantidades iguales de tipos de leche.\n");
	
	} else {
		
		printf("El tipo de leche mas vendido fue: \t\t%s\nCon un total de %d unidades vendidas.\n", maxTipo, maxCant);
	
	}
	
	printf("\n*-----------------------------------------------------------------------*\n");
	
	printf("Esta semana se vendieron %d tipos de fideos.\n\n", tipoVendido);
		
}

void informeMensual(float totalFinal, int maxSemana, float mejorSemana){
	system("cls");
	
	printf("\t\tInforme mensual\n\n");
	
	printf("El total mensual fue: \t$%.2f\n", totalFinal);
	
	printf("\n*-----------------------------------------------------------------------*\n");
	
	printf("La semana con mayores ingresos fue la ");
	
	switch(maxSemana){
		
		case 1:
			printf("primera semana.\n");
		break;
		
		case 2:
			printf("segunda semana.\n");
		break;
		
		case 3:
			printf("tercera semana.\n");
		break;
		
		case 4:
			printf("cuarta semana.\n");
		break;
		
	}
	
	printf("Con unos ingresos registrados de: \t$%.2f\n", mejorSemana);
	
}
