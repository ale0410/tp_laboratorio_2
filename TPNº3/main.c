#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    EMovie movies;

    char nombre[50];
    char seguir='s';
    char guardar= 's';

    if(cargarDesdeArchivo(&movies))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}

	system("pause");

	system("cls");

    while(seguir=='s')
    {

        switch(menu())
        {
            case 1:
                agregarPelicula(&movies);
                break;
            case 2:
                borrarPelicula(&movies);
                break;
            case 3:
                modificarPelicula(&movies);
                break;
            case 4:
                generarPagina(&movies,nombre);
                break;
            case 5:
                printf("\nGuardar cambios S/N ?: ");
				guardar = tolower(getche());

				if(guardar == 's')
				{
					if(guardarEnArchivo(&movies))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}
                seguir = 'n';
                break;
        }
    }

    return 0;
}
