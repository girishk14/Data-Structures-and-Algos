#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
int info;
struct node *llink;
struct node *rlink;
}node;

node* getnode()
{
    node *temp = (node*)malloc(sizeof(node));
    temp->llink = NULL;
    temp->rlink=NULL;
    return temp;
}
node* insert(node*root, int ele);
node* delete(node*root, int ele);

int main()
{

    int ch, ele;
    node *root=NULL;

    while(1)
    {

        printf("\n\n1.Insert\n2. Delete\n3. Exit");
        scanf("%d",&c);
        printf("\n\nEnter element ");
        scanf("%d",&ele);

        switch(ch)
        {

            case 1: insert(root,ele);
            break;
            case 2: delete(root, ele);
            break;
            case 3: exit(0);
        }
    }

    return 0;

}


node* insert(node*root, int ele)
{
    node *temp = getnode():
    node *trav, prev;
    temp->info = ele;

    if(root==NULL)
    return temp;

    trav=root;

    while(trav!=NULL)
    {
        prev = trav;

        if(ele>trav->info)
        trav = trav->rlink;

        else
        trav = trav->llink;
    }



}



node* delete(node*root, int ele);
