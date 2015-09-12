#include <stdio.h>
#include <stdlib.h>


typedef struct
{

    int digit;
    struct node* next;
    struct node* prev;

}node;

node * getnode()
{

    node *temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->prev = NULL;
        return temp;

}
node* insert(node* last,int data)
{
    node *temp = getnode();
    temp->digit = data;
    node *first;
    if(last==NULL)
    {
        last = temp;
        last->next = last;
        last->prev = last;
        return last;
    }

    else
    {
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        first = temp->next;
        first->prev = temp;
        return temp;
    }
}

int main()
{

node* l1= NULL ,*l2=NULL, *l3 = NULL;
node *trav1,*trav2, *trav3;
int a;
int carry, dig,sum;
printf("\nEnter the data for first list");
while(1)
{
    scanf("%d",&a);

    if(a==-1)
    break;

    l1 = insert(l1,a);
}

printf("\nEnter the data for the second list ");
while(1)
{
    scanf("%d",&a);

    if(a==-1)
    break;

    l2 = insert(l2,a);
}

/*printf("\nFirst Long integer: ");

trav1 = l1->next;
printf("\n\n");
do
{

    printf("%d - > ",trav1->digit);
    trav1 = trav1->next;
}while(trav1!=l1->next);


printf("\n\nSecond long integer :");
trav2 = l2->next;
printf("\n\n");
do
{

    printf("%d - > ",trav2->digit);
    trav2 = trav2->next;
}while(trav2!=l2->next);
printf("\n\n");
carry = 0;

//printf("\n\n THE VALUES OF THE FIRST NODES ARE %d and %d", trav1->digit, trav2->digit);*/

do
{
    sum = trav1->digit + trav2->digit + carry;
    dig = sum%10;
    l3 = insert(l3,dig);
    carry = sum/10;
    trav1= trav1->next;
    trav2 = trav2->next;

}while(trav1!=l1->next&&trav2!=l2->next);

if(trav1 == l1->next)
{
    while(trav2!=l2->next)
    {
        sum =trav2->digit+carry;
        carry = sum/10;
        dig = sum%10;
        l3 = insert(l3,dig);
        trav2 = trav2->next;
    }
}

else
{

    while(trav1!=l1->next)
    {
        sum = trav1->digit+carry;
        carry = sum/10;
        dig = sum%10;
        l3 = insert(l3,dig);
        trav1 = trav1->next;
    }
}

l3 = insert(l3,carry);

printf("\n\nPRINTING THE ADDED LONG INTEGER");
trav3 = l3->next;
printf("\n\n");
do
{

    printf("%d - > ",trav3->digit);
    trav3 = trav3->next;
}while(trav3!=l3->next);



    return 0;
}
