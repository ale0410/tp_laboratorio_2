#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"

int main()
{
    ArrayList* movie;
    char follow='s';
    char option;
    while(follow=='s')
    {
        loadMenu();
        scanf("%s",&option);
        switch(option)
        {
            case '1':
                system("cls");
                addMovie(&movie);
                break;
            case '2':
                system("cls");
                deleteMovie(&movie);
                getche();
                break;
            case '3':
               system("cls");
               createWebPage(&movie);
               getche();
               break;
            case '4':
                follow = 'n';
                break;
            default:
                printf("\nError. Reingrese la opcion: ");
                system("pause");
                break;
        }
    }

    return 0;
}
