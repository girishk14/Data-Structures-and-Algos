//Creating tree using recursion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    int data;
    struct node *llink;
    struct node *rlink;
}node;


node *getnode()
{
    node*temp;
    temp = (node*)malloc(sizeof(node));
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}


node* insert(node*root, node *temp, char dir[100],int i)
{

    static int StatusFlag = 0;

    if(root==NULL)
    {
    StatusFlag=1;
    return temp;
    }

    if(dir[i]=='L')
    {

    insert(root->llink, temp, dir, (i+1)); //DO NOT PASS ++i here or else value of i will be permanently changed when  we return control
    }

    else
    {

    insert(root->rlink, temp, dir, (i+1));
    }


    if(StatusFlag==1)
    {
    if(dir[i]=='L')

    {
        root->llink = temp;
    }
    else
    {
    root->rlink = temp;
    }

    StatusFlag=0;
    return root;
    }
    else return root;
}

void inorder(node* root, int prev, int *flag)
{
    if(root==NULL)
    return;

    if(*flag==0)
    return;

    inorder(root->llink, prev, flag);

    if(root->data<prev)
    *flag = 0;
     prev=root->data;

    inorder(root->rlink,prev, flag);
}
int main()

{   int flag = 1;
    node* root=NULL;
    int datas;
    node *temp;
    char dir[20];
    printf("\n\nEnter information for nodes. Enter -1 when done ");

    while(1)
    {
        scanf("%d",&datas);
        if(datas==-1)
        break;

        printf("\n\nEnter directions to enter this node ");
        scanf("%s",dir);
        temp = getnode();
        temp->data = datas;

        printf("\n\n\n");

        root = insert(root,temp,dir, 0);
    }

inorder(root, -999, &flag);

if(flag==1)
printf("\nIt is a B.S.T!");

else
printf("NOT A B.S.T! ");

return 0;
}
