/*

Menu-driven program to add two polynomials

@Author : Girish Kumar

*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    float cf;  //coefficient
    int px; //power
    struct node* link;
};
typedef struct node* nodeptr;

nodeptr getnode()
{
    nodeptr temp;
    temp=(nodeptr)malloc (sizeof(struct node));
    return temp;
}

nodeptr create_poly(float c,int x,nodeptr head)
{
    nodeptr temp,cur;
    temp=getnode();
    temp->cf=c;
    temp->px=x;
    cur=head->link;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
    return head;
}
nodeptr add_poly(nodeptr first, nodeptr second)
{   float x;
    nodeptr head;
    int flag = 0;
    nodeptr t1 = first->link;
    nodeptr t2 = second->link;
    nodeptr t;
    head=getnode();
    head->link = head;

    while(t1!=first) //Inserting the nodes that have coeffs in both lists, and the distinct coeff nodes of list 1
    {
        t2 = second->link;
        flag = 0;
        for(t2;t2!=second;t2=t2->link)
        {
        if(t1->px==t2->px)
        {
            flag = 1;
            x = t1->cf + t2->cf;
            head = create_poly(x, t1->px,head);
        }
        }

        if(flag==0)
       head = create_poly(t1->cf,t1->px,head);

        t1 = t1->link;
    }


   t2 = second->link;
    while(t2!=second) //Inserting distinct coeff nodes of list 2
    {
        t1 = first->link;
        flag = 0;
        for(t1;t1!=first;t1=t1->link)
        if(t2->px==t1->px)flag = 1;


        if(flag==0)
        head = create_poly(t2->cf,t2->px,head);

        t2 = t2->link;
    }

        t = head->link;
      while(t!=head)
    {
         printf("%f x^%d  +  ", t->cf, t->px);
        t= t->link;
    }

}

int main()
{
    nodeptr one,two,sum;
    int x;
    int y=0;
    float c;
    one=getnode();
    two=getnode();
    sum=getnode();
    one->link=one;
    two->link=two;
    sum->link=sum;

    printf("1.enter first poly 2.enter second poly 3. add and display 4.exit");
    while(y!=4)
    {
        printf("enter choice");
        scanf("%d",&y);
        switch(y)
        {
          case 1:   printf("enter coefficient of x");
                    scanf("%f",&c);
                    printf("enter power of x");
                    scanf("%d",&x);
                    one=create_poly(c,x,one);
                    break;

        case 2:     printf("enter coefficient of x");
                    scanf("%f",&c);
                    printf("enter power of x");
                    scanf("%d",&x);
                    two=create_poly(c,x,two);
                    break;

        case 3:     sum=add_poly(one,two);



        }

    }

    return 0;
}
