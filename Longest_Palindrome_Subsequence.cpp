
/*
Algorithm to find the longest palindrome that occurs as a subsequence in a string

Example : For “BBABCBCAB”, “BABCBAB” is the longest palindromic subseuqnce in it

@Author : Girish

*/


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int getmax(int a, int b)
{

    if(a>b) return a;
    return b;
}

int main()
{
char str[1000];
cout<<"\nEnter string  ";
gets(str);


int n = strlen(str);
int i,j;
int**arr;

arr = new int*[n];
for(i=0;i<n;++i)
arr[i] = new int[n];


for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    {

    if(i==j) arr[i][j] = 1;
    else arr[i][j] = 0;
    }


for(i=0;i<n;++i)
{
    for(j=i;j>=0;--j)
    {
        cout<<i<<" "<<j<<endl;
        if(i==j)continue;

        if(str[i]==str[j])
        arr[j][i] = 2 + arr[j+1][i-1];

        else
        arr[j][i] = getmax(arr[j+1][i],arr[j][i-1]);

    }
}

cout<<"\nSolution is "<<arr[0][n-1];


}
