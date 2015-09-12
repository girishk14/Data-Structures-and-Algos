#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(int s[],int top, int a,const int ctop)
{
    static int i=0;
    static int flag = 0;

    if(top==-1)
    {
    flag = 1;
    i = ctop;
    s[i--] = a;
    return;
    }

    else
    reverse(s,top-1,s[top],ctop);


    s[i--] = a;
}




int main()
{
 int stack[20];
 int top = -1;
 int a,i;
 printf("\n\nEnter the elements of the stack till -1  ");

 while(1)
 {

     scanf("%d",&a);

     if(a==-1)break;
     stack[++top] = a;
 }

 reverse(stack,top, stack[top],top);


 printf("\n\nDisplaying reversed stack . . . ");
 for(i=0;i<=top;++i)
 {
     printf("%d ",stack[i]);
 }
}
