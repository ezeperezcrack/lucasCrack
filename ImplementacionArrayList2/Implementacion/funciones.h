#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"



typedef struct {
    char nombre[50];
    char apellido[50];
    int dni;
    int estado;
    int id;
}Cliente;

int menu(char mensaje[],char error[]);
void altaCliente(Cliente *datos,int idcontador);
Cliente* employe_new(void);
int Apertura(ArrayList *listaDeC,FILE *f);
void Cerrar(ArrayList *listaDeC,FILE *f,int id);
void Modificar(ArrayList *listaDeC, int nAux);
void Borrar(ArrayList *listaDeC, int aux);
void Lista(ArrayList *listaDeC);
int cliente_compareName(Cliente* pEmployeeA,Cliente* pEmployeeB);
