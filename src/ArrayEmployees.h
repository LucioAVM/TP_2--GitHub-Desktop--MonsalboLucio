/*
 * ArrayEmployees.h
 *
 *  Created on: 6 jul. 2021
 *      Author: Ususario
 */

#ifndef arrayemployees_H_
#define arrayemployees_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int    id;
	char   nombre[51];
	char   apellido[51];
	float  salario;
	int    sector;
	int    isEmpty;
}empleado;

int guardarUltimoID(char* path, int id);

int cargarUltimoID (char* path, char* id);


/**
 * @fn int darDeAltaEmpleado(empleado, int)
 * @brief
 *
 * @param list
 * @param TAM
 * @return
 */
void darDeAltaEmpleado(empleado list[], int TAM);

/**
 * @fn int pedirEmpleado(int, char[], char[], float*, int*)
 * @brief
 *
 * @param id
 * @param nombre
 * @param apellido
 * @param salario
 * @param sector
 * @return
 */
int pedirEmpleado(char nombre[], char apellido[],float *salario, int *sector);

/**
 * @fn void eGen_ObtenerID(int*)
 * @brief
 *
 * @param Gen_idIncremental
 */
void eGen_ObtenerID(int* Gen_idIncremental);

/**
 * @fn empleado modificarEmpleado(empleado*, int)
 * @brief
 *
 * @param list
 * @param TAM
 * @return
 */
void modificarEmpleado(empleado list[],int TAM);


/**
 * @fn int menu(void)
 * @brief muestra el menu y recibe la respuesta del usuario
 *
 * @return retorna el numero de opcion ingresado por el usuario
 */
int mostrarMenu(void);

/**
 * @fn int darDeBajaEmpleado(empleado, int)
 * @brief
 *
 * @param list
 * @param TAM
 * @return
 */
int darDeBajaEmpleado(empleado list,int TAM);

/**
 * @fn int empleado_ObtenerLibre(empleado, int)
 * @brief
 *
 * @param array
 * @param TAM
 * @return
 */
int empleado_ObtenerLibre(empleado array[], int TAM);

/**
 * @fn void ordenPorSalario(empleado, int)
 * @brief
 *
 * @param array
 * @param TAM
 * @return
 */
void ordenPorSalario(empleado list, int TAM);


/*......................................................................................................*/

/**
 * @fn int initempleados(empleado*, int)
 * @brief para indicar todas las posiciones del array que estan vacias,bandera(isEmpty) a TRUE
 *
 * @param list empleado* puntero hacia el array de empleados
 * @param TAM
 * @return (-1) en caso de error(longitud inválida o puntero nulo) - (0) todo ok
 */
int initempleados(empleado *list, int TAM);

/*......................................................................................................*/

/**
 * @fn int addempleado(empleado*, int, int, char[], char)
 * @brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
 * posición libre.
 *
 * @param list      empleado*
 * @param pos   int
 * @param id        int
 * @param nombre[]    char
 * @param apellido[] char
 * @param salario    float
 * @param sector    int
 * @return retorna (-1) [Longitud no válida o puntero NULL o sin espacio libre] (0) todo ok
 */

int addEmpleado(empleado list[], int pos, int id, char nombre[], char apellido[], float salario, int sector);

/*......................................................................................................*/

/**
 * @fn int findempleadoById(empleado, int, int)
 * @brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
 *
 * @param list empleado*
 * @param TAM int
 * @param id int
 * @return retorna el empleado index con la posicion o (-1) [Longitud no válida o NULL
 * puntero recibido o empleado no encontrado]
 */
int findempleadoById(empleado list[], int TAM, int id);

/*......................................................................................................*/

/**
 * @fn int removeempleado(empleado*, int, int)
 * @brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 *
 * @param list empleado*
 * @param TAM int
 * @param id int
 * @return retorna un int (-1) si Error [Longitud no válida o puntero NULO o si no puede
 * encontrar un empleado] - (0) si está bien
 */
void removeempleado(empleado list[],int TAM);

/*......................................................................................................*/

/**
 * @fn int sortempleados(empleado*, int, int)
 * @brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * @param list empleado*
 * @param TAM int
 * @param ordenar int [1] indica ARRIBA - [0] indica ABAJO
 * @return  int Devuelve (-1) si hay error [longitud no válida o puntero NULO] - (0) si está bien
 */
int sortEmpleados(empleado* list, int TAM, int ordenar);

/*......................................................................................................*/

/**
 * @fn int printEmpleados(empleado*, int)
 * @brief Imprime el array de empleados de forma encolumnada
 *
 * @param list empleado*
 * @param TAM int
 * @return int
 */
int printEmpleados(empleado* list, int TAM);

/*......................................................................................................*/
/**
 * @fn int agregarEmpleadoModificado(empleado[], int, char[], char[], float, int)
 * @brief
 *
 * @param list
 * @param pos
 * @param nombre
 * @param apellido
 * @param salario
 * @param sector
 */
int agregarEmpleadoModificado(empleado list[], int pos, char nombre[],char apellido[], float salario, int sector);

int empleado_len(empleado list[], int tam);

int mostrarEmpleados(empleado list[], int tam);

void mostrarUnEmpleado(empleado list[], int pos);

int ordenarEmpleados(empleado list[], int tam);

int ordenarEmpleadosPorApellido(empleado list[], int tam, int orden);

int ordenarEmpleadosPorSector(empleado list[], int tam, int orden);

void mostrarTotalYPromedioSalariosYEmpleadosSuperiorPromedio(empleado list[], int tam);

int empleadosSuperanSalarioPromedio(empleado list[], int tam, float salarioPromedio);


#endif /* arrayemployees_H_ */
