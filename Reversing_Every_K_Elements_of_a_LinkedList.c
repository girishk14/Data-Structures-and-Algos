/*
Program to reverse every K elements of a linked list

@Author  :  Girish

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int info;
    struct node *next;
}node;


node *getnode()
{

    node *temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}


node* insert(node* start, int a)
{
    node*trav;
    node * temp = getnode();
    temp->info = a;

    if(start==NULL)
    {
    start = temp;
    }


    else
    {
        trav = start;
        while(trav->next!=NULL)

        {
            trav=trav->next;
        }

        trav->next = temp;

    }
    return start;
}

void display(node *first)
{
    printf("\n\nDisplaying list . . .\n");
    for(first;first!=NULL;first=first->next)
    printf("%d-> ",first->info);

}

node *krev(node*first,int k);


int main()
{   int a;

    node * first = NULL;
    int k;
    printf("\n\nEnter the information for the nodes. -1 when done ");

    while(1)
    {

        scanf("%d",&a);

        if(a==-1)
        break;

        first = insert(first, a);
    }

    display(first);
    first = krev(first,3);

    //display(first);
}

node *krev(node *first, int k)
{
    int flag =0;

    node *prevfirst;
    node *check;
    node *trav,*prev,*temp;
    node *subfirst;
    int i,j;
    prev = NULL;
    trav = first;
    prevfirst=subfirst = trav;
    for(i=0;i<k;++i)
    {   //printf("\n%d",first->info);
        //1 2 3 4 5 6 7 8 9
        temp = first->next;
        first->next = prev;

        prev = first;

        if(i==k-1) break;
        first = temp;
    }



    while(1)
    {   subfirst = trav = temp;

        //check = trav;
// 3 2 1 4 5 6 7 8 9
       for(i=0;i<k;++i)
        {
            temp = trav->next;
            trav->next = prev;

            prev = trav;
            trav = temp;

            if(trav==NULL)
            {
                flag = 1;
                break;
            }
        }
    //printf("\n\nPrevfirst %d -> Subfirst %d\n\n",prevfirst->info, prev->info);
    if(flag==1)
    break;
        prevfirst->next = prev;
        prevfirst = subfirst;
    }

    trav = first;


        for(i=0;i<9;++i)
        {

        printf(" Bitch please8%d ->",trav->info);
        trav = trav->info;
        }
    return first;
}
