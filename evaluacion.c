//
// Created by pauli on 18/03/2019.
//

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "pila.h"

float convierte(char car)
{
    double nuevo=0;
    nuevo = (float) car - '0';
    return nuevo;
}

float evalua(float opd1, char sign, float opd2)
{
    float result=0.0;
    switch (sign)
    {
        case '+':
            result = opd1 + opd2;
            printf("\t Executes: %f + %f = %f\n\n",opd1,opd2,result);
            break;
        case '-':
            result = opd1 - opd2;
            printf("\t Executes: %f - %f = %f\n\n",opd1,opd2,result);
            break;
        case '*':
            result = opd1 * opd2;
            printf("\t Executes: %f * %f = %f\n\n",opd1,opd2,result);
            break;
        case '/':
            result = opd1 / opd2;
            printf("\t Executes: %f / %f = %f\n\n",opd1,opd2,result);
            break;
        case '^':
            result = (float) pow(opd1, opd2);
            printf("\t Executes: %f ^ %f = %f\n\n",opd1,opd2,result);
            break;
    }
    return result;
}

float evaluar(char expresion[])
{
    int i;
    float converted;
    union datos nuevo;
    union datos value;
    union datos symb;
    static union datos opnd1;
    static union datos opnd2;

    i = 0;
    while (expresion[i] != '\0')
    {
        symb.info1 = expresion[i];
        if (symb.info1 != '^' && symb.info1 != '*' && symb.info1 != '/' && symb.info1 != '+' && symb.info1 != '-'  && symb.info1 != '('  && symb.info1 != ')')
        {
            converted=convierte(symb.info1);
            symb.digit=converted;
            push(symb);
        }


        else
        {
            opnd2 = pop();
            opnd1 = pop();
            value.digit = evalua(opnd1.digit, symb.info1, opnd2.digit);
            push(value);

        }
        i++;
    }
    nuevo = pop();
    return nuevo.digit;
}