#include <stdlib.h>
#include <stdio.h>
#include <string.h>

float importe(float, int);
void informeSemanal(float, float, float, char[], int, int);
void informeMensual(float, int, float);

int main() {

    // Productos
    float preHar, preEspa, preTall, preFus, preLecEnt, preLecDes; // Precios
    int   venHar, venEspa, venTall, venFus, venLecEnt, venLecDes; // Ventas
    char tipoFideo, tipoLeche[3+1]; // Tipos

    // Maximos
	int semanaMax, lecheMax;
	float totalSemanaMax;
	char lecheMaxTipo[11];

    // Acumuladores
	float subTotSem, totSem, totalMensual, gastoRepo;

    // Contadores
	int conTipoFidVen;

	// Auxiliares
	int i, flagLeche, flagFideos = 0;
	char opc[2+1];

    // Inicializacion
    totalMensual = gastoRepo = 0;

	// Ingreso de los precios de los productos
	printf("\t\tBienvenido\nPor favor, ingrese los precios de los productos.\n\n");
    printf("Harina: ");
	scanf("%f", &preHar);
    printf("Espagueti: ");
	scanf("%f", &preEspa);
    printf("Tallarin: ");
	scanf("%f", &preTall);
    printf("Fusilli: ");
	scanf("%f", &preFus);
    printf("Leche Entera: ");
	scanf("%f", &preLecEnt);
    printf("Leche Descremada: ");
	scanf("%f", &preLecDes);
	printf("\n");
	system("pause");
	system("cls");

	// Ingreso de ventas semanal
	for( i = 1; i < 5 ; i++ ) {

		// Reseteo de valores
		venHar = venEspa = venTall = venFus = venLecEnt = venLecDes = subTotSem = totSem = conTipoFidVen = flagFideos = 0;

        // Ingreso Harina
        printf("\t\tSemana %d\n", i);
        printf("\nIngrese la cantidad de unidades de harina vendidas: ");
        scanf("%d", &venHar);
        
		printf("\n");
		system("pause");
		system("cls");

        // Ingreso de Fideos
		do {
			printf("Seleccione que tipo de fideo se vendio:\n");
			printf("\t[E] Espagueti\n");
            printf("\t[T] Tallarin\n");
            printf("\t[F] Fusilli\n");
            printf("\t[N] Sin ventas\n");
            printf("Opcion: ");
			fflush(stdin);
			scanf("%c", &tipoFideo);

			switch(tipoFideo) {
				case 'E':
					printf("\nIngrese cantidad de fideos ESPAGUETI vendidos: ");
					scanf("%d", &venEspa);
					conTipoFidVen++;
					break;
				case 'T':
					printf("\nIngrese cantidad de fideos TALLARIN vendidos: ");
					scanf("%d", &venTall);
					conTipoFidVen++;
					break;
                case 'F':
					printf("\nIngrese cantidad de fideos FUSILLI vendidos: ");
					scanf("%d", &venFus);
					conTipoFidVen++;
					break;
				case 'N':
					flagFideos = 1;
					strcpy(opc, "NO");
				break;
			}

            // DEV: Funcion Continuar(). Ingresa una opcion de SI/NO y devuelva si continua o no.
            if(flagFideos == 0){
            	printf("\nSeguir ingresando FIDEOS?\n");
            	printf("\t[SI] Si.\n");
            	printf("\t[NO] No.\n");
            	printf("Opcion: ");
				fflush(stdin);
				scanf("%s", opc);
				printf("\n");
			}

		} while(strcmp(opc, "SI") == 0);

		system("pause");
		system("cls");

        // Ingreso de Leche
        printf("Seleccione que tipo de leche se vendio:\n");
		printf("[ENT] Entera\n");
        printf("[DES] Descremada\n");
        printf("Opcion: ");
		fflush(stdin);
        scanf("%s", tipoLeche);

		if (strcmp(tipoLeche, "ENT") == 0) {
			printf("\nIngrese la cantidad de unidades de leche entera vendidas: ");
			scanf("%d", &venLecEnt);
			lecheMax = venLecEnt;
			flagLeche = 0;
		} else {
			printf("\nIngrese la cantidad de unidades de leche descremada vendidas: ");
			scanf("%d", &venLecDes);
			lecheMax = venLecDes;
			flagLeche = 1;
		}

		printf("\nSi se vendieron mas tipos de leche ingrese SI, de lo contrario ingrese NO: ");
		scanf("%s", opc);

		if (strcmp(opc,"SI") == 0) {
			if (flagLeche == 1) {
				printf("\nIngrese la cantidad de unidades de leche entera vendidas: ");
				scanf("%d", &venLecEnt);

				if (lecheMax < venLecEnt) {
					lecheMax = venLecEnt;
                }
			} else {
				printf("\nIngrese la cantidad de unidades de leche descremada vendidas: ");
				scanf("%d", &venLecDes);

				if (lecheMax < venLecDes) {
					lecheMax = venLecDes;
                }
			}
		}
		
		printf("\n");
		system("pause");
		system("cls");

		if(lecheMax == 0)
            strcpy(lecheMaxTipo, "ninguna");
		else if (venLecEnt == venLecDes)
            strcpy(lecheMaxTipo, "iguales");
        else if(lecheMax == venLecEnt)
            strcpy(lecheMaxTipo, "Entera");
        else
            strcpy(lecheMaxTipo, "Descremada");

        subTotSem += importe(preHar, venHar);
		subTotSem += importe(preEspa, venEspa);
		subTotSem += importe(preTall, venTall);
		subTotSem += importe(preFus, venFus);
		subTotSem += importe(preLecEnt, venLecEnt);
		subTotSem += importe(preLecDes, venLecDes);

        gastoRepo = subTotSem * 100/120;
        totSem = subTotSem - gastoRepo;

		if(i == 1) {
			semanaMax = i;
			totalSemanaMax = totSem;
		} else if(totalSemanaMax < totSem) {
			semanaMax = i;
			totalSemanaMax = totSem;
		}

		totalMensual += totSem;

		informeSemanal(subTotSem, gastoRepo, totSem, lecheMaxTipo, lecheMax, conTipoFidVen);

		printf("\n");
		system("pause");
		system("cls");
	}

	informeMensual(totalMensual, semanaMax, totalSemanaMax);
	printf("\n");
	system("pause");

	return 0;
}

float importe(float precio, int cantidad) {

	float total;

	total = precio * cantidad;

	return total;

}

void informeSemanal(float subtotal, float gasto, float total, char maxTipo[], int maxCant, int tipoVendido) {
	system("cls");
	printf("------------------------------------------------------------------------\n");
	printf("\t\tInforme SEMANAL\n");
	printf("------------------------------------------------------------------------\n");
	printf("Total semanal previo a reposicion: ......................... $%.2f\n", subtotal);
    printf("Costo de reposicion: ....................................... $%.2f\n", gasto);
	printf("Total semanal posterior a reposicion: ...................... $%.2f\n", total);
	printf("------------------------------------------------------------------------\n");
	printf("Ventas de Fideos\n");
	printf("------------------------------------------------------------------------\n");
    printf("Tipos diferentes: .......................................... %d\n", tipoVendido);
	printf("------------------------------------------------------------------------\n");
    printf("Tipo de Leche con mayor cantidad de ventas\n");
	printf("------------------------------------------------------------------------\n");
	if(strcmp(maxTipo,"ninguna") == 0)
		printf("No hubo ventas de leche.\n");
	else {
        if (strcmp(maxTipo,"iguales") == 0)
            printf("Misma cantidad de ventas de cada tipo de leche.\n");
        else
            printf("Tipo: ...................................................... %s\n", maxTipo);

        printf("Cantidad: .................................................. %d\n", maxCant);
    }
	printf("------------------------------------------------------------------------\n");
}

void informeMensual(float gananciaNeto, int maxSemana, float mejorSemana) {
	system("cls");
	printf("------------------------------------------------------------------------\n");
	printf("\t\tInforme MENSUAL\n");
	printf("------------------------------------------------------------------------\n");
	printf("Ganancia mensual neto: ..................................... $%.2f\n", gananciaNeto);
	printf("Mayor ingreso semanal: ..................................... $%.2f\n", mejorSemana);
	printf("Semana con mayor ingresos: ................................. ");

	switch(maxSemana) {
		case 1: printf("PRIMERA semana.\n"); break;
		case 2: printf("SEGUNDA semana.\n"); break;
		case 3:	printf("TERCERA semana.\n"); break;
		case 4: printf("CUARTA semana.\n"); break;
	}
	printf("------------------------------------------------------------------------\n");
}
