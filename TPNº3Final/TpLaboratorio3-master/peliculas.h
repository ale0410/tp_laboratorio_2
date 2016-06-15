typedef struct{
    char title[20];
    char genre[20];
    int duration;
    int score;
    char description[50];
    char linkImg[50];
    int state;
}EMovie;

/**
 *  Carga el menu al inciar iniciar el sistema
 *  @param
 *  @return
 */
void loadMenu(void);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return
 */
int addMovie(EMovie *movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return
 */
int deleteMovie(EMovie *movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param
 */
int createWebPage(EMovie *movie);




