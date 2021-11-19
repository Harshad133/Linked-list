#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node* insert(struct node *start,int value)
{
    struct node *t,*p;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=value;
    t->next=NULL;
    if(start==NULL)
    {
        start=t;
        return(start);
    }
    p=start;
    while(p->next!=NULL)
        p=p->next;
    p->next=t;
    return(start);
}

void display(struct node *start)
{
    struct node *t;
    t=start;
    printf("\n\n");
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}

int countNode(struct node *start)
{
    struct node *t=start;
    int count=0;
    while(t!=NULL)
    {
        t=t->next;
        count++;
    }
    return(count);
}

void middleNode(struct node *start)
{
    int n,i;
    struct node *t=start;
    if(start->next==NULL)
        printf("\n only one node available = %d", start->data);
    n=countNode(start);

    for(i=1; i!=n/2; i++)
        t=t->next;

    if(n%2==0)
    {
        printf("\ntotal number of node is even so two middle node available ::: \n\n");
        printf("midle node is %d ,%d ",t->data,t->next->data);
    }
    else
        printf("\nmiddle node is %d",t->next->data);
}

main()
{
    struct node *start=NULL;
    int i=1,v;

    printf("Enter the value :::  ");
    while(1)
        if(i==1)
        {
            printf("\nEnte value = ");
            scanf("%d",&v);
            start=insert(start,v);
            printf("\nDo you wish continue [1/0] = ");
            scanf("%d",&i);
        }
        else
            break;

    middleNode(start);
}