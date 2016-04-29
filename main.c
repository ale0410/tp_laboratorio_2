#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define A 20


int main()
{
    EPersona lista[A];

    int opcion=0;
    char seguir = 's';

    inicializar(lista,A);

    while(seguir == 's')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("\n: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(lista,A);
                break;
            case 2:
                borrarPersona(lista,A);
                break;
            case 3:
                ordenarArray(lista,A);
                break;
            case 4:
                imprimir_grafico(lista,A);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
