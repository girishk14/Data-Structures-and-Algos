#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

void add_in_heap(int ele, int *heap, int &heapctr)
{
heap[++heapctr] = ele;
int i = heapctr;

while(heap[i/2]<heap[i])//&&i/2>=1)
{
swap(heap[i], heap[i/2]);
i/=2;
}

cout<<endl;
for(i=1;i<=heapctr;++i)
cout<<heap[i]<<" ";

}


int main()
{
int n,i;
int *arr;
cin>>n;
arr = new int[n];
for(i=0;i<n;++i)
cin>>arr[i];

int *heap = new int[n+1];
int heapctr = 0;
heap[0] = 99999;
cout<<endl<<endl;

for(i=0;i<n;++i)
add_in_heap(arr[i], heap, heapctr);

//for(i=1;i<=n;++i)
//    cout<<heap[i]<<" ";

}

