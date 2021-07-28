/*
 * ArrayEmployees.c
 *
 *  Created on: 6 jul. 2021
 *      Author: Ususario
 */

#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Monsalbo.h"

#define OCUPADO 1
#define LIBRE 0

void darDeAltaEmpleado(empleado list[], int TAM)
{
	int validacion;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int id;
	int libre;
	char idStr[5];

	libre = empleado_ObtenerLibre(list, TAM);
	if(libre != -1)
	{
		cargarUltimoID ( "ultimoId.csv", idStr);

		id = atoi(idStr);
		id++;

		guardarUltimoID("ultimoId.csv",id);

		getString("ingresar nombre del empleado: ", nombre);
		strlwr(nombre);
		nombre[0] = toupper(nombre[0]);

		getString("ingresar apellido del empleado: ", apellido);
		strlwr(apellido);
		apellido[0] = toupper(apellido[0]);

		getFloat("ingresar salario del empleado: ", &salario);

		getInt("ingrese sector del empleado: ", &sector);

		validacion = addEmpleado(list, libre, id, nombre, apellido, salario, sector);

		if(validacion != 0)
		{
			printf("\nERROR, no se pudo dar de alta correctamente  el empleado");
		}else{
			printf("\nse dio de alta correctamente el empleado");
		}
	}else{
		printf("\nno se encontro lugar libre en el sistema");
	}
}

int addEmpleado(empleado list[], int pos, int id, char nombre[], char apellido[],float salario, int sector)
{
	int retorno;
	int validacion;

	retorno = -1;

	if(list != NULL && pos > -1 && id > 0 && nombre != NULL && apellido !=NULL && salario > 0 && sector > 0)
	{
		empleado auxiliar;

		auxiliar.id = id;
		strcpy(auxiliar.nombre, nombre);
		strcpy(auxiliar.apellido, apellido);
		auxiliar.salario = salario;
		auxiliar.sector = sector;

		do
		{
			printf("\nesta seguro que quiere dar de alta el empleado ingresado?\n"
					"\n1- SI"
					"\n2- NO"
					"\ningrese opcion: ");
			scanf("%d", &validacion);
		}while(validacion != 1 && validacion != 2);

		if(validacion == 1)
		{
			list[pos].id = auxiliar.id;
			strcpy(list[pos].nombre, auxiliar.nombre);
			strcpy(list[pos].apellido, auxiliar.apellido);
			list[pos].salario = auxiliar.salario;
			list[pos].sector = auxiliar.sector;
			list[pos].isEmpty = OCUPADO;
			retorno = 0;
		}else{
			printf("\noperacion cancelada");
		}
	}
	return retorno;
}

int guardarUltimoID(char* path, int id)
{
	FILE* pFile;
	int retorno=0;

	pFile = fopen(path, "w");

	if(pFile != NULL)
	{
		fprintf(pFile,"%d", id);
		retorno=1;
	}

	fclose(pFile);

	return retorno;
}

int cargarUltimoID (char* path, char* id)
{
	int retorno=0;
	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%s", id);
		retorno=1;
	}

	fclose(pFile);

	return retorno;
}

int empleado_ObtenerLibre(empleado array[], int TAM)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == 0)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int initempleados(empleado* list, int TAM)
{
	int i;
	int retorno;

	retorno = -1;

	if (list != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			list[i].isEmpty = 0;
		}
		retorno = 0;
	}
	return retorno;
}

void modificarEmpleado(empleado list[],int TAM)
{
	int pos;
	int id;
	int validacion;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int largo;

	largo = empleado_len(list, TAM);
	if(largo > 0)
	{
		getInt("\ningrese el id del empleado a modificar: ", &id);

		pos = findempleadoById(list, TAM,  id);


		if(pos != -1)
		{
			puts("\nempleado encontrado: ");
	        puts("\nID ******** NOMBRE ******** APELLIDO ******** SALARIO ******** SECTOR");

			mostrarUnEmpleado( list, pos);

			strcpy(nombre,list[pos].nombre);
			strcpy(apellido,list[pos].apellido);
			salario = list[pos].salario;
			sector = list[pos].sector;

			getInt("\ndesea modificar el nombre del empleado?\n"
					"\n1 PARA SI"
					"\ncualquier otro numero para NO: ",&validacion);
			if(validacion == 1)
			{
				getString("\ningrese el nuevo nombre: ", nombre);
				strlwr(nombre);
				nombre[0] = toupper(nombre[0]);
			}


			getInt("\ndesea modificar el apelldio del empleado?\n"
					"\n1 PARA SI "
					"\ncualquier otro numero para NO: ",&validacion);
			if(validacion == 1)
			{
				getString("\ningrese el nuevo apelldio: ", apellido);
				strlwr(apellido);
				apellido[0] = toupper(apellido[0]);
			}


			getInt("\ndesea modificar el salario del empleado?\n"
					"\n1 PARA SI "
					"\ncualquier otro numero para NO: ",&validacion);
			if(validacion == 1)
			{
				getFloat("\ningrese el nuevo salario: ", &salario);
			}

			getInt("\ndesea modificar el sector del empleado?\n"
					"\n1 PARA SI"
					"\ncualquier otro numero para NO: ",&validacion);
			if(validacion == 1)
			{
				getInt("\ningrese el nuevo sector: ", &sector);
			}

			getInt("\nesta seguro que desea modificar el empleado?"
					"\n1 PARA SI "
					"\ncualquier otro numero para NO: ",&validacion);
			if(validacion == 1)
			{
				validacion = agregarEmpleadoModificado(list,  pos, nombre, apellido, salario, sector);
				if(validacion == 1)
				{
					puts("\nempleado modificado con exito");
				}
			}else{
				puts("\nopereacion cancelada");
			}
		}else{
			puts("\nno se encontro el empleado");
		}
	}else{
		puts("\nno hay empleados cargados para modificar");
	}
}

int findempleadoById(empleado list[], int TAM, int id)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL && TAM > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (list[i].id == id && list[i].isEmpty == OCUPADO)
			{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int agregarEmpleadoModificado(empleado list[], int pos, char nombre[],char apellido[], float salario, int sector)
{
	int retorno;

	retorno = -1;

	if(list != NULL && pos> -1 && nombre != NULL && apellido != NULL && salario > 0 && sector > 0)
	{
		strcpy(list[pos].nombre,nombre);
		strcpy(list[pos].apellido, apellido);
		list[pos].sector = sector;
		list[pos].salario = salario;
		retorno = 1;
	}
	return retorno;
}

int empleado_len(empleado list[], int tam)
{
	int i;
	int contador;

	contador = 0;

	for(i=0; i<tam; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			contador++;
		}
	}
	return contador;
}


int mostrarEmpleados(empleado list[], int tam)
{
    int i;
    int largo;
    int retorno;

    retorno = -1;

    largo = empleado_len(list, tam);

    if(largo > 0)
    {
        puts("\nEMPLEADOS: ");
        puts("\nID ******** NOMBRE ******** APELLIDO ******** SALARIO ******** SECTOR");
        for(i=0; i<tam; i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
                mostrarUnEmpleado(list, i);
                retorno = 1;
            }
        }
    }
    else
    {
        puts("\nNo hay empleados cargados para mostrar.");
        retorno = 0;
    }

    return retorno;
}

void mostrarUnEmpleado(empleado list[], int pos)
{
    printf("\n%d %16s %17s %16.2f %15d", list[pos].id,
    		list[pos].nombre,
			list[pos].apellido,
			list[pos].salario,
			list[pos].sector);
}

void removeempleado(empleado list[],int TAM)
{
	int pos;
	int id;
	int validacion;
	int largo;

	largo = empleado_len(list, TAM);
	if(largo > 0)
	{
		getInt("\ningrese el id del empleado a borrar: ", &id);

		pos = findempleadoById(list, TAM,  id);


		if(pos != -1)
		{
			puts("\nempleado encontrado: ");
	        puts("\nID ******** NOMBRE ******** APELLIDO ******** SALARIO ******** SECTOR");

			mostrarUnEmpleado( list, pos);

			getInt("\nesta seguro que desea dar de baja el empleado?"
					"\n1 PARA SI "
					"\ncualquier otro numero para NO: ",&validacion);
			if(validacion == 1)
			{
				list[pos].isEmpty = LIBRE;
				puts("\nempleado borrado con exito");
			}else{
				puts("\nopereacion cancelada");
			}
		}else{
			puts("\nno se encontro el empleado");
		}
	}else{
		puts("\nno hay empleados cargados para borrar");
	}
}

int ordenarEmpleados(empleado list[], int tam)
{
    int orden;
    int opcion;
    int retorno;
    int largo;

    retorno = -1;

    largo = empleado_len(list, tam);

    if(largo > 0)
    {
        getInt("\nComo desea ordenar la lista de empleados?"
               "\n1. Por apellido."
               "\n2. Por sector."
               "\nIngrese la opcion que desea realizar: ", &opcion);

        while(opcion > 2 || opcion < 1)
        {
            getInt("\nERROR: Opcion incorrecta"
                   "\nIngrese nuevamente como desea ordenar la lista de empleados?"
                   "\n1. Por apellido."
                   "\n2. Por sector."
                   "\nIngrese la opcion que desea realizar: ", &opcion);
        }

        switch(opcion)
        {
        case 1:
            getInt("\nIngrese el criterio con el que desea ordenar la lista."
                   "\n'1' para ascendente o '0' para descendente: "
                   "\nIngrese la opcion que desea realizar: ", &orden);
            while(orden > 1 || orden < 0)
            {
                getInt("\nERROR: El numero ingresado no es correcto, intente nuevamente."
                       "\n'1' para ascendente o '0' para descendente: "
                       "\nIngrese la opcion que desea realizar: ", &orden);
            }
            ordenarEmpleadosPorApellido(list, tam, orden);
            mostrarEmpleados(list, tam);
            retorno = 1;
            break;
        case 2:
            getInt("\nIngrese el criterio con el que desea ordenar la lista."
                   "\n'1' para ascendente o '0' para descendente: "
                   "\nIngrese la opcion que desea realizar: ", &orden);
            while(orden > 1 || orden < 0)
            {
                getInt("\nERROR: El numero ingresado no es correcto, intente nuevamente."
                       "\n'1' para ascendente o '0' para descendente: "
                       "\nIngrese la opcion que desea realizar: ", &orden);
            }
            ordenarEmpleadosPorSector(list, tam, orden);
            mostrarEmpleados(list, tam);
            retorno = 1;
            break;
        }
    }
    else
    {
        puts("\nERROR: No hay empleados cargados para mostrar la lista ordenada.");
    }

    return retorno;
}

int ordenarEmpleadosPorApellido(empleado list[], int tam, int orden)
{
    int i;
    int j;
    int retornoCmp;
    int retorno;
    empleado aux;

    retorno = -1;

    if(orden == 1)
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                retornoCmp = strcmp(list[i].apellido, list[j].apellido);
                if(retornoCmp == 1)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                    retorno = 1;
                }
            }
        }
    }
    else
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                retornoCmp = strcmp(list[i].apellido, list[j].apellido);
                if(retornoCmp == -1)
                {
                    aux = list[j];
                    list[j] = list[i];
                    list[i] = aux;
                    retorno = 1;
                }
            }
        }
    }

    return retorno;
}

int ordenarEmpleadosPorSector(empleado list[], int tam, int orden)
{
  int i;
  int j;
  int retorno;
  empleado aux;

  retorno = -1;
    if(orden == 1)
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(list[i].sector > list[j].sector)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                    retorno = 1;
                }
            }
        }
    }
    else
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(list[i].sector < list[j].sector)
                {
                    aux = list[j];
                    list[j] = list[i];
                    list[i] = aux;
                    retorno = 1;
                }
            }
        }
    }

    return retorno;
}

void mostrarTotalYPromedioSalariosYEmpleadosSuperiorPromedio(empleado list[], int tam)
{
    int i;
    int contadorSalarios;
    float sumaSalarios;
    float promedioSalarios;
    int empleadosSuperiorPromedio;
    int largo;

    contadorSalarios = 0;
    promedioSalarios = 0;
    sumaSalarios = 0;

    largo = empleado_len(list, tam);

    if(largo > 0)
    {
        for(i=0; i<tam; i++)
        {
            if(list[i].isEmpty == OCUPADO)
            {
                sumaSalarios = sumaSalarios + list[i].salario;
                contadorSalarios++;
            }
        }

        promedioSalarios = sumaSalarios / contadorSalarios;

        empleadosSuperiorPromedio = empleadosSuperanSalarioPromedio(list,  tam, promedioSalarios);

        puts("\nEmpleados cargados hasta el momento: ");
        mostrarEmpleados(list, tam);

        printf("\nEl total de los salarios es: %.2f", sumaSalarios);
        printf("\nEl promedio de los salarios es: %.2f", promedioSalarios);
        printf("\nLa cantidad de empleados que superan el salario promedio es: %d", empleadosSuperiorPromedio);

    }
    else
    {
        puts("\nNo hay empleados cargados para mostrar el promedio de salarios, total de salarios y la cantidad de empleados que lo superan.");
    }
}

int empleadosSuperanSalarioPromedio(empleado list[], int tam, float salarioPromedio)
{
    int i;
    int empleadosSuperiorPromedio;

    empleadosSuperiorPromedio = 0;

    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            if(list[i].salario > salarioPromedio)
            {
                empleadosSuperiorPromedio++;
            }
        }
    }

    return empleadosSuperiorPromedio;
}
