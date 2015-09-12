/*
This program is a standard application of stacks, that is conversion between infix and postfix expressions

@Author : Girish

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char *post(char exp[]);
int isp(char);
int icp(char);

int main()
{

    char exp[200];
        char *postfix;
    printf("\n\nENter the expression ");
    scanf("%s",exp);

   // postfix = post(exp);
post(exp);
    //printf("\n\nThe Postfix String is :%s",postfix);
    return 0;
}


char *post(char exp[])
{
    char str[200];
    char stack[200];
    int i,tmp;
    char symb;
    int top = -1;
    int strctr = 0;

    for(i=0;i<strlen(exp);++i)
    {
        symb = exp[i];

        if(symb=='(')
           {

           //printf("LEFT PARA");
            stack[++top] = symb;
           }

        else if(isalpha(symb))
        {
         str[strctr++] =  symb;
         //printf("PUSHED SYMB");
        }

        else if(symb==')')
        {
            while(stack[top]!='(')
            str[strctr++] = stack[top--];
           // printf("RIGHT PARA");
            top--;
        }

        else
        {
            while((isp(stack[top]))>icp(symb))
            str[strctr++] = stack[top--];
            //printf("OOPA");
            stack[++top] = symb;
        }

    }

    while(top!=-1)
    str[strctr++]=stack[top--];
    str[strctr] = '\0';


    printf("\n\n%s",str);
}


int isp(char a)
{

    switch(a)
    {

        case '+':
        case '-': return 1;

        case '*':
        case '/':return 4;

        case '$': return 5;

        case '(': return 0;
    }
}


int icp(char a)
{

    switch(a)
    {

        case '+':
        case '-': return 2;

        case '*':
        case '/':return 3;

        case '$': return 6;


    }
}
