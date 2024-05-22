Algoritmo main
	Escribir 'ingrese precio de fideo tipo espagueti: '
	Leer preFidEspa
	Escribir 'ingrese precio de fideo tipo tallarin: '
	Leer preFidTalla
	Escribir 'ingrese precio de fideo tipo fusilli: '
	Leer preFidFusi
	Escribir 'ingrese precio de leche tipo entera: '
	Leer preLecEnt
	Escribir 'ingrese precio de leche tipo descremada: '
	Leer preLecDes
	Escribir 'ingrese precio de harina: '
	Leer preHarina
	Escribir 'ingrese stock de fideo tipo espagueti: '
	Leer stkFidEspa
	Escribir 'ingrese stock de fideo tipo tallarin: '
	Leer stkFidTalla
	Escribir 'ingrese stock de fideo tipo fusilli: '
	Leer stkFidFusi
	Escribir 'ingrese stock de leche tipo entera: '
	Leer stkLecEnt
	Escribir 'ingrese stock de leche tipo descremada: '
	Leer stkLecDes
	Escribir 'ingrese stock de harina: '
	Leer stkHarina
	Para i<-1 Hasta 4 Hacer
		Escribir 'ingrese ventas de fideo tipo espagueti: '
		Leer venFidEspa
		Escribir 'ingrese ventas de fideo tipo tallarin: '
		Leer venFidTalla
		Escribir 'ingrese ventas de fideo tipo fusilli: '
		Leer venFidFusi
		Escribir 'ingrese ventas de leche tipo entera: '
		Leer venLecEnt
		Escribir 'ingrese ventas de leche tipo descremada: '
		Leer venLecDes
		Escribir 'ingrese precio de harina: '
		Leer venHarina
		Si band==0 Entonces
			Si lecDes<lecEnt Entonces
				maxLex <- lecEnt
			SiNo
				maxLex <- lecDes
			FinSi
			band <- 1
		SiNo
			Si maxLec<lecDes Entonces
				maxLec <- lecDes
				maxLecTipo <- "DES"
			FinSi
			Si maxLec<lecEnt Entonces
				maxLex <- lecEnt
				maxLecTipo <- "ENT"
			FinSi
		FinSi
	FinPara
FinAlgoritmo

Funcion descuento <- desReb(prVen,falta,opci)
	ganBase <- prVen*falta
	Si opci=='S' Entonces
		preCom <- prVen*100/120
		des <- falta*preCom
		Escribir 'Faltante: ',falta,' Unidades.'
		Escribir 'Costo rebastecimiento: $ ',des
	SiNo
		des <- 0
	FinSi
	descuento <- ganBase-des
FinFuncion
