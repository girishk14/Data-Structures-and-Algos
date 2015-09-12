#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;


struct mterm
{
    char maj[100];
    struct sterm* sptr;
    struct page* pptr;
    struct mterm* llink;
    struct mterm* rlink;
};

struct sterm
{
char sub[100];
struct sterm *sllink;
struct sterm  *srlink;
struct page *spptr;
};

struct page
{
    int no;
    struct page *pllink;
    struct page *prlink;
};


void display(mterm*);

mterm * getmajnode()
{
    mterm *temp = (mterm*)malloc(sizeof(mterm));
    temp->llink = NULL;
    temp->rlink = NULL;
    temp->pptr = NULL;
    temp->sptr=NULL;
    return temp;
}

sterm * getsubnode()
{
    sterm *temp = (sterm*)malloc(sizeof(sterm));
    temp->sllink = NULL;
    temp->srlink = NULL;
    temp->spptr=NULL;
    return temp;
}

page *getpagenode()
{
    page *temp = (page*)malloc(sizeof(page));
    temp->pllink = NULL;
    temp->prlink = NULL;
    return temp;
}

mterm *findnode(mterm *root, char str[]);
sterm *subtree(sterm *root, char term[],int nopages, int list[]);
page *pagetree(page *root, int nopages, int pagelist[]);
mterm *majortree(mterm *root, char term[],int nopages, int pagelist[]);



void subdisplay(sterm*);
void pagedisplay(page*);

int main()
{
 int pagenos[100];
 char type;
 int n,i;
 char str[100];
 mterm *active=NULL;

 mterm *treeroot=NULL;
 while(1)
 {
 printf("\n\nEnter the input lines in the format : <type><term><no of pages><page set>. Enter 0,0,0,0 when done");

        cin>>type;
if(type=='0')
 break;

cin>>str;
cin>>n;

 for(i=0;i<n;++i)
 cin>>pagenos[i];

 printf("\n\nDONE SCANNING!");


 if(type=='m'||type=='M')
 {
     treeroot = majortree(treeroot,str, n, pagenos);
     active = findnode(treeroot, str);
 }

 if(type=='s'||type=='S')
     active->sptr = subtree(active->sptr, str, n, pagenos);


 }



 printf("\n\nDisplaying the Index of the Textbook . . .\n\n");

 display(treeroot);
 return 0;
}



void display(mterm* root)
{
    if(root==NULL)
    return;

    display(root->llink);

    printf("%s:", root->maj);
    pagedisplay(root->pptr);
    printf("\n\n\n");
    subdisplay(root->sptr);
printf("\n\n\n");
    display(root->rlink);
}

void pagedisplay(page*root)
{
    if(root==NULL)
    return;

    pagedisplay(root->pllink);
    printf("%d, ", root->no);
    pagedisplay(root->prlink);
}


void subdisplay(sterm*root)
{
    if(root==NULL)
    return;

    subdisplay(root->sllink);

    printf("     %s - ", root->sub);
    pagedisplay(root->spptr);
    printf("\n");

    subdisplay(root->srlink);
}



mterm *majortree(mterm *root, char term[],int nopages, int pagelist[])
{

    mterm *temp = getmajnode();
    strcpy(temp->maj,term);
    mterm *curr,*prev;

    temp->pptr = pagetree(temp->pptr, nopages, pagelist);

    if(root==NULL)
    {
        printf("I KILL U!");
        return temp;

    }
    curr = root;

    while(curr!=NULL)
    {
        prev = curr;
        if(strcmp(term, curr->maj)<0)
        curr=curr->llink;

        else
        curr = curr->rlink;
    }

    printf("INSERTED MON!");

    if(strcmp(term,prev->maj)<0)
    prev->llink = temp;

    else
    prev->rlink = temp;

    return root;
}

page *pagetree(page *root, int nopages, int pagelist[])
{
    page *curr, *prev, *temp;
    int i=0;
    for(i = 0;i<nopages;++i)
    {
        temp = getpagenode();
        temp->no = pagelist[i];
        curr = root;

        if(root==NULL)
        root = temp;

        else
        {

            while(curr!=NULL)
            {
                prev = curr;
                if(pagelist[i]<curr->no)
                curr = curr ->pllink;

                else
                curr = curr->prlink;
            }

            if(pagelist[i]<prev->no)
            prev->pllink = temp;

            else
            prev->prlink = temp;

        }

    }

    return root;
}

sterm *subtree(sterm* root, char term[],int nopages, int list[])
{

    sterm *temp = getsubnode();
    strcpy(temp->sub,term);
    sterm *curr,*prev;

    temp->spptr = pagetree(temp->spptr, nopages, list);

    if(root==NULL)
    return temp;

    curr = root;

    while(curr!=NULL)
    {

        cout<<"HEHE ";
        prev = curr;
        if(strcmp(term, curr->sub)<0)
        curr=curr->sllink;

        else
        curr = curr->srlink;
    }

    if(strcmp(term,prev->sub)<0)
    prev->sllink = temp;

    else
    prev->srlink = temp;

    return root;
}


mterm *findnode(mterm *root, char str[])
{
    mterm*curr = root,*prev;

    while(curr!=NULL)
    {
        prev = curr;
        if(strcmp(str, curr->maj)<0)
        curr=curr->llink;

        else
        curr = curr->rlink;

        if(!strcmp(prev->maj,str))
        return prev;
    }


}
