#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{

    int info;
    struct node* next;
};


node*newnode();
node* delfront(node*);
void delrear(node*);
node* insertfront(node*);
node* insertrear(node*);
void display(node*);
node* reverse(node*);

int main()
{
  node * first;
  //node *temp, *curr, *rear;
  char ans = 'y',op;
  first= NULL;

  while(ans == 'y')
  {
    printf("\n\n1. Insert Front\n2.Delete Front\n3.Insert Rear\n4.Delete Rear\n5.Display\n6. Reverse\n");
    cin>>op;

    switch(op)
    {

        case '1': first = insertfront(first);
        break;
        case '2': first = delfront(first);
        break;
        case '3': first = insertrear(first);
        break;
        case '4': delrear(first);
        break;
        case '5': display(first);
        break;
        case '6': first = reverse(first);
    }

    //printf("\n\nContinue? (Y/N)");
    //cin>>ans;

    }
    return 0;
}


node* newnode()
{
node*x;

x = (node*)malloc(sizeof(node));

if(x==NULL)
{
   printf("\nNO MEMORY");
    exit(0);
}

else
return x;


}


node* insertfront(node* first)
{

    int data;
    printf("\n\nEnter info ");
    cin>>data;

    node*tempnew  = newnode();
    tempnew->info = data;

    if(first==NULL)
    {
            first = tempnew;
            first->next=NULL;
        //cout<<"\n\nINSERTED RITE AT THE START!";
        return first;
    }

    else
    {

        tempnew->next = first;
        first = tempnew;

        return first;
    }
}


node* insertrear(node *first)
{
    int data;
    printf("\n\nEnter info ");
    cin>>data;

    node*tempnew  = newnode();
    tempnew->info = data;
    tempnew->next=NULL;

    if(first==NULL)
    {

            first = tempnew;
            return first;
    }


    else
    {

    node* rear,*temp=first;

    while(first!=NULL)
    {   rear = first;
        first=first->next;

    }

    rear->next = tempnew;
    rear=rear->next;
    return temp;
    }

}


node* delfront(node* first)
{

    if(first==NULL)
    {
        printf("\n\nUNDERFLOW! TERMINATING");
        exit(0);
    }

    node * temp;
    temp = first;
    first=first->next;
    free(temp);

    return first;
}


void delrear(node* first)
{
    if(first==NULL)
    {
        printf("\n\nUNDERFLOW! TERMINATING");
        exit(0);
    }



    node*prev;
    while(first->next!=NULL)
    {
        prev = first;
        first = first->next;
    }

    prev->next = NULL;
    free(first);

}

void display(node* first)
{
    printf("\n\nDisplaying nodes \n\n");
    while(first!=NULL)
    {

        printf("%d ->",first->info);
        first=first->next;
    }
}


node* reverse(node*first)
{
 node *newfirst=NULL;



    if(first==NULL)
    return first;
    node*temp;

    while(first!=NULL)
    {
        temp = first->next;
        if(newfirst==NULL)
        {
            newfirst = first;
            newfirst->next = NULL;
        }

        else
        {

            first->next = newfirst;
            newfirst = first;

        }

        first = temp;
    }
        /*node* curr = NULL, *temp;

        while(first!=NULL)
        {

            temp = first->next;
            first->next = curr;
            curr = first;
            first = temp;

        }*/


        return newfirst;

}
