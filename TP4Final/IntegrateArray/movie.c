/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#define F 4


/** \brief Compara las peliculas por puntaje
 *
 * \param pMovieA
 * \param pMovieB
 * \return 0 si esta fuera de rango, 1 si A es mayor que B, y -1 si A es menor que B
 *
 */

int compareMovie(void* pMovieA,void* pMovieB)
{

    if(((EMovie*)pMovieA)->score > ((EMovie*)pMovieB)->score)
    {
        return 1;
    }
    if(((EMovie*)pMovieA)->score < ((EMovie*)pMovieB)->score)
    {
        return -1;
    }
    return 0;


}
/** \brief Imprime los datos de la pelicula
 *
 * \param EMovie
 *
 */

void printMovie(EMovie* m)
{
    printf("\nTitulo    Genero    Duracion    Puntaje    Descripcion    LinkImagen\n");
    printf("\n%s    \t%s    \t%d    \t%d    \t%s    \t%s    \n", m->title, m->genre, m->duration, m->score, m->description, m->linkImg);
}

/** \brief Set this movie the values recived as parameters
 *
 * \param title[]
 * \param genre[]
 * \param duration
 * \param score
 * \param description[]
 * \param linkImg[]
 * \param state
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
EMovie* newMovie(char title[], char genre[], int duration, int score, char description[], char linkImg[])
{
    EMovie* returnAux = NULL;
    EMovie* pMovie = malloc(sizeof(EMovie));

    if(pMovie != NULL)
    {
        strcpy(pMovie->title,title);
        strcpy(pMovie->genre,genre);
        pMovie->duration = duration;
        pMovie->score = score;
        strcpy(pMovie->description,description);
        strcpy(pMovie->linkImg,linkImg);
        pMovie->state = 0;
        returnAux = pMovie;
    }

    return returnAux;

}


int guardarEnArchivo(EMovie * m0, EMovie * m1, EMovie * m2, EMovie * m3)
{
	FILE *f;

		f=fopen("movie.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(m0,sizeof(EMovie),F,f);
	fwrite(m1,sizeof(EMovie),F,f);
	fwrite(m2,sizeof(EMovie),F,f);
	fwrite(m3,sizeof(EMovie),F,f);

	fclose(f);

	return 0;
}


int cargarDesdeArchivo(EMovie * m0, EMovie * m1, EMovie * m2, EMovie * m3)
{
	int flag = 0;
	FILE *f;

	f=fopen("data.bin", "rb");
	if(f==NULL)
	{
		f= fopen("data.bin", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	   fread(m0,sizeof(EMovie),F,f);
	   fread(m1,sizeof(EMovie),F,f);
	   fread(m2,sizeof(EMovie),F,f);
	   fread(m3,sizeof(EMovie),F,f);
    }

	fclose(f);
	return 0;

}



void crearTxt(EMovie *m0, EMovie *m1, EMovie *m2, EMovie *m3)
{
     FILE *f;
     f=fopen("index.html", "w");

     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         fprintf(f,"Listado de Peliculas\n\n\n");
         fprintf(f,"Titulo    Genero    Duracion    Puntaje    Descripcion    LinkImagen \n");

         fprintf(f,"%s\t\%s\t\%d\t\%d\t\%s\t\%s\n", m0->title, m0->genre, m0->duration, m0->score, m0->description, m0->linkImg);
         fprintf(f,"%s\t\%s\t\%d\t\%d\t\%s\t\%s\n", m1->title, m1->genre, m1->duration, m1->score, m1->description, m1->linkImg);
         fprintf(f,"%s\t\%s\t\%d\t\%d\t\%s\t\%s\n", m2->title, m2->genre, m2->duration, m2->score, m2->description, m2->linkImg);
         fprintf(f,"%s\t\%s\t\%d\t\%d\t\%s\t\%s\n", m3->title, m3->genre, m3->duration, m3->score, m3->description, m3->linkImg);
      }

      fclose(f);

      printf("Listado creado con exito\n");
      system("pause");
}
