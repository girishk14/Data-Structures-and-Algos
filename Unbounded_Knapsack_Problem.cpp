/*
This is  an implementation of the unbounded knapsack problem, i.e to choose combination of items in a knapsack such that we get maximum value. 
In this case, there is no restriction on the number of each item.

@Author: GirishKumar
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;




int getmax(int a, int b)
{

    if(a>b)
        return a;
    return b;

}
int main()
{
    int n, w, *wts, *values;
    cout<<"\nEnter the number of items ";
    cin>>n;

    wts = new int[n];
    values = new int[n];

    cout<<"\n\nEnter weight and value for each item ";

    for(int a = 0;a<n;++a)
    cin>>wts[a]>>values[a];

    cout<<"\nEnter the maxiumum weight ";
    cin>>w;
    int *m;
    int i,j;
    m = new int[w + 1];
    int q;
    m[0] = 0;

    for(i=1;i<=w;++i)
    {cout<<"For weight = "<<i<<endl;
            q = -999;
            for(j=0;j<n;++j)
            {
                if(wts[j]<=i)
                    {
                    q = getmax(q, values[j] + m[(i-wts[j])]);
                    cout<<"item "<<j<<" q = "<<q<<"\n";
                    }
                    cout<<endl;
            }
            cout<<"maxval is "<<q;
            m[i] = q;


    }

cout<<endl<<endl;

for(i=0;i<=w;++i)
cout<<m[i]<<" ";


}
