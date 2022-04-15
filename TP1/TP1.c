/*
 ============================================================================
 Name        : TP1.c
 Author      : Escobar Juan Ignacio
 Version     :
 Copyright   : DIVISION F
 Description : TRABAJO PRACTICO N 1
 ============================================================================
 */

#include <stdio.h>

#include "funcionesImpresionPorPantallaTP1.h"
#include "funcionesCalculosTP1.h"
#include "dataInOutValidateTP1.h"

int main()
{
	setbuf(stdout,NULL);

	/// DECLARACION DE TODAS LAS VARIABLES A UTILIZAR

    int opcion;
    int opcionSubmenu;

    /// DATOS BASICOS A INGRESAR POR USUARIO
    float km=0;
    float precioAA = 0;
    float precioLatam = 0;

    //costos AA
    float precioTdAA=0;
    float precioTcAA=0;
    float precioBtcAA=0;
    float precioAAUnitario=0;

    //costos LATAM
    float precioTdLatam=0;
    float precioTcLatam=0;
    float precioBtcLatam=0;
    float precioLatamUnitario=0;

    ///DIFERENCIAL PRECIO ENTRE AEREOLINEAS
    float precioDiferencia=0;


    int continuar = 1;

    ///EL USURIO INGRESA AL PROGRAMA, NO SALDRA DEL MISMO HASTA INVOCAR LA OPCION 6, DONDE VALIDARA SI REALMENTE QUIERA SALIR
    do{

    	///SE LE MOSTRARA EL MENU CON TODAS LAS OPCIONES DISPONIBLES
        mostrarMenuInicial(km, precioAA, precioLatam);
        ///SE LE INDICA QUE INGRESE OPCION Y SE VALIDA
        opcion = recibirOpcionMenuPrincipal(km, precioAA, precioLatam);
        ///LIMPIAMOS PANTALLA PARA SER ESTETICO Y ORDENADO
        limpiarPantalla();


        ///DENTRO DE UNA ESTRUCTURA DE SELECCION, HARA DIFERENTES FUNCIONES SEGUN LA OPCION ELEGIDA EN MENU PRINCIPAL
        switch(opcion){
            case 1:
            	///OPCION 1: DEBERA CARGAR LA CANTIDAD DE KILOMETROS QUE TIENE EL VIAJE
                km = cargarKilometros();
                break;
            case 2:
            	///OPCION 2: DEBERA CARGAR LOS VALORES DEL VIAJE SEGUN AEREOLINEA. SE ABRIRA UN SUB MENU PARA INDICAR QUE AEREOLINEA QUIERE CARGAR EL PRECIO
                mostrarSubmenuAereolineas();
                ///SUBMENU DEBERA ELEGIR ENTRE LATAM O AA. ELEGIR OPCION
                opcionSubmenu = recibirOpcionSubmenu();
                if(opcionSubmenu==1){
                	///OPCION 1: CARGAR EL PRECIO DEL VIAJE AA
                    precioAA = cargarPrecio();
                }else{
                	///OPCION 2: CARGAR EL PRECIO DEL VIAJE LATAM
                    precioLatam = cargarPrecio();
                }
                break;
            case 3:
            	///OPCION 3: DEBERA REALIZAR TODOS LOS CALCULOS DE VALORES DEL VIAJE. SOLO SI >> KM PRECIO AA y LATAM ESTAN CARGADOS
                if(km>0 && precioAA>0 && precioLatam>0){
                	///CALCULANDO COSTOS TARJETA CREDITO
                    precioTdAA = calcularPrecioTD(precioAA);
                    precioTdLatam = calcularPrecioTD(precioLatam);

                    ///CALCULANDO COSTOS TARJETA DEBITO
                    precioTcAA = calcularPrecioTC(precioAA);
                    precioTcLatam = calcularPrecioTC(precioLatam);

                    ///CALCULANDO COSTOS EN BTC
                    precioBtcAA = calcularPrecioBTC(precioAA);
                    precioBtcLatam = calcularPrecioBTC(precioLatam);

                    ///CALCULANDO COSTOS DE PRECIO POR 1KM
                    precioAAUnitario = calcularPrecioUnitario(precioAA, km);
                    precioLatamUnitario = calcularPrecioUnitario(precioLatam, km);

                    ///CALCULA LA DIFERENCIA DE PRECIO ENTRE LOS VALORES DEL VIAJE ENTRE AMBAS AEREOLINEAS
                    precioDiferencia = diferenciaPrecio(precioAA,precioLatam);

                    calcularTodosLosCostos();

                }else{
                	///SI FALTARON CARGAR VALORES BASICOS KM PRECIO AA y LATAM. ENTONCES NO HACE NADA.
                    noRealizarCalculos();
                }
                break;
            case 4:
            	///OPCION 4: MOSTRARA TODOS LOS PRECIOS EN TABLAS. SIEMPRE QUE SE HAYAN CALCULADO PREVIAMENTE LOS VALORES FINALES. SE TOMO COMO REFERENCIA QUE ESTE CALCULADO PRECIO UNITARIO
                if(precioAAUnitario>0){
                    printf("\nLatam:\n");
                    printf("\na) Precio con tarjeta de d�bito: %.2f", precioTdLatam);
                    printf("\nb) Precio con tarjeta de cr�dito: %.2f", precioTcLatam);
                    printf("\nc) Precio pagando con bitcoin : %f", precioBtcLatam);
                    printf("\nd) Precio unitario: %.2f", precioLatamUnitario);
                    printf("\n\nAerol�neas:\n");
                    printf("\na) Precio con tarjeta de d�bito: %.2f", precioTdAA);
                    printf("\nb) Precio con tarjeta de cr�dito: %.2f", precioTcAA);
                    printf("\nc) Precio pagando con bitcoin : %f", precioBtcAA);
                    printf("\nd) Precio unitario: %.2f", precioAAUnitario);
                    printf("\n\nLa diferencia de precio es : %.2f", precioDiferencia);
                    printf("\n\n\n\n");
                }else{
                	///SI NO SE CALCULARON LOS VALORES EN OPCION 3. ENTONCES NO HACE NADA. USANDO COMO REFERENCIA QUE NO SE OBTUVO PRECIO UNITARIO DE AA
                    noMostrarCalculos();
                }
                break;
            case 5:
            	///OPCION 5: SE CARGA FORZADAMENTE VALORES EN KM PRECIO AA y LATAM. LUEGO PROCEDE A REALIZAR TODOS LOS CALCULOS.
                km = 7090;
                precioLatam = 162965;
                precioAA = 159339;

                precioTdAA = calcularPrecioTD(precioAA);
				precioTdLatam = calcularPrecioTD(precioLatam);

				precioTcAA = calcularPrecioTC(precioAA);
				precioTcLatam = calcularPrecioTC(precioLatam);

				precioBtcAA = calcularPrecioBTC(precioAA);
				precioBtcLatam = calcularPrecioBTC(precioLatam);

				precioAAUnitario = calcularPrecioUnitario(precioAA, km);
				precioLatamUnitario = calcularPrecioUnitario(precioLatam, km);

				precioDiferencia = diferenciaPrecio(precioAA,precioLatam);

                break;
            case 6:
            	///OPCION 6: SE LE PREGUNTA AL USUARIO SI REALMENTE QUIERE SALIR. DE SER AFIRMATIVO FINALIZA EL PROGRAMA. DE SER NEGATIVO REITERA MENU PRINCIPAL
                continuar = confirmacionSalida();
                break;
        }

    }while(continuar);

    return 0;
}



