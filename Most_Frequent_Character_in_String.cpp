//Given a string. Find a character with most number of occurrences. Write code and test case for same


#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int main()
{


    char str[20];
    cout<<"\n\nEnter the string";
    gets(str);

    static int count[256];
    int aval,i;

    for(i=0;i<strlen(str);++i)
    {
        aval = str[i];
        count[aval]++;
    }

    int max = 0,ctr;
    for(i=0;i<256;++i)
    {
        if(count[i]>max)
        {
            max = count[i];
            ctr = i;
        }

    }

    cout<<"\n\nThe Character with the greatest frequency is "<<(char)ctr;


}
