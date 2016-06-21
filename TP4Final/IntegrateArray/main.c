#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "movie.h"


void printArrayListMovie(ArrayList* lista)
{
  int i;
  for(i=0;i<lista->len(lista);i++)
  {
      EMovie* pAux = lista->get(lista,i);
      printf("\n%d ",i);
      printMovie(pAux);
  }
}

int main()
{
     // Genero personas para usar en el ArrayList
    EMovie* m0 = newMovie("Aprentice Witch", "Fantasia", 150, 9, "The argument is that Morgana want lib of the crystal", "Aprentice Witch");
    EMovie* m1 = newMovie("The Lord of the Rings 3", "Aventuras", 200, 9, "The culmination of nearly 10 years", "The Lord of the Rings 3");
    EMovie* m2 = newMovie("Gladiator", "Accion", 155, 8, "The film was released in the United States on May 5, 2000", "Gladiator");
    EMovie* m3 = newMovie("Harry Potter 4", "Fantasia", 157, 8, "The fourth movie in the Harry Potter", "Harry Potter 4");

    if(cargarDesdeArchivo(m0,m1,m2,m3))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}

	system("pause");


    printMovie(m0);
    printMovie(m1);
    printMovie(m2);
    printMovie(m3);
    //__________________________________________


    printf("\r\nCargo ArraList...\r\n");
    ArrayList* lista = al_newArrayList();
    lista->add(lista,m0);
    lista->add(lista,m1);
    lista->add(lista,m2);
    al_add(lista,m3); // forma no orientada a objetos
    printArrayListMovie(lista);

    printf("\r\nRemuevo index 2\r\n");
    lista->remove(lista,2);
    printArrayListMovie(lista);

    printf("\r\nContiene m0 ?\r\n");
    if(lista->contains(lista,m0))
        printf("SI");
    else
        printf("NO");

    printf("\r\nContiene m2 ?\r\n");
    if(lista->contains(lista,m2))
        printf("SI");
    else
        printf("NO");

    printf("\r\nAgrego m2 en la posicion 1\r\n");
    lista->set(lista,1,m2); // vuelvo a agregar p2
    printArrayListMovie(lista);


    printf("\r\nClonamos array\r\n");
    ArrayList* lista2 = lista->clone(lista);
    printf("Lista original:%p\r\n",lista);
    printArrayListMovie(lista);


    printf("Lista Clonada:%p\r\n",lista2);
    printArrayListMovie(lista2);

    lista2->sort(lista2, compareMovie,1);
    printf("Lista Clonada Ordenada por puntaje (UP):%p\r\n",lista2);
    printArrayListMovie(lista2);

    lista2->sort(lista2, compareMovie,0);
    printf("Lista Clonada Ordenada por puntaje (DOWN):%p\r\n",lista2);
    printArrayListMovie(lista);

    printf("\r\nlista clonada contiene lista?:");
    if(lista->containsAll(lista,lista2))
        printf("SI");
    else
        printf("NO");


    printf("\r\n\r\nPosicion de m2:");
    int index = lista->indexOf(lista,m2);
    printf("%d\r\n",index);
    printf("\r\nPosicion de m1:");
    index = lista->indexOf(lista,m1);
    printf("%d\r\n",index);


    printf("\r\n\r\nHacemos push de m1 en la posicion 1\r\n");
    lista->push(lista,1,m1);
    printArrayListMovie(lista);


    printf("\r\nObtenemos sub-lista de 1 a 2\r\n");
    ArrayList* subLista = lista->subList(lista,1,2);
    printArrayListMovie(subLista);


    printf("\r\n\r\nHacemos pop de m1 en la posicion 1\r\n");
    EMovie* p1Aux = lista->pop(lista,1);
    printf("Elemento pop(): %s\r\n",p1Aux->title);
    printArrayListMovie(lista);


    printf("\r\nClear array\r\n");
    lista->clear(lista);
    printArrayListMovie(lista);

    printf("\r\nEsta vacio?\r\n");
    if(lista->isEmpty(lista))
        printf("SI");
    else
        printf("NO");

    // Test expansion/contraccion del size
    printf("\r\n\r\nTest size\r\n");
    int j;
    for(j=0; j<1100; j++)
    {
      EMovie* pAux = malloc(sizeof(EMovie));
      sprintf(pAux->title,"Aprentice Witch %d",j);
      pAux->score=j;
      lista->add(lista,pAux);
    }
    printf("Cantidad de elementos:%d\r\n",lista->len(lista));

    for(j=0; j<1100; j++)
    {
      lista->pop(lista,0);
    }
    printf("Cantidad de elementos:%d\r\n",lista->len(lista));
    //printArrayListPersonas(lista);
    //____________________________________

    if(guardarEnArchivo(m0,m1,m2,m3))
    {
       printf("\nNo se pudo abrir el fichero\n");
    }
    else
    {
       printf("\nSe guardo la informacion con exito\n");
    }

    crearTxt(m0,m1,m2,m3);

    printf("\r\nLibero memoria y termino\r\n");
    free(m0);
    free(m1);
    free(m2);
    free(m3);
    lista->deleteArrayList(lista);
    lista2->deleteArrayList(lista2);

    system("PAUSE");
    return 0;
}
