#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>
// #include <time.h>
/*
 *
 *  Created on: Mar 27, 2023
 *      Author: youseif essam
 */
#define STACK_SIZE 10
typedef unsigned char uint8_t;
typedef char int8_t;


typedef struct stack { 
uint8_t elements[STACK_SIZE];
int8_t top
}ST_stack_t; // Type

void createEmptyStack(ST_stack_t *stack);
int8_t push(ST_stack_t *stack, uint8_t data);
int8_t pop(ST_stack_t *stack, uint8_t *data);
int8_t printStack(ST_stack_t *stack);
int8_t getStackTop(ST_stack_t *stack, uint8_t *topData);
int8_t isFull(ST_stack_t *stack);
int8_t isEmpty(ST_stack_t *stack);

int8_t isBalancedParanthethes(uint8_t *expression);

int test_push=0;
uint8_t baranth=0;
int8_t top_cursor=0;
uint8_t array_char[25]={0};
int main(int argc, char const *argv[])
{
    /*stack test*/
    // ST_stack_t p1;
    // createEmptyStack(&p1);
    // push(&p1,1);
    // push(&p1,2);
    // push(&p1,3);
    // push(&p1,4);
    // push(&p1,5);
    // printStack(&p1);
    // printf("\n");
    // pop(&p1,&p1.elements[p1.top]);
    // getStackTop(&p1,&top_cursor);
    // printStack(&p1);
    // printf("\n");
    // push(&p1,11);
    // push(&p1,22);
    // push(&p1,33);
    // push(&p1,44);
    // push(&p1,55);
    // push(&p1,66);
    // push(&p1,77);
    // getStackTop(&p1,&top_cursor);
    // printStack(&p1);
    // printf("\n");
    // pop(&p1,&p1.elements[p1.top]);
    // pop(&p1,&p1.elements[p1.top]);
    // pop(&p1,&p1.elements[p1.top]);
    // pop(&p1,&p1.elements[p1.top]);
    // getStackTop(&p1,&top_cursor);
    // printStack(&p1);
    // printf("\n");
    // pop(&p1,&p1.elements[p1.top]);
    // pop(&p1,&p1.elements[p1.top]);
    // pop(&p1,&p1.elements[p1.top]);
    // pop(&p1,&p1.elements[p1.top]);
    // pop(&p1,&p1.elements[p1.top]);
    // pop(&p1,&p1.elements[p1.top]);
    // pop(&p1,&p1.elements[p1.top]);
    // getStackTop(&p1,&top_cursor);
    // printStack(&p1);
    

    /*test cases*/

    printf("\nenter your expression");
    scanf("%s",&array_char);
    int check=isBalancedParanthethes(array_char);
    if (check==0)
    {
        printf("balancd");
    }
    else if (check==-1)
    {
        printf("not balancd");
    }
    else if(check==-2)
    {
        printf("neither");
    }
    return 0;
}

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

int8_t isBalancedParanthethes(uint8_t *expression)
{
    ST_stack_t stack;
    createEmptyStack(&stack);
    int8_t top=0;
    int8_t status=-2;
    int8_t flag=0;
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