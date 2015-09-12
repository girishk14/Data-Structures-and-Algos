/*

This program takes input m and n, and deletes n nodes in a linked list after every m nodes

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

    node * temp = getnode();
    temp->info = a;

    if(start==NULL)
    {
    start = temp;
    }

    else
    {
    temp->next = start;
    start=temp;
    }

    return start;
}

void display(node *first)
{
    printf("\n\nDisplaying list . . .\n");
    for(first;first!=NULL;first=first->next)
    printf("%d-> ",first->info);

}


node* deletemn(node*,int,int);

int main()
{   int a;

    node * first = NULL;
    int m,n;
    printf("\n\nEnter the information for the nodes. -1 when done ");

    while(1)
    {

        scanf("%d",&a);

        if(a==-1)
        break;

        first = insert(first, a);
    }

    display(first);

    printf("\n\nEnter the values of m and n ");
    scanf("%d%d",&m,&n);

    first = deletemn(first,m,n);

    display(first);

    return 0;


}


node *deletemn(node*first, int m, int n)
{
    node *temp,*trav, *prev;
    int i,j;
    trav = first;

    while(trav!=NULL)
    {

        for(i=0;i<m;++i)
        {   prev = trav;
            trav = trav->next;

            if(!trav)
            return first;
        }
        // 1 2 3 4  5 6 7 8 9
        for(j=0;j<n;++j)
        {
            if(trav==NULL) return first;
            temp = trav;
            trav= trav->next;
            free(temp);
        }

        prev->next = trav;
    }

return first;

}
