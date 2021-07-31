//
// Created by pauli on 18/03/2019.
//

#include "pila.h"

int profundidad(char expresion[])
{
    int index;
    union datos symb;
    union datos temp;
    index = 0;
    while (expresion[index] != '\0')	//Recorre la expresión
    {
        symb.info1 = expresion[index];	//Guarda el caracter a comparar
        if (symb.info1 == '(' || symb.info1 == '{' || symb.info1 == '[')
            push(symb);
        if (symb.info1 == ')' || symb.info1 == '}' || symb.info1 == ']')
        {
            if (isEmpty())	//Para verificar que haya un paréntesis antes :)
                return 0;
            else
            {
                temp = pop();
                if ((temp.info1 == '(' && symb.info1 != ')') || (temp.info1 == '[' && symb.info1 != ']') || (temp.info1 == '{' && symb.info1 != '}')) //Si los simbolos no son del mismo tipo
                    return 0;
            }
        }
        index++;
    }
    if (!isEmpty()) //Verifica si faltó algun paréntesis por cerrar :)
        return 0;
    return 1;
}