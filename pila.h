//
// Created by pauli on 18/03/2019.
//

#ifndef BA3_EVALUA_EXPRESION_PILA_H
#define BA3_EVALUA_EXPRESION_PILA_H
#include <malloc.h>
#include <stdio.h> // I/O
#include <stdlib.h> //rutinas de utilería

//Prototipos de función
int isEmpty(void);
void push(union datos);
union datos pop(void);
union datos stackTop(void);
void imprimeLista(void);
union datos;
struct nodo;


//Definición del nodo
union datos
{
    float digit;
    char info1; //info - dato a preservar
};
struct nodo
{
    union datos info;
    struct nodo *sig;//sig - Siguiente nodo de información
};

struct nodo *raiz = NULL;//Es el "origen" de la lista ligada

void imprimeLista()
{
    struct nodo *recorre = raiz;

    printf("\n\tLISTA: \n\n");
    while (recorre != NULL)
    {
        printf("info = %f\n", recorre->info.digit);
        recorre = recorre->sig;
    }
    printf("\n\n");
}


void push(union datos dato)
{
    struct nodo *nuevo;
    struct nodo *tempo;
    nuevo = (struct nodo*)malloc(sizeof(struct nodo));
    tempo = raiz;

    raiz = nuevo;
    raiz->info = dato;
    raiz->sig = tempo;
    printf("\tPushed: %f \n\n",raiz->info.digit);
}

int isEmpty()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

union datos pop()
{
    union datos dato;
    if (!isEmpty())
    {
        struct nodo *elimina = raiz;
        dato = raiz->info;
        raiz = raiz->sig;
        free(elimina);
        printf("\tPopped: %f\n\n",dato.digit);
        return dato;
    }

    else
    {
        dato.digit = 0.0;
        return dato;
    }
}

union datos stackTop()
{
    union datos dat;
    dat.digit = 0;
    if (isEmpty())
        return dat;
    else
        return raiz->info;
}
#endif //BA3_EVALUA_EXPRESION_PILA_H
