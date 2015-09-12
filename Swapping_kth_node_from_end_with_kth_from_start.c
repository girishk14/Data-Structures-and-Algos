/*

Given a singly link list and a number 'K', swap the Kth node from the start with the Kth node from the last. Check all the edge cases.
Sample Input: 1->2->3->4->5->6->7->8 and K = 3
Sample Output : 1->2->6->4->5->3->7->8
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

node *swaps(node*first,int k);


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

    printf("\n\nEnter k ");
    scanf("%d",&k);

    swaps(first, k);

    display(first);
    return 0;
}




node *swaps(node*first,int k)
{
    int i;
    //1 2 3 4 5 6 7 8 9
    node *trav = first, *fp, *lp, *ft, *lt,*temp;
    k--;

    for(i=0;i<k;++i)
    {

        fp  = trav;
        trav = trav->next;
    }
    ft = trav;

   // printf("%d %d", fp->info, ft->info);

    lt = first;

    while(trav->next!=NULL)
    {
        lp = lt;
        lt = lt->next;
        trav = trav->next;
    }
    //printf("\n\n%d %d", lp->info, lt->info);


    temp = lt->next;
    lt->next = ft->next;
    ft->next = temp;
    fp->next  = lt;
    lp->next = ft;

    return first;
}
