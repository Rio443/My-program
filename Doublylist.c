/*
    Create a doubly linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct Link
{
    int data;
    struct Link *rlink,*llink;
};typedef struct Link node;

node *start;

node *createnode()
{
    node *d;
    d=(node *)malloc(sizeof(node));
    printf("Enter value:");
    scanf("%d",&d->data);
    d->llink=NULL;
    d->rlink=NULL;
    return d;
}

void createlist(int n)
{
    node *l,*m;
    l=start;
    while(n!=0)
    {
        l=createnode();
        if(start==NULL)
        {
            start=l;
            m=l;
        }
        else{
            l->llink=m;
            m->rlink=l;
            m=m->rlink;
        }
        n--;
    }
}

void display()
{
    node *p;
    p=start;
    while (p!=NULL)
    {
        printf("%d,",p->data);
        p=p->rlink;
    }
    
}
int main()
{
    int n;
    printf("Enter the number limit:");
    scanf("%d",&n);
    createlist(n);
    printf("The linked list is....\n");
    display();
    return 0;
}

