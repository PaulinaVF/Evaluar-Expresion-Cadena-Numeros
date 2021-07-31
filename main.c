#include <malloc.h> //Manejo de la memoria dinámica
#include <stdio.h> //Para I/O
#include <stdlib.h> //Para las rutinas de utilería
#include "pila.h"
#include "profundidad.c"
#include "postfijo.c"
#include "evaluacion.c"
/*
float evalua(float, char, float);
int profundidad(char ex[]);
float convierte(char);
float evaluar(char[]);
int prec(char, char);
void postfijo(char[]);
*/

int main()
{
    char exp[50];
    //Pedir expresión
    printf("Ingrese una expresion:\t");
    fflush(stdin);
    gets(exp);

    if (profundidad(exp))
    {
        printf("\n\tLa expresion es correcta\n\n\tPostfijo de la expresion:\n\n\t");
        postfijo(exp);
        printf("\n\tEl resultado de la expresion es %f\n\n", evaluar(exp));
    }
    else
        printf("\nLa expresion es incorrecta, no se puede evaluar\n\n");
    system("pause");
    return 0;
}