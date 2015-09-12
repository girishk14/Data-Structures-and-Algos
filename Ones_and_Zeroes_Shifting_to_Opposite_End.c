//#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int arr[1000],n;
    int i,left,right;
    printf("\n\nEnter the size of the array ");
    scanf("%d",&n);


    printf("\n\nEnter the elements of the array :");

    for(i=0;i<n;++i)
    scanf("%d",&arr[i]);

    printf("\n\nThe original array is : ");
    for(i=0;i<n;++i)
   printf("%d ",arr[i]);

    left = 0;
    right = n-1;


      while(left < right)
    {
        while(arr[left] == 0 && left < right)
        left++;

        while(arr[right] == 1 && left < right)
        right--;

        if(left < right)
        {
        arr[left] = 0;
        arr[right] = 1;
        left++;
        right--;
        }
    }


    printf("\n\nThe sorted array is :");
    for(i=0;i<n;++i)
    printf("%d ",arr[i]);
}


