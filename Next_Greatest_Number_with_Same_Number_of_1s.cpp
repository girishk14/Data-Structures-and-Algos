/*

This program uses bitwise manipulation to find the next greatest number with the same number of 1

@Author : Girish

*/


#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{


    int n, temp;

    cin>>n;
    int cnt = 0;
    temp =n;
    int a = 1;
    while(temp&1!=0)
    {
        temp>>=1;
        cnt++;
    }

    cout<<n + pow(2,cnt-1);

}
