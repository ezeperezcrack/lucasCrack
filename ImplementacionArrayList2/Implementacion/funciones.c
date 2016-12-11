#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"


int menu(char mensaje[],char error[])
{
    int op,aux;
    printf("%s",mensaje);
    aux=scanf("%d",&op);
    fflush(stdin);
    while(aux==0 ||(op<1||op>7))
    {
        printf("%s",error);
        fflush(stdin);
        aux=scanf("%d",&op);
    }
    return op;
}
void altaCliente(Cliente *datos,int idcontador)
{
    int i=0,aux;
    char nombre[50], apellido[50], dni[10];
    if(datos != NULL)
    {
        datos->estado = 1;
        datos->id = idcontador;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);
                                            ///validar nombre
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(apellido);
                                            ///validar apellido
        printf("Ingrese dni: ");
        gets(dni);
        aux = atoi(dni);
        while(aux == 0 || aux < 10000000)
        {
            printf("Ingrese dni nuevamente: ");
            fflush(stdin);
            gets(dni);
            aux = atoi(dni);
        }
        for(i=0;i<1;i++)
        {
           nombre[i] = toupper(nombre[i]);
           apellido[i] = toupper(apellido[i]);
        }
        strcpy(datos->nombre,nombre);
        strcpy(datos->apellido,apellido);
        datos->dni = aux;

    }
}
Cliente* cliente_new(void)
{
    Cliente* returnAux = malloc(sizeof(Cliente));
    return returnAux;
}
int Apertura(ArrayList *listaDeC,FILE *f)
{
    int id;
    Cliente *aux;
    f = fopen("Personas.dat", "rb");
    if(f!=NULL)
    {
        fread(&id, sizeof(int), 1, f);
        while(!feof(f))
        {
            aux = (Cliente*)malloc(sizeof(Cliente));
            if(aux !=NULL)
            {
              if(fread(aux, sizeof(Cliente), 1, f)==1)
                listaDeC->add(listaDeC, aux);
            }
    }
    fclose(f);
    printf("Archivo levantado con exito\n\n");
    }
    else
    {
        printf("\n No existe el archivo %s.\n\n","./personas.dat");
        id=1;
    }
    return id;
}
void Modificar(ArrayList *listaDeC, int aux)
{
    Cliente *auxiliar;
    Cliente *datos;
    int i, flag=0;
    for(i=0;i<al_len(listaDeC);i++)
    {
        datos = al_get(listaDeC,i);
        if(datos->id == aux)
        {
            auxiliar = cliente_new();
            altaCliente(auxiliar, datos->id);
            if(al_set(listaDeC,al_indexOf(listaDeC,datos),auxiliar) == 0)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        printf("No existe empleado con ese id\n");
    }
}
void Borrar(ArrayList *listaDeC, int aux)
{
    Cliente *auxiliar;
    Cliente *datos;
    int i, flag=0;
    for(i=0;i<al_len(listaDeC);i++)
    {
        datos = al_get(listaDeC,i);
        if(datos->id == aux)
        {
            auxiliar = al_pop(listaDeC,al_indexOf(listaDeC,datos));
            printf("%s---%s---%d---%d---%d\n",auxiliar->apellido,auxiliar->nombre,auxiliar->dni,auxiliar->id,auxiliar->estado);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("No existe empleado con ese id\n");
    }
}
void Cerrar(ArrayList *listaDeC,FILE *f,int id)
{
    int cantidad,i;
    f = fopen("Personas.dat", "wb");
    if(f != NULL)
    {
        fwrite(&id, sizeof(int), 1, f);
        cantidad = listaDeC->len(listaDeC);
        for(i=0; i<cantidad; i++)
        {
            fwrite((Cliente*)listaDeC->get(listaDeC, i), sizeof(Cliente), 1, f);
        }
        fclose(f);
        printf("Archivo guardado con exito\n\n");
        system("pause");
    }
}
void Lista(ArrayList *listaDeC)
{
    Cliente *auxiliar;
    int i;
    for(i=0;i<al_len(listaDeC);i++)
    {
        auxiliar = al_get(listaDeC,i);
        printf("%d---%s---%s---%d\n",auxiliar->id,auxiliar->nombre,auxiliar->apellido,auxiliar->dni);
    }
    system("pause");
}
int cliente_compareName(Cliente* pEmployeeA,Cliente* pEmployeeB)
{
    int retorno;
    retorno=strcmp(pEmployeeA->nombre,pEmployeeB->nombre);
    return retorno;
}
