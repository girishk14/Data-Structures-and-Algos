/*
Implementation of a bottom-up heapchec

@Author : Girish

*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

void heapify(int *arr, int i, int heapsize)
{
    int l = 2*i;
    int r = 2*i+1;

    int largest=i;

    if(l<=heapsize&&arr[l]>arr[largest])
    largest = l;

    if(r<=heapsize&&arr[r]>arr[largest])
    largest = r;


    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr, largest ,heapsize);
    }
}


int main()
{
int *arr;
int n,i;

cout<<"\nEnter n";
cin>>n;

arr = new int[n+1];

for(i=1;i<=n;++i)
cin>>arr[i];

for(i=n/2;i>=1;--i)
heapify(arr, i, n);

cout<<endl<<endl;
for(int i = 1;i<=n;++i)
cout<<arr[i]<<" ";

}
