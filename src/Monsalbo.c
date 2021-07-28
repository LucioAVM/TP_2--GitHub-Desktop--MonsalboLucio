/*
 * Monsalbo.c
 *
 *  Created on: 6 jul. 2021
 *      Author: Ususario
 */

#include "Monsalbo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getInt (char* mensaje, int* entero)
{
    printf(mensaje);
    scanf("%d", entero);
}

void getFloat (char* mensaje, float* flotante)
{
    printf(mensaje);
    scanf("%f", flotante);
}

void getString(char* mensaje, char* cadena)
{
    printf(mensaje);
    fflush(stdin);
    gets(cadena);
}

void getChar (char* mensaje, char* caracter)
{
    printf(mensaje);
    fflush(stdin);
    scanf("%c",caracter);
}

int mostrarMenu(void)
{
	int menu;

	printf("\n\n1. ALTA EMPLEADO\n"
			"2. MODIFICAR EMPLEADO\n"
			"3. DAR DE BAJA EMPLEADO\n"
			"4. LISTAR EMPLEADOS\n"
			"5. LISTAR EMPLEADOS ORDEANDOS POR APELLIDO Y SECTOR\n"
			"6. SALARIOS: LISTAR, TOTAL, PROMEDIO, SUPERIORES AL SALARIO PROMEDIO\n"
			"7. SALIR\n"
			"\n Ingrese la opcion que desea realizar: ");
	scanf("%d", &menu);

	return menu;
}
