Algoritmo main
	Definir preHar, preEspa, preTall, preFus, preLecEnt, preLecDes, gastoRepo, subtotSem, totSem, totalMensual, totalSemanaMax Como Real
	Definir venhar, venEspa, venTall, venFus, venLecEnt, venLecDes, conTipoFidVen, semanaMax, lecheMax, i, flagLeche, flagFideos Como Entero
	Definir tipoFideo, opc, tipoLeche, lecheMaxTipo Como Cadena
	Escribir 'Bienvenido'
	Escribir 'Por favor, ingrese los precios de los productos.'
	Escribir 'Harina:'
	Leer preHar
	Escribir 'Espagueti:'
	Leer preEspa
	Escribir 'Tallarin:'
	Leer preTall
	Escribir 'Fusilli:'
	Leer preFus
	Escribir 'Leche Entera:'
	Leer preLecEnt
	Escribir 'Leche Descremada:'
	Leer preLecDes
	Para i<-1 Hasta 4 Con Paso 1 Hacer
		venhar <- 0
		venEspa <- 0
		venTall <- 0
		venFus <- 0
		venLecEnt <- 0
		venLecDes <- 0
		subtotSem <- 0
		totSem <- 0
		conTipoFidVen <- 0
		flagFideos <- 0
		Escribir 'Semana ', i
		Escribir 'Ingrese la cantidad de unidades de harina vendidas: '
		Leer venHar
		Repetir
			Escribir 'Seleccione que tipo de fideo se vendio:'
			Escribir '[E] Espagueti'
			Escribir '[T] Tallarin'
			Escribir '[F] Fusilli'
			Escribir '[N] Sin ventas'
			Escribir 'Opcion: '
			Leer tipoFideo
			Según tipoFideo Hacer
				'E':
					Escribir 'Ingrese cantidad de fideos ESPAGUETI vendidos: '
					Leer venEspa
					conTipoFidVen <- conTipoFidVen+1
				'T':
					Escribir 'Ingrese cantidad de fideos TALLARIN vendidos: '
					Leer venTall
					conTipoFidVen <- conTipoFidVen+1
				'F':
					Escribir 'Ingrese cantidad de fideos FUSILLI vendidos: '
					Leer venFus
					conTipoFidVen <- conTipoFidVen+1
				'N':
					flagFideos <- 1
					opc <- 'NO'
			FinSegún
			Si flagFideos == 0 Entonces
				Escribir 'Seguir ingresando FIDEOS?'
				Escribir '[SI] Si.'
				Escribir '[NO] No.'
				Escribir 'Opcion: '
				Leer opc
			FinSi

		Hasta Que opc=='NO'
		Escribir 'Seleccione que tipo de leche se vendio:'
		Escribir 'ENT = Entera'
		Escribir 'DES = Descremada'
		Escribir 'Opcion: '
		Leer tipoLeche
		Si tipoLeche=='ENT' Entonces
			Escribir 'Ingrese la cantidad de unidades de leche entera vendidas:'
			Leer venLecEnt
			lecheMax <- venLecEnt
			flagLeche <- 0
		SiNo
			Escribir 'Ingrese la cantidad de unidades de leche descremada vendidas:'
			Leer venLecDes
			lecheMax <- venLecDes
			flagLeche <- 1
		FinSi
		Escribir 'Si se vendieron mas tipos de leche ingrese SI, de lo contrario ingrese NO:'
		Leer opc
		Si opc=='SI' Entonces
			Si flagLeche==1 Entonces
				Escribir 'Ingrese la cantidad de unidades de leche entera vendidas:'
				Leer venLecEnt
				Si lecheMax<venLecEnt Entonces
					lecheMax <- venLecEnt
				FinSi
			SiNo
				Escribir 'Ingrese la cantidad de unidades de leche descremada vendidas:'
				Leer venLecDes
				Si lecheMax<venLecDes Entonces
					lecheMax <- venLecDes
				FinSi
			FinSi
		FinSi
		Si lecheMax==0 Entonces
			lecheMaxTipo <- 'ninguna'
		SiNo
			Si venLecEnt==venLecDes Entonces
				lecheMaxTipo <- 'iguales'
			SiNo
				Si lecheMax==venLecEnt Entonces
					lecheMaxTipo <- 'Entera'
				SiNo
					lecheMaxTipo <- 'Descremada'
				FinSi
			FinSi
		FinSi
		subTotSem <- subTotSem+importe(preHar,venHar)
		subTotSem <- subTotSem+importe(preEspa, venEspa)
		subTotSem <- subTotSem+importe(preTall, venTall)
		subTotSem <- subTotSem+importe(preFus, venFus)
		subTotSem <- subTotSem+importe(preLecEnt, venLecEnt)
		subTotSem <- subTotSem+importe(preLecDes, venLecDes)
		gastoRepo <- subTotSem*100/120
		totSem <- subTotSem-gastoRepo

        Escribir "importe(preHar,venHar)", importe(preHar,venHar)
        Escribir "importe(preEspa, venEspa)", importe(preEspa, venEspa)
        Escribir "importe(preTall, venTall)", importe(preTall, venTall)
        Escribir "importe(preFus, venFus)", importe(preFus, venFus)
        Escribir "importe(preLecEnt, venLecEnt)", importe(preLecEnt, venLecEnt)
        Escribir "importe(preLecDes, venLecDes)", importe(preLecDes, venLecDes)
        Escribir "gastoRepo", gastoRepo
        Escribir "totSem", totSem

		Si i==1 Entonces
			semanaMax <- i
			totalSemanaMax <- totSem
		SiNo
			Si totalSemanaMax<totSem Entonces
				semanaMax <- i
				totalSemanaMax <- totSem
			FinSi
		FinSi
		totalMensual <- totalMensual+totSem
		informeSemanal(subTotSem, gastoRepo, totSem, lecheMaxTipo, lecheMax, conTipoFidVen)
	FinPara
	informeMensual(totalMensual,semanaMax,totalSemanaMax)
FinAlgoritmo

Función total <- importe(precio,cantidad)
	total <- precio*cantidad
FinFunción

Función informeSemanal(subtotal,gasto,total,maxTipo,maxCant,tipoVendido)
	Escribir '------------------------------------------------------------------------'
	Escribir 'Informe SEMANAL'
	Escribir '------------------------------------------------------------------------'
	Escribir 'Total semanal previo a reposicion: ......................... $', subtotal
	Escribir 'Costo de reposicion: ....................................... $', gasto
	Escribir 'Total semanal posterior a reposicion: ...................... $', total
	Escribir '------------------------------------------------------------------------'
	Escribir 'Ventas de Fideos'
	Escribir '------------------------------------------------------------------------'
	Escribir 'Tipos diferentes: .......................................... ', tipoVendido
	Escribir '------------------------------------------------------------------------'
	Escribir 'Tipo de Leche con mayor cantidad de ventas'
	Escribir '------------------------------------------------------------------------'
	Si maxTipo = "ninguna" Entonces
		Escribir 'No hubo ventas de leche.'
	SiNo
		Si maxTipo = "iguales" Entonces
			Escribir 'Misma cantidad de ventas de cada tipo de leche.'
		SiNo
			Escribir 'Tipo: ...................................................... ', maxTipo
			Escribir 'Cantidad: .................................................. ', maxCant
		FinSi
	FinSi
	Escribir '------------------------------------------------------------------------'
FinFunción

Función informeMensual(gananciaNeto,maxSemana,mejorSemana)
	Escribir '------------------------------------------------------------------------'
	Escribir 'Informe MENSUAL'
	Escribir '------------------------------------------------------------------------'
	Escribir 'Ganancia mensual neto: ..................................... $', gananciaNeto
	Escribir 'Mayor ingreso semanal: ..................................... $', mejorSemana
	Escribir 'Semana con mayor ingresos: ................................. '
	Escribir 'La semana con mayores ingresos fue la '
	Según maxSemana Hacer
		1:
			Escribir 'PRIMERA semana.'
		2:
			Escribir 'SEGUNDA semana.'
		3:
			Escribir 'TERCERA semana.'
		4:
			Escribir 'CUARTA semana.'
	FinSegún
	Escribir '------------------------------------------------------------------------'
FinFunción
