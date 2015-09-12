/*

Program to implement a queue using two stacks

@Author  :  GirishKumar

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 10

void push(int[], int*top, int data);

int pop(int[], int*);


void display(int[],int[],int,int);

int main()
{

        int top1=-1, top2=-1, s1[size],s2[size];
        int ch, data;
        int temp;
        do
        {

            printf("\n\n1. Insert\n2. Delete\n3. Display\n4. Exit");
            scanf("%d",&ch);
            //scanf("%d",&ch);

            switch(ch)
            {

                case 1: printf("Enter data");
                scanf("%d",&data);
                push(s1,&top1, data);
                break;

                case 2: if(top2==-1&&top1!=-1)
                        {



                        while(top1!=-1)
                        {   //printf("%d ",top1);
                                temp = pop(s1,&top1);
                                push(s2,&top2,temp);
                        }
                        }

                        pop(s2,&top2);



                        break;

                case 3: display(s1,s2,top1,top2);
                break;

                case 4: exit(0);

            }
        }while(1);

}


void display(int s1[],int s2[], int top1, int top2)

{

    int i;
    while(top2!=-1)
    {
        printf("%d ",s2[top2]);
        top2--;
    }

    for(i=0;i<=top1;++i)
    printf(" %d",s1[i]);

}


void push(int s[], int *top, int data)
{

    s[++*top] = data;
}


int pop(int s[], int *top)
{
    int tmp;
    if(*top==-1)
    {
        printf("UNDERFLOW!");
        exit(0);
    }

    else
    {
        tmp = s[*top];
        --*top;
        return tmp;
    }
}
