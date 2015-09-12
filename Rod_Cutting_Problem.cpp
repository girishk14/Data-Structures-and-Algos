#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


int gmax(int a, int b)
{


    if(a>b)
        return a;

    return b;
}

int main()
{

    int p[] = {0,1,5,8,9,10,17,17,20,24,30};
    int *r = new int[11];
    r[0] = 0;
    int n = 10;
    int i,j;
    int q;


    for(j=1;j<=n;++j)
    {
        q = -1;

        for(i=1;i<=j;++i)
        {

            q = gmax(q, p[i] + r[j-i]);
    //    cout<<q<<endl;
        }

        r[j] = q;

    }
cout<<r[n];

}
