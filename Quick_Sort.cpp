#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int make_part(int arr[], int l, int h)
{
    int x = arr[h];
    int i = l -1,j;

   for(j=l;j<=h-1;++j)
    {
        if(arr[j]<x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);
    return i+1;
}

void quicksort(int arr[], int l, int h)
{
int q;

if(l<h)
{
   q = make_part(arr, l ,h);
    quicksort(arr, l, q-1);
    quicksort(arr, q+1,h);
}

}

int main()
{
int n;
    int arr[10];
    cin>>n;
    for(int i = 0;i<n;++i)
    cin>>arr[i];

    quicksort(arr, 0, n-1);


    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";


}
