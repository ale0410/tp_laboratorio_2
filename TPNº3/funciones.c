#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define A 4

/** \brief Elige una de las cinco opciones y la retorna
 *
 * \return Retorna la opcion
 *
 */

int menu()
{
    int c;
	system("cls");
	printf("MENU\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Generar pagina web\n5- Salir\n");
	printf("Elija una opcion: ");
	fflush(stdin);
	scanf("%d", &c);

	return c;
}

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *movie)
{
    int flag = 0;
    int ret = 0;


    if(movie != NULL)
    {
       if(flag==0)
       {
	         printf("\nIngrese el titulo de la pelicula: ");
             fflush(stdin);
             gets(movie->titulo);
             while(getChar(movie->titulo,50) == 1)
             {
                   printf("\nError. Reingrese el titulo de la pelicula: ");
                   fflush(stdin);
                   gets(movie->titulo);
             }
             printf("\nIngrese el genero de la pelicula: ");
             fflush(stdin);
             gets(movie->genero);
             while(getChar(movie->genero,50) == 1)
             {
                    printf("\nError. Reingrese el genero de la pelicula: ");
                    fflush(stdin);
                    gets(movie->genero);
             }
             getInt(movie->duracion, "\nIngrese la duracion de la pelicula: ", 0, 240, "\nError. Reingrese la duracion de la pelicula: ");
             printf("\nIngrese la descripcion de la pelicula: ");
             fflush(stdin);
             gets(movie->descripcion);
             while(getChar(movie->descripcion,3000) == 1)
             {
                    printf("\nError. Reingrese la descripcion de la pelicula: ");
                    fflush(stdin);
                    gets(movie->descripcion);
             }
             getInt(movie->puntaje, "\nIngrese el puntaje de la pelicula: ", 1, 100, "\nError. Reingrese el puntaje de la pelicula: ");
             printf("\nIngrese el link imagen de la pelicula: ");
             fflush(stdin);
             gets(movie->linkImagen);
             while(getChar(movie->linkImagen,3000) == 1)
             {
                    printf("\nError. Reingrese el link imagen de la pelicula: ");
                    fflush(stdin);
                    gets(movie->linkImagen);
             }
             flag = 1;
             ret = 1;
       }
    }
    else
    {
       printf("\nNo se puede agregar pelicula\n");
    }

    return ret;
}

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *movie)
{
    int flag = 0;
    int ret = 0;
    char pelicula[50];

    if(movie != NULL)
    {
       printf("\nIngrese el titulo de la pelicula a borrar: ");
       fflush(stdin);
       gets(pelicula);
       while(getChar(pelicula,50) == 1)
       {
             printf("\nError. Reingrese el titulo de la pelicula a borrar: ");
             fflush(stdin);
             gets(pelicula);
       }

       if(flag == 0 && strcmp(pelicula,movie->titulo) == 0)
       {
          printf("\nLa pelicula ha sido borrada\n");
          ret = 1;
       }
       else
       {
          printf("\nNo se encuentra la pelicula\n");
       }
    }
    else
    {
        printf("\nNo se cargaron las peliculas\n");
    }

    return ret;
}


/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser modificada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int modificarPelicula(EMovie *movie)
{
    int flag = 0;
    int ret = 0;
    char pelicula[50];

    if(movie != NULL)
    {
       printf("\nIngrese el titulo de la pelicula a modificar: ");
       fflush(stdin);
       gets(pelicula);
       while(getChar(pelicula,50) == 1)
       {
             printf("\nError. Reingrese el titulo de la pelicula a modificar: ");
             fflush(stdin);
             gets(pelicula);
       }

       if(flag == 0 && strcmp(pelicula,movie->titulo) == 0)
       {
          printf("\nIngrese el genero de la pelicula: ");
          fflush(stdin);
          gets(movie->genero);
          while(getChar(movie->genero,50) == 1)
          {
                printf("\nError. Reingrese el genero de la pelicula: ");
                fflush(stdin);
                gets(movie->genero);
          }
          getInt(movie->duracion, "\nIngrese la duracion de la pelicula: ", 0, 240, "\nError. Reingrese la duracion de la pelicula: ");
          printf("\nIngrese la descripcion de la pelicula: ");
          fflush(stdin);
          gets(movie->descripcion);
          while(getChar(movie->descripcion,3000) == 1)
          {
                printf("\nError. Reingrese la descripcion de la pelicula: ");
                fflush(stdin);
                gets(movie->descripcion);
          }
          getInt(movie->puntaje, "\nIngrese el puntaje de la pelicula: ", 1, 100, "\nError. Reingrese el puntaje de la pelicula: ");
          printf("\nIngrese el link imagen de la pelicula: ");
          fflush(stdin);
          gets(movie->linkImagen);
          while(getChar(movie->linkImagen,3000) == 1)
          {
                printf("\nError. Reingrese el link imagen de la pelicula: ");
                fflush(stdin);
                gets(movie->linkImagen);
          }
          ret = 1;
       }
       else
       {
          printf("\nNo se encuentra la pelicula\n");
       }
    }
    else
    {
        printf("\nNo se cargaron las peliculas\n");
    }

    return ret;
}

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie *x, char nombre[])
{
     int i;

     FILE *f;

     char bloque1[3000];
     char bloque2[2048];
     char bloque3[3000];

     f=fopen("index.html", "w");

     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         while(!feof(f))
         {
             sprintf(bloque1, "%s\n", "<html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script></head><body><div class='container'><div class='row'>");

             for(i = 0; i < A; i++)
             {
                 sprintf(bloque2,"%s %s  %s %s  %s %d  %s %s  %s %d  %s %s","Titulo: ",x[i].titulo,"Género: ",x[i].genero,"Duración: ",x[i].duracion,"Descripcion: ",x[i].descripcion,"Puntaje:",x[i].puntaje,"Link imagen: ",x[i].linkImagen);
             }

             sprintf(bloque3, "%s\n", "</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");

             fprintf(f,"%s  %s  %s", bloque1, bloque2, bloque3);
         }
      }

      fclose(f);

      printf("Listado creado con exito\n");
      system("pause");
}

/** \brief Guarda y escribe el archivo en binario
 *
 * \param La estructura a trabajar
 * \return Retorna 1 si f devuelve NULL, o 0 en caso contrario
 *
 */

int guardarEnArchivo(EMovie * x)
{

	FILE *f;

		f=fopen("bin.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(x,sizeof(EMovie),A,f);

	fclose(f);

	return 0;
}
/** \brief Carga el archivo y lo lee como lectura o sino como escritura
 *
 * \param La estructura a trabajar
 * \return Retorna 1 si f devuelve NULL tanto en lectura como escritura, o 0 si no devuelve NULL ni en lectura ni en escritura
 *
 */

int cargarDesdeArchivo(EMovie *x)
{
	int flag = 0;
	FILE *f;

	f=fopen("bin.dat", "rb");
	if(f==NULL)
	{
		f= fopen("bin.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	   fread(x,sizeof(EMovie),A,f);
    }

	fclose(f);
	return 0;

}


/** \brief Devuelve un entero si supera el rango maximo
 *
 * \param La cadena a trabajar
 * \param El maximo rango
 * \return Retorna 1 si supera el rango maximo, o 0 en caso contrario
 *
 */

int getChar(char cad[], int max)
{
    if(strlen(cad) > max)
       return 1;
    else
       return 0;
}

/** \brief Imprime el mensaje y retorna el auxiliar
 *
 * \param El auxiliar
 * \param El mensaje
 * \param El minimo rango
 * \param El maximo rango
 * \param El mensaje de error
 * \return El auxiliar
 *
 */

int getInt(int auxiliar, char mensaje[], int min, int max, char mensajeError[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &auxiliar);

    while(!(auxiliar >= min && auxiliar <= max))
    {
          printf("%s", mensajeError);
          fflush(stdin);
          scanf("%d", &auxiliar);
    }

    return auxiliar;
}

