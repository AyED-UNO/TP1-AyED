Algoritmo main
	Definir precioHarina, precioEspagueti, precioTallarin, precioFusilli, precioLecheEnt, precioLecheDes, gastoReposicion, subtotalSemanal, totalSemanal, totalMensual, totalSemanaMax Como Real
	Definir harina, espagueti, tallarin, fusilli, lecheEnt, lecheDes, tiposFideosVendidos, semanaMax, lecheMax, i, flagLeche Como Entero
	Definir tipoFideo, opc, opcLeche, LecheMaxTipo Como Cadena
	Escribir 'Bienvenido'
	Escribir 'Por favor, ingrese los precios de los productos.'
	Escribir 'Harina:'
	Leer precioHarina
	Escribir 'Espagueti:'
	Leer precioEspagueti
	Escribir 'Tallarin:'
	Leer precioTallarin
	Escribir 'Fusilli:'
	Leer precioFusilli
	Escribir 'Leche Entera:'
	Leer precioLecheEnt
	Escribir 'Leche Descremada:'
	Leer precioLecheDes
	Para i<-1 Hasta 5 Con Paso 1 Hacer
		harina <- 0
		espagueti <- 0
		tallarin <- 0
		fusilli <- 0
		lecheEnt <- 0
		lecheDes <- 0
		subtotalSemanal <- 0
		totalSemanal <- 0
		tiposFideosVendidos <- 0
		Escribir 'Semana %d', i
		Escribir 'Ingrese la cantidad de unidades de harina vendidas: '
		Leer harina
		Repetir
			Escribir 'Seleccione que tipo de fideo se vendio:'
			Escribir 'E = Espagueti    T = Tallarin    F = Fusilli    N = Sin ventas'
			Leer tipoFideo
			Según tipoFideo Hacer
				E:
					Escribir 'Ingrese la cantidad de unidades de fideos espagueti vendidos:'
					Leer espagueti
					tiposFideosVendidos <- tiposFideosVendidos+1
				T:
					Escribir 'Ingrese la cantidad de unidades de fideos tallarin vendidos:'
					Leer tallarin
					tiposFideosVendidos <- tiposFideosVendidos+1
				F:
					Escribir 'Ingrese la cantidad de fideos fusillo vendidos: '
					Leer fusilli
					tiposFideosVendidos <- tiposFideosVendidos+1
			FinSegún
			Escribir 'Si se vendieron mas tipos de fideos ingrese SI, de lo contrario ingrese NO:'
			Leer opc
		Hasta Que opc=='NO'
		Escribir 'Seleccione que tipo de leche se vendio:'
		Escribir 'ENT = Entera    DES = Descremada'
		Si opcLeche=='ENT' Entonces
			Escribir 'Ingrese la cantidad de unidades de leche entera vendidas:'
			Leer lecheEnt
			lecheMax <- lecheEnt
			flagLeche <- 0
		SiNo
			Escribir 'Ingrese la cantidad de unidades de leche descremada vendidas:'
			Leer lecheDes
			lecheMax <- lecheDes
			flagLeche <- 1
		FinSi
		Escribir 'Si se vendieron mas tipos de leche ingrese SI, de lo contrario ingrese NO:'
		Leer opc
		Si opc=='SI' Entonces
			Si flagLeche==1 Entonces
				Escribir 'Ingrese la cantidad de unidades de leche entera vendidas:'
				Leer lecheEnt
				Si lecheMax<lecheEnt Entonces
					lecheMax <- lecheEnt
				FinSi
			SiNo
				Escribir 'Ingrese la cantidad de unidades de leche descremada vendidas:'
				Leer lecheDes
				Si lecheMax<lecheDes Entonces
					lecheMax <- lecheDes
				FinSi
			FinSi
		FinSi
		Si lecheMax==0 Entonces
			LecheMaxTipo <- 'nunguna'
		SiNo
			Si lecheEnt==lecheDes Entonces
				LecheMaxTipo <- 'iguales'
			SiNo
				Si lecheMax==lecheEnt Entonces
					LecheMaxTipo <- 'Entera'
				SiNo
					LecheMaxTipo <- 'Descremada'
				FinSi
			FinSi
		FinSi
		subtotalSemanal <- subtotalSemanal+calculoTotal(precioHarina,harina)
		subtotalSemanal <- subtotalSemanal+calculoTotal(precioEspagueti,espagueti)
		subtotalSemanal <- subtotalSemanal+calculoTotal(precioTallarin,tallarin)
		subtotalSemanal <- subtotalSemanal+calculoTotal(precioFusilli,fusilli)
		subtotalSemanal <- subtotalSemanal+calculoTotal(precioLecheEnt,lecheEnt)
		subtotalSemanal <- subtotalSemanal+calculoTotal(precioLecheDes,lecheDes)
		gastoReposicion <- subtotalSemanal*0.8
		totalSemanal <- subtotalSemanal-gastoReposicion
		Si i==1 Entonces
			semanaMax <- i
			totalSemanaMax <- totalSemanal
		SiNo
			Si totalSemanaMax<totalSemanal Entonces
				semanaMax <- i
				totalSemanaMax <- totalSemanal
			FinSi
		FinSi
		totalMensual <- totalMensual+totalSemanal
		informeSemanal(subtotalSemanal,gastoReposicion,totalSemanal,LecheMaxTipo,lecheMax,tiposFideosVendidos)
	FinPara
	informeMensual(totalMensual,semanaMax,totalSemanaMax)
FinAlgoritmo

Función total <- calculoTotal(precio,cantidad)
	total <- precio*cantidad
FinFunción

Función informeSemanal(subtotal,gasto,total,maxTipo,maxCant,tipoVendido)
	Escribir 'Informe semanal'
	Escribir 'El total semanal previo a reposicion fue:', subtotal
	Escribir 'El gasto de reposicion fue:', gasto
	Escribir 'El total semanal luego de reponer es: ', total
	Escribir '*-----------------------------------------------------------------------*'
	Si maxTipo = "ninguna" Entonces
		Escribir 'Esta semana no hubo ventas de leche.'
	SiNo
		Si maxTipo = "iguales" Entonces
			Escribir 'esta semana se vendieron cantidades iguales de tipos de leche.'
		SiNo
			Escribir 'El tipo de leche mas vendido fue: ', maxTipo
			Escribir 'Unidades vendidas: ', maxCant
		FinSi
	FinSi
	Escribir '*-----------------------------------------------------------------------*'
	Escribir 'Tipos de fideos vendidos esta semana: ', tipovendido
FinFunción

Función informeMensual(totalFinal,maxSemana,mejorSemana)
	Escribir 'Informe mensual'
	Escribir 'El total mensual fue: $', totalFinal
	Escribir '*-----------------------------------------------------------------------*'
	Escribir 'La semana con mayores ingresos fue la '
	Según maxSemana Hacer
		1:
			Escribir 'primera semana.'
		2:
			Escribir 'segunda semana.'
		3:
			Escribir 'tercera semana.'
		4:
			Escribir 'cuarta semana.'
	FinSegún
	Escribir 'Con unos ingresos registrados de: $', mejorSemana
FinFunción

Función descuento <- desReb(prVen,falta,opci)
	ganBase <- prVen*falta
	Si opci=='S' Entonces
		preCom <- prVen*100/120
		des <- falta*preCom
		Escribir 'Faltante: ', falta, ' Unidades.'
		Escribir 'Costo rebastecimiento: $ ', des
	SiNo
		des <- 0
	FinSi
	descuento <- ganBase-des
FinFunción
