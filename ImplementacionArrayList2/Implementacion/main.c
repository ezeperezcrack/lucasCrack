#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"



int main()
{
    FILE *f = NULL;
    ArrayList *listaDeClientes = al_newArrayList();
    Cliente *datos;
    Cliente *auxiliar;
    ArrayList *datos2;

    char seguir='s';
    int opcion=0, aux,i;
    int idcont;

    idcont = Apertura(listaDeClientes, f);
    system("pause");

    while(seguir=='s')
    {
        system("cls");
        printf("Actual: %d - RS: %d\n", al_len(listaDeClientes), listaDeClientes->reservedSize);
        opcion = menu("1-Alta cliente\n2-Modificar datos del cliente\n3-Baja del cliente\n4-Nuevo alquiler\n5-Fin del alquiler\n6-Listar\n7-Salir\n\n","Error ingrese nuevamente una opcion entre 1 y 7: ");

        switch(opcion)
        {
            case 1:
                datos = cliente_new();
                altaCliente(datos, idcont);
                aux = al_add(listaDeClientes, datos);
                if(aux == 0)
                {
                    idcont++;
                }
                break;
            case 2:
                printf("Ingrese un id");
                scanf("%d",&aux);
                Modificar(listaDeClientes, aux);
                system("pause");
                break;
           case 3:
                printf("Ingrese un id");
                scanf("%d",&aux);
                Borrar(listaDeClientes, aux);
                system("pause");
                break;
            case 4:
                al_sort(listaDeClientes,&cliente_compareName,0);
                break;
            case 5:
                datos2 = al_clone(listaDeClientes);
                Lista(datos2);
                break;
            case 6:
                Lista(listaDeClientes);

                break;
            case 7:
                Cerrar(listaDeClientes,f,idcont);
                seguir='n';
                break;
        }
    }
    return 0;
}

