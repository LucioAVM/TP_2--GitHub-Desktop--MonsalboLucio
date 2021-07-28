/*
 ============================================================================
 Name        : TP2__MonsalboLucio.c
 Author      : Monsalbo Lucio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Monsalbo.h"

#define TAM 1000

int main(void)
{
	setbuf(stdout, NULL);
	int menu;

	//CREO ARRAY DE ESTRUCTURA
	empleado list[TAM];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	initempleados( list, TAM);


	do
	{
		menu = mostrarMenu();

		switch(menu)
		{
		case 1:
			darDeAltaEmpleado(list, TAM);
			break;

		case 2:
			modificarEmpleado(list , TAM);
			break;

		case 3:
			removeempleado( list, TAM);
			break;

		case 4:
			mostrarEmpleados(list,TAM);
			break;

		case 5:
			ordenarEmpleados(list, TAM);
			break;

		case 6:
			mostrarTotalYPromedioSalariosYEmpleadosSuperiorPromedio(list,TAM);
			break;

		case 7:
			printf( "\n           GRACIAS POR UTILIZAR ESTE PROGRAMA\n"
						"             PRODUCIDO POR Monsalbo lucio\n"
						"              EDITADO POR Lucio Monsalbo\n"
						"         BUILDEADO POR Alejandro Lucio Monsalbo\n"
						"        TESTEADO POR Valerio Alejandro Monsalbo\n"
						"        ENVIADO POR Monsalbo Lucio Alejandro Valerio\n"
						"   AGRADECIMIENTO ESPECIAL A Lucio Alejandro Valerio Monsalbo\n");
			break;
		}
	}while(menu != 7);


	return EXIT_SUCCESS;
}
