/*Implementation of the 0-1 KnapSack problem. Here, there can be only one of each item in the sack 

@Author : Girish Kumar
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

    wts = new int[n+1];
    values = new int[n+1];

    cout<<"\n\nEnter weight and value for each item ";

    for(int a = 1;a<=n;++a)
    cin>>wts[a]>>values[a];

    cout<<"\nEnter the maxiumum weight ";
    cin>>w;
    int **m;
    int i,j;

    m = new int*[w+1];

    for(i=0;i<=w;++i)
    m[i] = new int[n+1];

    for(i=0;i<=w;++i)
    for(j=0;j<=n;++j)
    m[i][j] = 0;




    for(i=1;i<=w;++i)
    {

        for(j=1;j<=n;++j)
        {
            if(i>=wts[j])
            {   cout<<m[i][j]<<" ";
                m[i][j] = getmax(m[i][j-1], m[i-wts[j]][j-1] + values[j]);

            }

            else
            {
            m[i][j] = m[i][j-1];
            }

        }
    }

    cout<<"\n\n";
    for(i=0;i<=w;++i)
    {

        for(j=0;j<=n;++j)
        cout<<m[i][j]<<" ";

        cout<<endl;
    }

}

