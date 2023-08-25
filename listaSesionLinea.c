#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno{
    char *nombreCompleto;
    int creditos;
    int semestre;
};

struct Nodo{
    struct Alumno* alumno;
    struct nodo* siguientePtr;
};

typedef struct Alumno Alumno;
typedef Alumno* AlumnoPtr;
typedef struct Nodo Nodo;
typedef Nodo* NodoPtr;



//firmas de las funciones
AlumnoPtr crearAlumno(char*, int, int );
void imprimirAlumno(AlumnoPtr);
NodoPtr crearNodo(AlumnoPtr);
void insertarNodoOrdenadoCréditos(NodoPtr*, NodoPtr);
void imprimirLista(NodoPtr*);


int main(){
    
   
    return 0;
}

Alumno* crearAlumno(char* nombre, int creditos, int semestre){
    Alumno *nuevo;

    nuevo = (Alumno*)malloc(sizeof(Alumno));

    nuevo->nombreCompleto = strdup(nombre);
    nuevo->creditos = creditos;
    nuevo->semestre = semestre;

    return nuevo;
}


void imprimirAlumno(AlumnoPtr alumno){
    printf("Alumno: \n");
    printf("Nombre: %s", alumno->nombreCompleto);
    printf("Creditos: %d", alumno->creditos);
    printf("Semestre equivalente: %d", alumno->creditos);
}


NodoPtr crearNodo(AlumnoPtr datosAlumno){
    NodoPtr nuevo;

    nuevo = (NodoPtr)malloc(sizeof(Nodo));
    nuevo->alumno = datosAlumno;
    nuevo->siguientePtr = NULL;
}


void insertarNodoOrdenadoCréditos(NodoPtr *cabecera, NodoPtr nuevo){
    NodoPtr actual;
    NodoPtr anterior;

    actual = *cabecera;
    anterior = NULL;

    if(anterior == NULL) //La lista esta vacia, el nodo sera el primer elemento de la lista
    {
        *cabecera = nuevo;
    }
    else
    {
        //determinar el lugar en la lista 
        while(actual != NULL  &&  nuevo->alumno->creditos < actual->alumno->creditos)
        {
            anterior = actual;
            actual = actual->siguientePtr;
        }

        //insertar Nodo en orden
        if(anterior == NULL)//el nodo a insertar estara en la primera posicion de la lista
        {
            *cabecera = nuevo;
            nuevo->siguientePtr = actual; 
        }
        else
        {
            anterior->siguientePtr = nuevo;
            nuevo->siguientePtr = actual;
        }
    }
}


void imprimirLista(NodoPtr *cabecera){
    NodoPtr actual = *cabecera;

    if(*cabecera == NULL){
        printf("La lista esta vacia.\n");
    }
    else
    {
        while(actual != NULL)
        {
            imprimirAlumno(actual->alumno);
            actual = actual->siguientePtr;
        }
    }
}