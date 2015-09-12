/*

Implementation of Prim's algorithm for minimum spanning tree, using an optimized approach, i.e using a heap

@Author  :  GirishKumar


#include <iostream>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
class graphnode;
class edgenode
{
public:
int weight;
graphnode *arc;
edgenode *nexte;
};

class graphnode
{
public:
    int id;
    edgenode *adjlist, *elast;
    graphnode *nextg;
    int data;

    graphnode(int d)
    {
    data=d;
    adjlist = elast = NULL;
    nextg = NULL;
    }

    void addArc(graphnode *v, int wt)
    {
        edgenode *temp = new edgenode();
        temp->weight = wt;
        temp->arc = v;

        if(adjlist==NULL)
        adjlist=elast=temp;


        else
        {
        elast->nexte = temp;
        elast = temp;
        }
    }
}*G,*glast;



void addVertex(int i)
{
graphnode *temp = new graphnode(i);

if(G==NULL)
G = glast = temp;

else
{
    glast->nextg = temp;
    glast = temp;
}
}


void addEdge(int a, int b, int w)
{
    graphnode *trav = G;
    graphnode *v1, *v2;

    while(trav!=NULL)
    {
        if(trav->data==a)
        v1 = trav;

        if(trav->data==b)
        v2 = trav;
        trav = trav->nextg;
    }
    v1->addArc(v2,w);
    v2->addArc(v1,w);
}

class heapnode
{
    public:
    int distance;
    graphnode *destvalue;
    graphnode *origin;
};


void minheapify(heapnode *heap, int i, int heapsize)
{
int smallest=i;
int l = i*2;
int r = i*2 +1;

if(l<=heapsize&&heap[l].distance<heap[i].distance)
smallest = l;

if(r<=heapsize&&heap[r].distance<heap[smallest].distance)
smallest = r;

if(smallest!=i)
{
    (heap[smallest].destvalue)->id = i;
    (heap[i].destvalue)->id = smallest;

    heapnode temp = heap[i];
    heap[i] = heap[smallest];
    heap[smallest] = temp;

    minheapify(heap, 1, heapsize);
}
}


heapnode extract_min(heapnode * heap, int &heapsize)
{
heapnode temp = heap[1];
heap[1] = heap[heapsize];
(heap[1].destvalue)->id = 1;
temp.destvalue->id = INT_MAX;
heapsize--;
minheapify(heap, 1, heapsize);
return temp;
}


void bubble_up(heapnode *heap, int i)
{
    while(i/2>=1&&heap[i].distance<heap[i/2].distance)
    {
        heapnode temp = heap[i];
        (heap[i].destvalue)->id = i/2;
        (heap[i/2].destvalue)->id = i;
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i = i/2;
    }
}

int main()
{

for(int i=1;i<5;++i)
addVertex(i);


addEdge(1,2,2);
addEdge(1,3,3);
addEdge(2,4,4);
addEdge(3,4,4);
addEdge(1,4, 8);
addEdge(3,2,7);

const int v = 4;
graphnode *trav = G;
int heapctr = 1;
heapnode *heap = new heapnode[v+1];
int heapsize = v;
const int source = 4;

graphnode *s = G;
while(s->data!=source)
s=s->nextg;

while(trav!=NULL)
{
    if(trav==s)
    heap[heapctr].distance = 0;

    else
    heap[heapctr].distance = 999;

    heap[heapctr].origin=s;
    heap[heapctr].destvalue = trav;
    trav->id = heapctr;
    heapctr++;
    trav = trav->nextg;
}//INITIATILIZING HEAP

bubble_up(heap,s->id);

for(int i=0;i<v;++i)
{
    heapnode temp = extract_min(heap, heapsize);

    cout<<"\n\nEdge extracted "<<" From "<<temp.origin->data<<" to "<<temp.destvalue->data<<" of weight "<<temp.distance<<endl;
    edgenode *etrav = (temp.destvalue)->adjlist;

    while(etrav!=NULL)
    {
        cout<<etrav->arc->data<<": ";
        int curr_stat =(etrav->arc)->id;

        if(curr_stat<=heapsize)
        {
        cout<<etrav->weight<<" "<<heap[curr_stat].distance<<endl;

        if(etrav->weight<heap[curr_stat].distance)
        {
            heap[curr_stat].distance = etrav->weight;
            heap[curr_stat].origin = temp.destvalue;
            bubble_up(heap,curr_stat);
        }
        }
        else
        cout<<"Done!"<<endl;
        etrav = etrav->nexte;
    }
}
}
