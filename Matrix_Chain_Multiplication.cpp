//Solving matrix chain problem using dynamic programming


/*
This algorithm uses Dynamic Programming solve the Matrix Multiplication Optimization problem. It forms subchains that minimize 
the number of steps in the multiplication

@Author: GirishKumar

*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

struct dimensions
{
    int d1, d2;
};


void printoptimal(int **s, int i, int j);

int main()
{

int n,i,j,k,l;
cout<<"\n\nEnter the number of matrices ";
cin>>n;

dimensions *dimlist = new dimensions[n+1];
cout<<"\n\nEnter the dimensions ";
for(i=1;i<=n;++i)
cin>>dimlist[i].d1>>dimlist[i].d2;

int **m = new int*[n+1];
int **s = new int*[n+1];



for(i=0;i<=n;++i)
{
    *(m+i) = new int[n+1];
    *(s+i) = new int[n+1];
}

for(i=0;i<=n;++i)
    for(j=0;j<=n;++j)
    m[i][j] = 0;

for(i=0;i<=n;++i)
{
    m[i][i] = 0;

}




int q;



for(l=2; l<=n;++l)
{

    cout<<"\n\nLength = "<<l<<endl;
    for(i=1;i<=n-l+1;++i)
    {

        j = i+l-1;
        m[i][j] = 320000;

        for(k=i;k<=j-1;++k)
        {

            cout<<"i = "<<i<<" k = "<<k<<" j = "<<j<<endl;
            q = m[i][k] + m[k+1][j] + dimlist[i].d1*dimlist[j].d2*dimlist[k].d2;

            if(q<m[i][j])
            {

                m[i][j] = q;
                s[i][j] = k;
            }
        }

    }
}


for(i=1;i<=n;++i)
{
    for(j=i;j<=n;++j)
        cout<<m[i][j]<<" ";
    cout<<"\n";
}

printoptimal(s,1,n);
}

void printoptimal(int **s, int i, int j)
{


    if(i==j)
        cout<<"A"<<i;


    else
    {

        cout<<"(";
        printoptimal(s, i, s[i][j]);
        printoptimal(s,s[i][j]+1, j);
        cout<<")";
    }

}
