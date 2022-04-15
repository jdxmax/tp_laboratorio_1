/*
 * dataInOutValidateTP1.c
 *
 *  Created on: 14 abr 2022
 *      Author: Juan
 */
#include <stdio.h>
#include "funcionesImpresionPorPantallaTP1.h"
#include "dataInOutValidateTP1.h"

///validarOpcionMenuPrincipal: VALIDA QUE LA OPCION INGRESADA SE ENCUNETRE ENTRE 1 - 6. DE NO ENCONTRARSE MOSTRARA MENU Y PEDIRA NUEVAMENTE DATO
///parametro 1, int opcion, opcion ingresada por usuario
///parametro 2, float km, km del viaje
///parametro 3, float precioAA, precio del viaje
///parametro 4, float precioLatam, precio del viaje

int validarOpcionMenuPrincipal(int opcion, float km, float precioAA, float precioLatam){
    while(opcion<1 || opcion>6){
        printf("\n\nError en dato\n\n");
        mostrarMenuInicial( km,  precioAA,  precioLatam);
        opcion = recibirOpcionMenuPrincipal(km, precioAA, precioLatam);
    }
    return opcion;
}


///cargarKilometros: solicita al usuario que cargue los kilometros

float cargarKilometros(){
    float km;
    printf("\nIngrese los Kilometros del viaje: ");
    scanf("%f", &km);
    km = validarKilometros(km);
    limpiarPantalla();
    return km;
}


///validarKilometros: con los datos ingresados por el usuario el programa valida que sea un kilometraje valido
///parametro 1. float km, es el dato km a validar

float validarKilometros(float km){
    while(km<1){
        limpiarPantalla();
        printf("\n\nERROR EN DATO. REINGRESE.\n\n");
        km = cargarKilometros();
    }

    return km;
}


///recibirOpcionSubmenu: SCANEA LA OPCION DE SUBMENU INGRESADA POR EL USUARIO

int recibirOpcionSubmenu(){
    int opcion;
    printf("\nIngrese la opcion deseada: ");
    scanf("%d",&opcion);
    limpiarPantalla();
    opcion = validaropcionSubmenu(opcion);

    return opcion;
}


///validaropcionSubmenu: VALIDA LA OPCION INGRESADA, QUE SEA VALIDA. DE NO SERLO PEDIRA INGRESAR NUEVAMENTE.
///parametro 1. int opcion, ingresa el valor de la opcion a validar

int validaropcionSubmenu(int opcion){
    while(opcion<1 || opcion>2){
        printf("\n\nError en dato\n\n");
        mostrarSubmenuAereolineas();
        opcion = recibirOpcionSubmenu();
    }
    return opcion;
}


///cargarPrecio: INGRESA EL USUARIO EL VALOR DEL VIAJE

float cargarPrecio(){
    float precio;
    printf("\nIngrese el precio del Kilometros: ");
    scanf("%f",&precio);
    precio = validarPrecio(precio);
    limpiarPantalla();
    return precio;
}


///validarPrecio: VALIDA QUE EL PRECIO INGRESADO SEA VALIDO. DE SER INVALIDO VUELVE A PEDIR DATO.
///parametro 1. float precio, ingresa un precio a validar.

float validarPrecio(float precio){
    while(precio<1){
        limpiarPantalla();
        printf("\n\nERROR EN DATO. REINGRESE.\n\n");
        precio = cargarPrecio();
    }

    return precio;
}


///confirmacionSalida: SE LE SOLICITARA AL USUARIO SI REALMENTE QUIERE SALIR. RETORNANDO TRUE O FALSE. 1/0

int confirmacionSalida(){
    int continuar;
    printf("\nRealmente Desea Salir. \n\n0- SI \n1- NO\n\n");
    scanf("%d", &continuar);
    continuar = validaropcionSalida(continuar);
    limpiarPantalla();
    return continuar;
}


///validaropcionSalida: VALIDA QUE LA OPCION INGRESADA SEA VALIDA. SINO VUELVE A PEDIR QUE REINGRESE
///parametro 1. int opcion, ingrea el valor input por usuario

int validaropcionSalida(int opcion){
    while(opcion<0 || opcion>1){
        printf("\n\nError en dato\n\n");
        opcion = confirmacionSalida();
    }

    return opcion;
}
