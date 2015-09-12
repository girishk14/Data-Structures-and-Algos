#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;


void mergesort(int arr[], int p, int r)
{

if(p>r) return;

    int q = (r+p)/2;
    mergesort(arr, p, q);
    mergesort(arr, q+1, r);
    int * temp = new int[r-p+1];
    int a = p, b = q+1;
    int c = 0,i;


    while(a<=q&&b<=r)
    {
    if(arr[a]<arr[b])
    temp[c++] = arr[a++];

    else
    temp[c++] = arr[b++];
    }


    if(a>q)
    {
        for(b;b<=r;++b)
            temp[c++] = arr[b];
    }

    else
    {
        for(a;a<=q;++a)
        {
            temp[c++] = arr[a];
        }
    }



    for(i=p,c=0;i<=r;++i,++c)
    arr[i] = temp[c];


}

int main()
{
int n = 6;
int arr[] = {7,9,3,5,1,2};

mergesort(arr, 0, n-1);

for(int i =0;i<n;++i)
    cout<<arr[i]<<" ";
}
