#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[3000];
    int puntaje;
    char linkImagen[3000];
}EMovie;

int menu();
int agregarPelicula(EMovie*);
int borrarPelicula(EMovie*);
int modificarPelicula(EMovie*);
void generarPagina(EMovie[],char[]);
int guardarEnArchivo(EMovie*);
int cargarDesdeArchivo(EMovie*);
int getChar(char[],int);
int getInt(int,char[],int,int,char[]);

#endif // FUNCIONES_H_INCLUDED
