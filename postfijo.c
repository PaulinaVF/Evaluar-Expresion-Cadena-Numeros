//
// Created by pauli on 18/03/2019.
//
#include "pila.h"
//OBTENER EL MODELO POSTFIJO DE LA EXPRESION
//Jerarquía de operadores
int prec(char op1, char op2)
{
    int jer1=0, jer2=0;
    switch (op1)
    {
        case '^':
            jer1 = 3;
            break;
        case '*':
            jer1 = 2;
            break;
        case '/':
            jer1 = 2;
            break;
        case '+':
            jer1 = 1;
            break;
        case '-':
            jer1 = 1;
            break;
        case '(':
            jer1 = 0;
            break;
        case ')':
            jer1 = 4;
            break;
    }
    switch (op2)
    {
        case '^':
            jer2 = 3;
            break;
        case '*':
            jer2 = 2;
            break;
        case '/':
            jer2 = 2;
            break;
        case '+':
            jer2 = 1;
            break;
        case '-':
            jer2 = 1;
            break;
        case '(':
            jer2 = 4;
            break;
        case ')':
            jer2 = 0;
            break;
    }

    if ((jer1 == 4 && jer2 == 4)|| (jer1 == 0 && jer2 == 0))
        return 0;
    else if (jer1 >= jer2)
        return 1;
    else
        return 0;
}

void postfijo(char expresion[])
{
    int i, j;
    char postf[50];
    union datos symb;
    union datos topsymb;
    union datos top;
    i = 0;
    j = 0;
    while (expresion[i] != '\0')
    {
        symb.info1 = expresion[i];
        if (symb.info1 != '^' && symb.info1 != '*' && symb.info1 != '/' && symb.info1 != '+' && symb.info1 != '-'  && symb.info1 != '('  && symb.info1 != ')')
        {
            postf[j] = symb.info1;
            j++;
            i++;
        }

        else
        {
            top = stackTop();
            while (!isEmpty() && prec(top.info1, symb.info1))
            {
                topsymb = pop();
                if (topsymb.info1 != '(' && topsymb.info1 != ')')
                {
                    postf[j] = topsymb.info1;
                    j++;
                }
            }
            if (isEmpty() || symb.info1 != ')')
                push(symb);
            else
                topsymb = pop();
            i++;
        }
    }
    while (!isEmpty())
    {
        topsymb = pop();
        if (topsymb.info1 != '(' && topsymb.info1 != ')')
        {
            postf[j] = topsymb.info1;
            j++;
        }
    }
    postf[j] = '\0';
    i = 0;
    while (postf[i] != '\0')
    {
        expresion[i] = postf[i];
        i++;
    }
    expresion[i] = '\0';
    i = 0;
    while (expresion[i] != '\0')
    {
        printf("%c", expresion[i]);
        i++;
    }
    printf("\n");
}
