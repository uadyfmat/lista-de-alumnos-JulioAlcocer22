//Julio Alcocer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno{
    char *nombreCompleto;
    int creditos;
    int semestre;
};

struct nodo{
    struct Alumno* alumno;
    struct nodo* siguientePtr;
};

typedef struct Alumno Alumno;
typedef Alumno* AlumnoPtr;

typedef struct nodo Nodo;
typedef Nodo* NodoPtr;



//firmas de las funciones
AlumnoPtr crearAlumno(char*, int, int );
void imprimirAlumno(AlumnoPtr);
NodoPtr crearNodo(AlumnoPtr);
void insertarNodoOrdenadoCréditos(NodoPtr*, NodoPtr);
void imprimirLista(NodoPtr);


int main(){
    NodoPtr cabecera = NULL;

    AlumnoPtr alumno1, alumno2, alumno3, alumno4, alumno5;

    alumno1 = crearAlumno("Alcocer Herrera Julio Cesar", 20, 2);
    alumno2 = crearAlumno("Aguilar Perez Johan Ricardo", 30, 5);
    alumno3 = crearAlumno("Hernandez Quijano Mauricio", 50, 8);
    alumno4 = crearAlumno("Hernandez Quijano Alejandra", 51, 1);
    alumno5 = crearAlumno("Hanma Baki", 32, 4);

    printf("\n");

    insertarNodoOrdenadoCréditos(&cabecera, crearNodo(alumno1));
    insertarNodoOrdenadoCréditos(&cabecera, crearNodo(alumno2));
    insertarNodoOrdenadoCréditos(&cabecera, crearNodo(alumno3));
    insertarNodoOrdenadoCréditos(&cabecera, crearNodo(alumno4));
    insertarNodoOrdenadoCréditos(&cabecera, crearNodo(alumno5));

    printf("\n");

    imprimirLista(cabecera);
    
   
    return 0;
}

Alumno* crearAlumno(char* nombre, int creditos, int semestre){
    Alumno *nuevo;

    nuevo = (Alumno*)malloc(sizeof(Alumno));

    nuevo->nombreCompleto = strdup(nombre); //la funcion strdup se encarga de la asignacion de memoria dinamica
    nuevo->creditos = creditos;
    nuevo->semestre = semestre;

    printf("Se ha creado una estructura Alumunos en la direccion de memoria %p\n", &nuevo);

    return nuevo;
}


void imprimirAlumno(AlumnoPtr alumno){
    
    printf("Nombre: %s, ", alumno->nombreCompleto);
    printf("Creditos aprobados: %d, ", alumno->creditos);
    printf("Semestre equivalente: %d\n", alumno->semestre);
}


NodoPtr crearNodo(AlumnoPtr datosAlumno){
    NodoPtr nuevo;

    nuevo = (NodoPtr)malloc(sizeof(Nodo));
    nuevo->alumno = datosAlumno;
    nuevo->siguientePtr = NULL;
    
    printf("Se ha creado un nodo de la lista de Alumnos en la direccion %p\n", &nuevo);
    return nuevo;
}


void insertarNodoOrdenadoCréditos(NodoPtr *cabecera, NodoPtr nuevo){
    NodoPtr actual;
    NodoPtr anterior;

    actual = *cabecera;
    anterior = NULL;

    if(*cabecera == NULL) //La lista esta vacia, el nodo sera el primer elemento de la lista
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


void imprimirLista(NodoPtr cabecera){
    NodoPtr actual = cabecera;
  
    if(cabecera == NULL){
        printf("La lista esta vacia.\n");
    }
    else
    {
        while(actual!= NULL)
        {
            imprimirAlumno(actual->alumno);
            actual = actual->siguientePtr;
        }
    }
}