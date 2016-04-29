
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

void inicializar(EPersona[], int);
void agregarPersona(EPersona[], int);
void borrarPersona(EPersona[], int);
void ordenarArray(EPersona[], int);
void imprimir_grafico(EPersona[], int);
int obtenerEspacioLibre(EPersona[]);


