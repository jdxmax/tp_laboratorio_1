/*
 * funcionesCalculosTP1.c
 *
 *  Created on: 14 abr 2022
 *      Author: JDXMAX
 */

#define BTC 4749852.74


///calcularPrecioTD: CALCULA EL PRECIO FINAL PAGANDO CON TARJETA DEBITO
///parametro 1. float precio; ingresa el precio a hacer descuento

float calcularPrecioTD(float precio){
    precio = precio*0.9;

    return precio;
}


///calcularPrecioTC: CALCULA EL PRECIO FINAL PAGANDO CON TARJETA CREDITO
///pprecio 1. float precio, calcula el precio final con recargo

float calcularPrecioTC(float precio){
    precio = precio*1.25;

    return precio;
}


///calcularPrecioBTC: CALCULA EL PRECIO SEGUN COTIZACION DEL BitCOIN
//parametro 1. float precio, calcula el final segun cotizacion bitcoin

float calcularPrecioBTC(float precio){
    precio = precio/BTC;

    return precio;
}


///calcularPrecioUnitario: CALCULA EL PRECIO QUE CUESTA 1 km DEL VIAJE
///parametro 1. float precio, ingresa el precio del valor del viaje
///parametro 2. float km, ingresa la cantidad de km que tiene el viaje

float calcularPrecioUnitario(float precio, float km){
    precio = precio/km;

    return precio;
}


///diferenciaPrecio: CALCULA LA DIFERENCIA ENTRE LOS PRECIOS DE VIAJES. PARA QUE EL RESULTADO NO DE NEGATIVO, VERIFICA EN LA FUNCION QUIEN ES EL MAYOR DESCONTANDO EL PRECIO MENOR
///parametro 1. float precioAA, ingresa el precio de viaje de la empresa AA
///parametro 2. float precioLatam, ingresa el precio de viaje de la empresa LATAM
float diferenciaPrecio(float precioAA, float precioLatam){
    float diferencia;
    if(precioAA>precioLatam){
        diferencia = precioAA - precioLatam;
    }else{
        diferencia = precioLatam - precioAA;
    }

    return diferencia;
}
