/*
 * stack.c
 *
 *  Created on: Aug 8, 2023
 *      Author: PC
 */
#include "stack.h"

void createEmptyStack(ST_stack_t *stack)
{
    for (uint8_t i = 0; i < STACK_SIZE; i++)
    {
        stack->elements[i]=0;
    }

    stack->top=-1;
}

int8_t push(ST_stack_t *stack, uint8_t data)
{

    if (stack->top==(STACK_SIZE-1))
    {
        return -1;
    }
    else
    {
        stack->top++;
        stack->elements[stack->top]=data;
        return 0 ;
    }


}

int8_t pop(ST_stack_t *stack, uint8_t *data)
{
    if (stack->top==-1)
    {
        return -2;
    }
    else
    {
        *data=stack->elements[stack->top];
        stack->top--;
        return 0 ;
    }

}

int8_t printStack(ST_stack_t *stack)
{
    for (int8_t i = stack->top+1; i >0; i--)
    {
        printf("%d\n",stack->elements[i-1]);

    }
    isFull(stack);
    isEmpty(stack);
    return 0 ;
}

int8_t getStackTop(ST_stack_t *stack, uint8_t *topData)
{

    if (stack->top==-1)
    {
        *topData=0;
        printf("empty stack");
        return -2;
    }
    *topData=stack->elements[stack->top];
    printf("%d top \n",*topData);

    return 0 ;
}

int8_t isFull(ST_stack_t *stack)
{
    if (stack->top==(STACK_SIZE-1))
    {
        return -1;
    }
}

int8_t isEmpty(ST_stack_t *stack)
{
    if (stack->top==-1)
    {
        return -2;
    }
}
