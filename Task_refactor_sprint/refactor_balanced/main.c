/*
 * main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: PC
 */
#include "main.h"
int test_push=0;
uint8_t baranth=0;
int8_t top_cursor=0;
uint8_t array_char[25]={0};

int main(int argc, char const *argv[])
{
    /*stack test*/
//     ST_stack_t p1;
//     createEmptyStack(&p1);
//     push(&p1,1);
//     push(&p1,2);
//     push(&p1,3);
//     push(&p1,4);
//     push(&p1,5);
//     printStack(&p1);
//     printf("\n");
//     pop(&p1,&p1.elements[p1.top]);
//     getStackTop(&p1,&top_cursor);
//     printStack(&p1);
//     printf("\n");
//     push(&p1,11);
//     push(&p1,22);
//     push(&p1,33);
//     push(&p1,44);
//     push(&p1,55);
//     push(&p1,66);
//     push(&p1,77);
//     getStackTop(&p1,&top_cursor);
//     printStack(&p1);
//     printf("\n");
//     pop(&p1,&p1.elements[p1.top]);
//     pop(&p1,&p1.elements[p1.top]);
//     pop(&p1,&p1.elements[p1.top]);
//     pop(&p1,&p1.elements[p1.top]);
//     getStackTop(&p1,&top_cursor);
//     printStack(&p1);
//     printf("\n");
//     pop(&p1,&p1.elements[p1.top]);
//     pop(&p1,&p1.elements[p1.top]);
//     pop(&p1,&p1.elements[p1.top]);
//     pop(&p1,&p1.elements[p1.top]);
//     pop(&p1,&p1.elements[p1.top]);
//     pop(&p1,&p1.elements[p1.top]);
//     pop(&p1,&p1.elements[p1.top]);
//     getStackTop(&p1,&top_cursor);
//     printStack(&p1);


    /*test cases*/

    printf("\nenter your expression");
    fflush(stdout);
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
