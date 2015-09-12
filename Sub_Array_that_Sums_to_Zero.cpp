
/*

Problem Statement: Check if there is a subarray that sums to 0

@Author : Girish

*/


#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int sumzero(int arr[], int n, int i)

{   static int depth = 0;
    static int sum = 0;

    if(depth==n)
    {   depth=0;
        sum=0;
        return -1;

    }

    if(sum==0&&depth>0)
    {
        int temp = depth;
        depth = 0;
        sum = 0;
        return temp;
    }

    else
    {sum += arr[i];
    depth++;
    return(sumzero(arr, n, ((i+1)%n)));
    }


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
    {   temp = sumzero(arr,n,i);
        if(temp>msize)

        {msize = temp;
        mstart = i;}
    }

    cout<<"\n\nThe Largest Subsequence summing to zero is: \n";
    for(i=mstart, j=0;j<msize;++j)
    cout<<arr[(i+j)%n]<<" ";

    return 0;

}
