/*
This program is an implementation of breadth first search and depth first search by representing the graph as an adjacency list. 

@Author: GirishKumar
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

class graphnode;
class edgenode
{   public:
    int weight;
    graphnode *arc;
    edgenode *nexte;
};

class graphnode
{
public:
char data;
bool visited;
graphnode *nextg;
edgenode  *adjlist, *last;

    graphnode(char ch)
    {   data = ch;
        visited = 0;
        adjlist = NULL;
        last = NULL;
    }
    void addArc(graphnode *v)
    {
        edgenode *temp = new edgenode();
        temp->arc = v;
        temp->nexte = NULL;

        if(adjlist==NULL)
        adjlist = temp;
        else
        last->nexte = temp;

        last = temp;
    }
}*G, *glast;

void addVertex(char c)
{
    graphnode *temp = new graphnode(c);
    temp->nextg = NULL;

    if(G==NULL)
    G=temp;
    else
    glast->nextg = temp;

    glast = temp;
}

void addEdge(char v1, char v2)
{
    graphnode *iter=G,*vert1,*vert2;

    while(iter!=NULL)
    {
    if(iter->data==v1)
        vert1 = iter;
    if(iter->data==v2)
        vert2 = iter;
        iter=iter->nextg;
    }
    vert1->addArc(vert2);
}

void dfs(graphnode *g);
void bfs(graphnode *g);

int main()
{
    G=NULL;
    graphnode *temp;
    int i;
    char ch;



for(i=65;i<=70;++i)
    addVertex((char)i);



addEdge('A','C');
addEdge('A','D');
addEdge('C','D');
addEdge('C','F');
addEdge('E','F');
addEdge('B','F');
addEdge('E','B');

graphnode *trav = G;

while(trav!=NULL)
{
    edgenode *etrav=trav->adjlist;
    cout<<trav->data<<" : ";
    while(etrav!=NULL)
    {cout<<(etrav->arc)->data<<" ";
    etrav = etrav->nexte;
    }
    cout<<endl;
    trav = trav->nextg;
}
bfs(G);
}






void dfs(graphnode *g)
{
    if(g->visited==0)
    {


        g->visited = true;
        cout<<g->data<<" ";

        edgenode *trav = g->adjlist;

        while(trav!=NULL)
        {

            dfs(trav->arc);
            trav = trav->nexte;
        }
    }
}




void bfs(graphnode *g)
{

list<graphnode*> bfsqueue;

bfsqueue.push_back(g);
graphnode *hello;
g->visited = 1;

while (!bfsqueue.empty())
{
    hello = bfsqueue.front();
   cout<<hello->data<<" ";
   bfsqueue.pop_front();


    edgenode *etrav = hello->adjlist;

    while(etrav!=NULL)
    {

        if((etrav->arc)->visited==0)
        {

            etrav->arc->visited = 1;
            bfsqueue.push_back((etrav->arc));

            }

        etrav = etrav->nexte;
    }

}


}
