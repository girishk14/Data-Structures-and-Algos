#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{

    int i,j,k,negcount, negsize, count,n, sum,negflag=0;
    int arr[100],negposarr[100];


    cout<<"Enter the size of the array ";
    cin>>n;

    cout<<"\n\nEnter the elements of the array";
    for(i=0;i<n;++i)
    cin>>arr[i];

    cout<<"\n\nThe sequence entered is :\n";
    for(i=0;i<n;++i)
    cout<<arr[i]<<" ";




    for(i=0,j=0;i<n;++i)
    {
        if(arr[i]<0)
        {
            negflag = 1;
            negposarr[j++] = i;
        }
    }
    negsize = j;

    if(negflag==0)
    {

        cout<<"\n\nThe greatest sum is the entire sequence itself \n\n";
        exit(0);
    }

    int ll,ul,max = 0;
    int lmax,umax;

    sum = 0;

    for(i=0;i<negsize;++i)
        {
            ll = negposarr[i];
            for(j=0;j<negsize;++j)
            {
                sum=0;
                ul = negposarr[j];

                if(ul<=ll)
                ul+=n;

                //cout<<"\nRange analyzed : "<<ll<<" to "<<ul;
                for(k=ll+1;k<ul;++k)
                {
                    sum =sum+arr[k%n];
                }

                if(sum>max)
                {   max=sum;
                    lmax = ll;
                    umax = ul;
                }

            }
        }


    cout<<"\n\nPrinting the largest sum of a cyclic sequence along with the sequence :\n";
    cout<<"Sum  = "<<max;
    cout<<"\nSequence :  ";


    for(i=lmax+1;i<umax;++i)
    cout<<arr[i%n]<<" ";

    cout<<"\n\n\n";

    return 0;
}
