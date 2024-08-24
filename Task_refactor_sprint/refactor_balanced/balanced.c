/*
 * balanced.c
 *
 *  Created on: Aug 8, 2023
 *      Author: PC
 */
#include "balanced.h"
int8_t isBalancedParanthethes(uint8_t *expression)
{
    ST_stack_t stack;
    createEmptyStack(&stack);
    int8_t top=0;
    int8_t status=-2;
//    int8_t flag=0;
    uint8_t i=0;

    for ( i = 0; i < 25; i++)
    {
        if (expression[i]=='{' || expression[i]=='(')
        {
            push(&stack,expression[i]);
            status=-1;
            continue;
        }
        if (expression[i]=='}' || expression[i]==')')
        {
           getStackTop(&stack,&top);
            if (((abs(expression[i]-top)) ==2) ||((abs(expression[i]-top))  ==1))
            {
                pop(&stack,&expression[i]);
                if (isEmpty(&stack)==-2)
                {
                   status=0;
                }
            }
            else
            {
                status=-1;
                break;
            }
        }
        else if(expression[i]=='[' || expression[i]=='<')
        {
            return -2;
        }
    }

    return status ;

}
