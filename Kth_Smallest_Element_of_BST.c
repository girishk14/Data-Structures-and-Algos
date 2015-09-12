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


void findkmin(node * root, int k, int *min)
{
    static int depth = 0;

    if(root==NULL||*min!=-1)return;

        findkmin(root->llink,k,min);

        if(++depth==k)
        *min = root->info;

    findkmin(root->rlink, k,min);

}

void inorder(node*root)
{
    if(root==NULL) return;

    inorder(root->llink);
    printf("%d ",root->info);

    inorder(root->rlink);
}

int main()
{

    int i, ele,k, min=-1;
    node *root =NULL;

    printf("\n\nInsert elements till -1 ");
    while(1)
    {

    scanf("%d",&ele);
    if(ele==-1) break;

    root = insert(root,ele);
    }

    printf("\n\n");

    inorder(root);
    printf("\n\n");

    printf("\nEnter k");
    scanf("%d ",&k);
    findkmin(root, k , &min);
    printf("\n\nThe %dth smallest element is %d ", k, min);



    return 0;

}



node* insert(node*root, int ele)
{
    node *temp = getnode();
    node *trav, *prev;
    temp->info = ele;

    if(root==NULL)

        {            return temp;
        }

    trav=root;


    while(trav!=NULL)
    {
        prev = trav;

        if(ele<trav->info)
        trav = trav->llink;

        else
        trav = trav->rlink;
    }

    if(ele<prev->info)
    prev->llink = temp;

    else
    prev->rlink = temp;

return root;
}



