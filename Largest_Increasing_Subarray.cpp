

/*

Problem Statement: To find the largest increasing subarray

This problem has been solved using recursion

@Author : GirishKumar

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int returnmaxsize(int arr[], int n, int i)
{


    if((arr[(i+1)%n]<arr[i]))
    return 1;

    else
    return (1 + returnmaxsize(arr,n, (i+1)%n));

}

int main()
{
    int n, *arr;

    cout<<"\n\nEnter the size of the array ";
    cin>>n;
    int i, msize=0, mstart=0, temp,j;
    arr = new int[n+1];

    arr[n] = -999;
    cout<<"\n\nEnter the elements of the array ";
    for(i=0;i<n;++i)
    cin>>arr[i];

    for(i=0;i<n;++i)
    {   temp = returnmaxsize(arr,n,i);
        if(temp>msize)
        {msize = temp;
        mstart = i;}
    }

    cout<<"\n\nThe Largest increasing subsequence is: \n";
    for(i=mstart, j=0;j<msize;++j)
    cout<<arr[(i+j)%n]<<" ";

    return 0;

}
