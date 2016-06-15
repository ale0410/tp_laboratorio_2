#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "ArrayList.h"

void loadMenu(void)
{
    system("cls");
    printf("________MENU__________\n");
    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n");
    printf("Ingrese una de las cinco opciones: ");
}

int addMovie(ArrayList* movie)
{
    FILE *fp;
    movie->state=0;
        printf("--------- ALTA DE PELICULA------------\n");
        fflush(stdin);
        /*Titulo*/
        printf("Ingrese el titulo de la pelicula:  ");
        gets(movie->title);
        /*Valido cant de caracteres*/
        while(!(strlen(movie->title) >= 1 && strlen(movie->title) <= 20))
        {
            system("cls");
            printf("\nEl titulo de la pelicula debe ser obligatorio y no tiene que superar los 20 caracteres");
            system("pause");
            printf("\nReingrese el titulo de la pelicula:  ");
            gets(movie->title);
        }
        /*Busco si el titulo ingresado existe*/
        system("cls");
        printf("\nIngrese el genero de la pelicula:  ");
        gets(movie->genre);
        while(!(strlen(movie->genre) <= 20))
        {
            system("cls");
            printf("\nEl genero de la pelicula debe ser obligatorio y no tiene que superar los 20 caracteres");
            getche();
            printf("\nReingrese el genero de la pelicula:  ");
            gets(movie->genre);
        }

        system("cls");
        printf("\nIngrese la duracion de la pelicula en minutos:  ");
        scanf("%d",&movie->duration);


        system("cls");
        fflush(stdin);
        printf("\nIngrese la descripcion de la pelicula:  ");
        gets(movie->description);
        while(!(strlen(movie->description) >= 1 && strlen(movie->description) <= 50))
        {
            system("cls");
            printf("\nError!!!...\nReingrese descripcion entre 1-50 caracteres: ");
            gets(movie->description);
        }

        system("cls");
        fflush(stdin);
        printf("\nIngrese puntaje de la pelicula del 1 al 10: ");
        scanf("%d",&movie->score);
        while(!(movie->score >= 1 && movie->score <= 10))
        {
            system("cls");
            printf("\nError!!!...\nEl puntaje debe ser entre 1 - 10.\n\nReingrese el puntaje: ");
            scanf("%d",&movie->score);
        }


        system("cls");
        fflush(stdin);
        printf("\nIngrese el link de la imagen de la pelicula :  ");
        gets(movie->linkImg);
        while(!(strlen(movie->linkImg) >= 1 && strlen(movie->linkImg) <= 50))
        {
            system("cls");
            printf("\nEl link de imagen debe ser obligatorio y no tiene que superar los 50 caracteres\n\nReingrese: ");
            gets(movie->linkImg);
        }

        movie->state=1;
        //Guardo la estructura en el archivo
        if((fp=fopen("dat.bin","ab+"))!=NULL)
        {
            fflush(stdin);
            fwrite(movie,sizeof(ArrayList),1,fp);
        }
        else
        {
            printf("\nError al cargar la pelicula");
            getche();
        }

        printf("\nPelicula guardada exitosamente.\n\nPresione una tecla para continuar...\n");
        fclose(fp);
        return 0;
}

int deleteMovie(ArrayList* movie)
{
    FILE *fp;
    char auxTitle[40];
    int find=0;

    printf("\nIngrese titulo de la pelicula que desea eliminar: ");
    fflush(stdin);
    strlwr(gets(auxTitle));


    if((fp=fopen("dat.bin","r+"))!=NULL)
    {
        while((fread(movie,sizeof(ArrayList),1,fp))!=0)
        {
           if(movie->state==1)
            {
                strlwr(movie->title);
                if(strcmp(movie->title,auxTitle)==0)
               {
                   fseek(fp,-sizeof(ArrayList),SEEK_CUR);
                   movie->state=0;
                   fwrite(movie,sizeof(ArrayList),1,fp);
                   find=1;
                   printf("\nPelicula borrada exitosamente\n.");
                   system("pause");
                   break;
               }
            }
        }

        if(find==0)
        {
            printf("No se encontro la pelicula solicitada.");
            return 0;
        }

    }
    else
    {
        printf("No se puedo abrir el archivo correctamente.");
        return 0;
    }

   fclose(fp);

    return 0;
}


int modifyMovie(ArrayList* movie)
{
    FILE *fp;
    char auxTitle[40];
    int find=0;

    printf("\nIngrese titulo de la pelicula que desea modificar: ");
    fflush(stdin);
    strlwr(gets(auxTitle));


    if((fp=fopen("dat.bin","r+"))!=NULL)
    {
        while((fread(movie,sizeof(ArrayList),1,fp))!=0)
        {
           if(movie->state==1)
            {
                strlwr(movie->title);
                if(strcmp(movie->title,auxTitle)==0)
               {
                   fseek(fp,-sizeof(ArrayList),SEEK_CUR);
                   printf("Ingrese el titulo de la nueva pelicula:  ");
                   gets(movie->title);
                   /*Valido cant de caracteres*/
                   while(!(strlen(movie->title) >= 1 && strlen(movie->title) <= 20))
                   {
                         system("cls");
                         printf("\nEl titulo de la pelicula debe ser obligatorio y no tiene que superar los 20 caracteres");
                         system("pause");
                         printf("\nReingrese el titulo de la nueva pelicula:  ");
                         gets(movie->title);
                   }
                   system("cls");
                   printf("\nIngrese el genero de la nueva pelicula:  ");
                   gets(movie->genre);
                   while(!(strlen(movie->genre) <= 20))
                   {
                         system("cls");
                         printf("\nEl genero de la pelicula debe ser obligatorio y no tiene que superar los 20 caracteres");
                         getche();
                         printf("\nReingrese el genero de la nueva pelicula:  ");
                         gets(movie->genre);
                   }

                   system("cls");
                   printf("\nIngrese la duracion de la nueva pelicula en minutos:  ");
                   scanf("%d",&movie->duration);


                   system("cls");
                   fflush(stdin);
                   printf("\nIngrese la descripcion de la nueva pelicula:  ");
                   gets(movie->description);
                   while(!(strlen(movie->description) >= 1 && strlen(movie->description) <= 50))
                   {
                         system("cls");
                         printf("\nError!!!...\nReingrese descripcion entre 1-50 caracteres: ");
                         gets(movie->description);
                   }

                   system("cls");
                   fflush(stdin);
                   printf("\nIngrese puntaje de la nueva pelicula del 1 al 10: ");
                   scanf("%d",&movie->score);
                   while(!(movie->score >= 1 && movie->score <= 10))
                   {
                         system("cls");
                         printf("\nError!!!...\nEl puntaje debe ser entre 1 - 10.\n\nReingrese el puntaje: ");
                         scanf("%d",&movie->score);
                   }


                   system("cls");
                   fflush(stdin);
                   printf("\nIngrese el link de la imagen de la nueva pelicula :  ");
                   gets(movie->linkImg);
                   while(!(strlen(movie->linkImg) >= 1 && strlen(movie->linkImg) <= 50))
                   {
                         system("cls");
                         printf("\nEl link de imagen debe ser obligatorio y no tiene que superar los 50 caracteres\n\nReingrese: ");
                         gets(movie->linkImg);
                   }
                   fwrite(movie,sizeof(ArrayList),1,fp);
                   find=1;
                   printf("\nPelicula modificada exitosamente\n.");
                   system("pause");
                   break;
               }
            }
        }

        if(find==0)
        {
            printf("No se encontro la pelicula solicitada.");
            return 0;
        }

    }
    else
    {
        printf("No se puedo abrir el archivo correctamente.");
        return 0;
    }

   fclose(fp);

    return 0;
}

int createWebPage(EMovie *movie)
{
    FILE *fp,*pAux;

    if((fp=fopen("dat.bin","rb"))!=NULL)
    {
        if((pAux=fopen("index.html","wb"))!=NULL)
        {
            fprintf(pAux,
            "<!DOCTYPE html>\n"
            "<html lang='en'>\n"
            "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <title>Lista peliculas</title>\n"
            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "</head>\n"
            "<body>\n"
            "    <div class='container'>\n"
            "        <div class='row'>\n");
            while((fread(movie,sizeof(ArrayList),1,fp))!=0)
            {

               if(movie->state==1)
               {
                    fprintf(pAux,
                    "<article class='col-md-4 article-intro'>\n"
                    "<a href='#'>\n"
                    "<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                    "</a>\n"
                    "<h3>\n"
                    "<a href='#'>%s</a>\n"
                    "</h3>\n"
                    "<ul>\n"
                    "<li>Genero :%s</li>\n"
                    "<li>Puntaje :%d</li>\n"
                    "<li>Duracion :%d minutos</li>\n"
                    "</ul>\n"
                    "<p>%s</p>\n"
                    " </article>\n",movie->linkImg,movie->title,movie->genre,movie->score,movie->duration,movie->description);
               }

            }

            fprintf(pAux,
            "</div>\n"
            "</div>\n"
            "<script src='js/jquery-1.11.3.min.js'></script>\n"
            "<script src='js/bootstrap.min.js'></script>\n"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
            "<script src='js/holder.min.js'></script>\n"
            "</body>\n"
            "</html>\n");
        }
        else
        {
            printf("Ocurrio un error al crear el archivo HTML.\n\nPulse una tecla para continuar");
            return 0;
        }
    }
    else
    {
        printf("Error al abrir el archivo");
        return 0;
    }

    printf("Listado creado exitosamente\n");
    system("PAUSE");

    fclose(fp);
    fclose(pAux);

    return 0;
}


