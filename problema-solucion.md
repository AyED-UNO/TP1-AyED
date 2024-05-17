# Problema

Se desea efectuar un programa para controlar el stock de productos y la ganancia de un almacén semana a semana hasta el final del mes.

## Solución

El stock máximo de cada cosa es el siguiente (va en función ganancia/reposición):
Harina:  300 unidades.
Espagueti: 100 unidades.
Tallarín:  100 unidades.
Fusilli: 100 unidades.
Leche entera: 100 unidades.
Leche descremada: 100 unidades.
Al inicio del mes los stocks están la máximo.

Al principio del programa se ingresan los precios de cada producto.
Luego por semana se ingresan:
Ventas de harina(entero)
Tipo de fideo vendidos (carácter ‘s’ = espagueti, ‘t’ = tallarín, ‘f’ = fusilli)
Ventas de fideos(entero)
Tipo de leche vendido (cadena de carácter “ENT” = entera, “DES” = descremada)
Ventas de leche(entero)
1 El programa pregunta cuantas harinas se vendieron
2 Qué tipo de fideo se vendió a través de un carácter (‘s’ = espagueti, ‘t’ = tallarín, ‘f’ = fusilli)
3 El programa pregunta cuantos fideos de ese tipo se vendieron
4 Pregunta si se vendieron de otro tipo (‘SI’ – si ‘NO’ – no). Si se vendieron otros pregunta otra vez 2
5 Qué tipo de leche se vendió a través de una cadena de caracteres (“ENT” = entera, “DES” = descremada)
6 El programa pregunta cuantas leches de ese tipo se vendieron
7 Pregunta si se vendieron del otro tipo (‘SI’ – si ‘NO’ – no) si se vendieron otros compara lo que se entró en 5 como falsedad, y pregunta de nuevo 6.
Al final del ingreso semanal el programa muestra la cantidad de ventas y calcula la ganancia total.
Luego se pregunta si se desea reponer el stock. En caso afirmativo se hace un pedido de reposición, para lo que se compara el máximo de stock con las ventas y se pide la cantidad faltante. Cada producto tiene una rebaja de %20 en su precio de venta, así que se descuenta de las ganancias lo que se gaste en reabastecimiento.
El cálculo de la ganancia y el de reabastecimiento se hacen con una función que recibe como parámetros la cantidad de ventas por cada producto y que tipo de operación es y devuelve un float.
El informe final semanal es una función void que recibe la ganancia total y el gasto en reposición.
Al finalizar 4 semanas (contador) el programa informa el total de ganancia mensual (acumulador), el stock al final del mes y la semana con más ganancias. Este informe puede o no ser también por otra función void.
