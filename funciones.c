#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"



/** \brief Inicializa el flag de estado
 *
 * \param La estructura con la que se trabaja
 * \param El largo del array
 *
 */

void inicializar(EPersona lista[], int largo)
{
    int i;

    for(i = 0; i < largo; i++)
    {
        lista[i].estado = 0;
    }
}
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[])
{
    int index = -1;
	int i;

	inicializar(lista,20);

	for(i = 0; i < 20; i++)
    {
        if(lista[i].estado==0)
        {
		   index=i;
		   break;
	    }
    }

	return index;
}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarDni(EPersona lista[], long int dni)
{
    int i;
    int ret;

    inicializar(lista,20);

    for(i = 0; i < 20; i++)
    {
        if(lista[i].estado == 0 && dni == lista[i].dni)
        {
            ret = 0;
        }
        else
        {
            ret = -1;
            lista[i].estado = 1;
        }
    }

    return ret;
}

/** \brief Pregunta si hay espacio y agrega a las personas
 *
 * \param La estructura con la que se va a trabajar
 * \param El tamaño del array
 *
 */

void agregarPersona(EPersona lista[], int largo)
{
    int index, i;

    index = obtenerEspacioLibre(lista);

    inicializar(lista,largo);

    if(index!=-1)
    {
       for(i = 0; i < largo; i++)
       {
           if(lista[i].estado == 0)
           {
              printf("\nIngrese el nombre: ");
              fflush(stdin);
              gets(lista[i].nombre);
              printf("\nIngrese la edad: ");
              fflush(stdin);
              scanf("%d", &lista[i].edad);
              printf("\nIngrese el dni: ");
              fflush(stdin);
              scanf("%ld", &lista[i].dni);
              lista[i].estado = 1;
           }
       }

    }
    else
	{
		printf("\nNo queda espacio");
	}
}

/** \brief Busca a la persona, pregunta si existe el dato y la borra
 *
 * \param La estructura con la que se va a trabajar
 * \param El tamaño del array
 *
 */

void borrarPersona(EPersona lista[], int largo)
{
    int flag=0;
    long int dni;

    dni = 0;

    printf("\nIngrese el dni a buscar: ");
    fflush(stdin);
    scanf("%ld", &dni);

    if(buscarDni(lista,dni) == 0 || flag == 0)
    {
       printf("\nLos datos de esa persona han sido borrados\n");
    }
    else
    {
       printf("\nDni inexistente\n");
       flag = 1;
    }


}



/** \brief Ordena el array por nombre y lo imprime
 *
 * \param La estructura con la que se va a trabajar
 * \param El tamaño del array
 *
 */

void ordenarArray(EPersona lista[], int largo)
{
    EPersona aux;

    int i, j;

    inicializar(lista,largo);

    for(i = 0; i < largo - 1; i++)
     for(j = i + 1; j < largo; j++)
     {
         if(lista[i].estado == 0 && lista[i].nombre > lista[j].nombre)
         {
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
            lista[i].estado = 1;
         }
     }

    printf("\nLista ordenada por nombre\n");
    printf("\nNombre    Edad    DNI\n");

    for(i = 0; i < largo; i++)
    {
        printf("\n%s    \t%d    \t%ld    \n", lista[i].nombre, lista[i].edad, lista[i].dni);
    }
}

/** \brief Imprime el grafico con los diferentes rangos de edades
 *
 * \param La estructura con la que se trabaja
 * \param El largo del array
 *
 */

void imprimir_grafico(EPersona lista[], int largo)
{
   int i, hasta18=0, de19a35=0, mayorDe35=0, flag=0, mayor;

   for(i = 0; i < largo; i++)
   {
       if(lista[i].edad <= 18)
       {
          hasta18++;
       }

       if(lista[i].edad >= 19 && lista[i].edad <= 35)
       {
          de19a35++;
       }

       if(lista[i].edad > 35)
       {
          mayorDe35++;
       }
   }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);


}
