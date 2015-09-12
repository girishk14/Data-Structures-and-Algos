/*

C++ Implmentation of Kruskal's Algorithm for Minimum Spanning Tree

@Author : Girish

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class graphnode;
class edgenode
{   public:
    int weight;
    graphnode *arc;
    edgenode *nexte;
    graphnode *origin;
};


class forestnode
{
public:
void *value;
forestnode *parent;
};

class graphnode
{
public:
char data;
bool visited;
graphnode *nextg;
int id;


edgenode  *adjlist, *last;

    graphnode(char ch, int idd)
    {   data = ch;
        visited = 0;
        adjlist = NULL;
        id = idd;
        last = NULL;
    }
    void addArc(graphnode *v, int w)
    {
        edgenode *temp = new edgenode();
        temp->arc = v;
        temp->nexte = NULL;
        temp->origin = this;
        temp->weight = w;

        if(adjlist==NULL)
        adjlist = temp;
        else
        last->nexte = temp;

        last = temp;
    }
}*G, *glast;

vector<edgenode> arr;

void addVertex(char c, int id)
{
    graphnode *temp = new graphnode(c, id);
    temp->nextg = NULL;

    if(G==NULL)
    G=temp;
    else
    glast->nextg = temp;

    glast = temp;
}

void addEdge(char v1, char v2, int weight)
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

    vert1->addArc(vert2, weight);
     vert2->addArc(vert1, weight);

    arr.push_back(*(vert1->last));
}

forestnode *make_forest_node(void *val)
{
     forestnode* node = (forestnode*)malloc(sizeof(forestnode));
    node->value = val;
    node->parent = NULL;
    return node;
}


forestnode* FindParent(forestnode* node)
{
    while (node->parent != NULL)
        node = node->parent;

    return node;
}

void Union(forestnode* node1, forestnode* node2)
{
    node2->parent = node1; /* or node1->parent = node2; */
}


bool func(const edgenode &e1, const edgenode &e2)
{

    if(e1.weight<e2.weight)
    return true;

    return false;

}

int main()
{
    G=NULL;
    graphnode *temp;
    int i;
    char ch;




for(i=65;i<=70;++i)
    addVertex((char)i, i-65);



addEdge('A','E', 1);
addEdge('A','B', 3);
addEdge('B','F', 2);
addEdge('D','F', 3);
addEdge('D','C', 2);
addEdge('E','C', 1);
addEdge('A','D', 6);
addEdge('C','B', 7);
addEdge('A','C', 1);

addEdge('B','D', 2);


graphnode *trav = G;

sort(arr.begin(), arr.end(),func);

forestnode **myforest = new forestnode*[6];

graphnode *gt = G;
i=0;

while(gt!=NULL)
{
myforest[i] = make_forest_node(gt);
gt=gt->nextg;
i++;
}

int x=0;
for(i=0;i<arr.size();++i)
{
    int a = (arr[i].origin)->id;
    int b = (arr[i].arc)->id;

    if(FindParent(myforest[a])!=FindParent(myforest[b]))
        {
            myforest[a]->parent = myforest[b];
            cout<<"\nEdge from "<<(arr[i].origin)->data<<" to "<<(arr[i].arc)->data<< " of weight "<<arr[i].weight<<" added \n\n";
                x++;
        }
        if(x==5)
            break;
}
}
