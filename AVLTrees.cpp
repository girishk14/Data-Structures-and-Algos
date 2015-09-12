

/*
This program is an implementation of AVL Tree. AVL Trees are a technique for building trees that are balanced
i.e Not heavily biased in any direction. Such trees help us easily acheive a search time of O(log n) since 
the maximum depth of any node cannot exceed log n.'


@Author GirishKumar
*/
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
struct bstnode
{

    int data;
    bstnode *left;
    bstnode *right;
    bstnode *p;
};
int getbalance(bstnode *subroot);
void RightRotate(bstnode *y);
void LeftRotate(bstnode *x);

bstnode *root = NULL;

void insert(int val)
{

    bstnode *temp = new bstnode();
    temp->data= val;
    temp->left = temp->p =  temp->right = NULL;

    if(root==NULL)
    {

        root = temp;
        return;
    }

    bstnode *parent, *trav;
    trav = parent = root;

    while(trav!=NULL)
    {
        parent = trav;

        if(trav->data<val)
        {
        trav = trav->right;
        }

        else
        {
        trav = trav->left;
        }
    }

    temp->p = parent;

    if(parent->data<val)
    {
    parent->right = temp;
    }

    else
    {
    parent->left = temp;
    }

    bstnode *grandfather, *father, *kid;
    kid = temp;
    father = parent;
    grandfather = parent->p;


    while(grandfather!=NULL&&getbalance(grandfather)<=1)
    {
    kid = father;
    father = grandfather;
    grandfather = grandfather->p;
    }


    if(grandfather!=NULL)
    {
    if(father==grandfather->left&&kid==father->left)
    RightRotate(grandfather);

    else if(father==grandfather->right&&kid==father->right)
    LeftRotate((grandfather));

    else if(father==grandfather->left&&kid==father->right)
    {

        RightRotate((father));
        LeftRotate(grandfather);

    }


    else if(father==grandfather->right&&kid==father->left)
    {

        LeftRotate((father));
        RightRotate(grandfather);

    }

    }





}

int height(bstnode *sroot)
{

if(sroot==NULL) return 0;

return max(height(sroot->left), height(sroot->right)) + 1;

}


int getbalance(bstnode *subroot)
{
    int h1 = height(subroot->left);
    int h2 = height(subroot->right);

    return abs(h1-h2);

}


void LeftRotate(bstnode *x)
{

bstnode *y = x->right;
x->right =y->left;

if(y->left!=NULL)
(y->left)->p = x;

y->p = x->p;

if(x==root)
root = y;

else  if((x->p)->left==x)
(x->p)->left = y;

else
(x->p)->right = y;

y->left = x;
x->p = y;

}


void RightRotate(bstnode *y)
{

    bstnode * x = y->left;

y->left = x->right;

if(x->right!=NULL)
(x->right)->p = y;

x->p = y->p;

if(y==root)
root = x;

else  if((y->p)->left==y)
(y->p)->left = x;

else
(y->p)->right = x;

x->right = y;
y->p = x;

}







void inorder(bstnode *roots, int level = 0)
{
    if(roots==NULL) return;
        inorder(roots->left,level+1);
        cout<<"\n\nI am "<<roots->data;//<<" and my kids are "<<(roots->left)->data<<" " <<(roots->right)->data<<"\n\n";
        inorder(roots->right,level+1);

}


int main()
{
    int n, val;
    while(true)
    {
        cin>>val;
        if(val==-1)
        break;
        insert(val);
    }
    inorder(root);
}
