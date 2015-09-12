/*

Implementation of Prim's Algorithm without using heaps, which is slightly inefficient


@Author : GirishKumar

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct ele
{
    int weight, origin;
};

int **mat;
int *istree;

void AddEdge(char s, char d, int w)
{
    mat[s-65][d-65] = mat[d-65][s-65] = w;
}

int getmin(ele *pq)
{


    int i, minval, m;

    for(i=0;i<v;++i)
    {
        if((pq[i]).weight<minval&&pq[i]!=0)
        {
            m = i;
            minval = pq[i];
        }

    }

    return m;
}


int main()
{

    inr i,j;

    mat = new int*[v];
    char ch;
    int str;

    for(i=0;i<v;++i)
        mat[i] = new int[v];

    for(i=0;i<v;++i)
    {

        for(j=0;j<v;++j)
        {

            if(i==j)
            mat[i][j] = 0;

            else
            mat[i][j] = INT_MAX;
        }
    }

    //ADD EDGES

    istree = new int[v];

    istree[str] = 1;

    ele *pqueue = new int[v];

    for(i=0;i<v;++i)
    {

        pqueue[i].origin = str;
        pqueue[i].weight = mat[str][i];
    }



}
