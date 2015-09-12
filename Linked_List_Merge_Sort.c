#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int info;
    struct node* next;

}node;

node * insert(node*,int);
void sort(node*,node*);

node* getnode()
{

    node*tmp = (node*)malloc(sizeof(node));
    tmp->next = NULL;
    return tmp;
}

int main()
{   int data;

    node *h1=getnode();
    node *h2 = getnode();
    h1->info = 0;
    h2->info = 0;
    node*curr;
    printf("\n\nInsert data for first list. -1 to end ");

    while(1)
    {
        scanf("%d",&data);

        if(data==-1)
        break;

        h1 = insert(h1,data);
    }


    printf("\n\nInsert data for second list. -1 to end ");

    while(1)
    {
        scanf("%d",&data);

        if(data==-1)
        break;

        h2 = insert(h2,data);
    }


    printf("\n\nSORTING AND DISPLAYING . . . \n\n ");
    sort(h1,h2);
    }


node* insert(node* head, int data)

{

       node* temp = getnode();
    temp->info = data;
    node*trav=head;
    if(head->next==NULL)
    {
        head->next = temp;
        temp->next = head;

    }

    else
    {
        while(trav->next!=head)
        trav=trav->next;

        trav->next = temp;
        temp->next = head;
    }

    return head;
}


void sort(node*h1,node*h2)
{

    node *trav1 = h1->next;
    node* trav2 = h2->next;
    node *h3 = getnode();
    node *trav3;
    h2->next = NULL;


    while(trav1!=h1&&trav2!=h2)
    {

     if(trav1->info<trav2->info)
     {
         h3=insert(h3,trav1->info);
         trav1 = trav1->next;
     }

     else
     {

            h3 =insert(h3,trav2->info);
         trav2=trav2->next;
    }
    }

        while(trav2!=h2)
        {
                h3 = insert(h3,trav2->info);
            trav2=trav2->next;
        }

        while(trav1!=h1)
        {
            h3 = insert(h1,trav1->info);
            trav1=trav1->info;

        }

        trav3 = h3->next;

        while(trav3!=h3)
        {
            printf("%d -> ",trav3->info);
            trav3 = trav3->next;
        }
}
