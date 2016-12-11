#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"



int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* this)
{
    printf("[ID: %d] Nombre y apellido: %s %s", this->id, this->name, this->lastName);
}


Employee* employee_new(void)
{

   Employee* returnAux = malloc(sizeof(Employee));

    return returnAux;

}

void employee_delete(Employee* this)
{

}

int employee_setId(Employee* this, int id)
{
    int ret;
    this->id = id;

    if(this->id == id)
    {
        ret = 1;
    } else
        {
            ret = 0;
        }

    return ret;

}

int employee_getId(Employee* this)
{
    int id = this->id;
    return id;

}


