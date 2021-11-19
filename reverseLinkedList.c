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

struct node* reverse(struct node *start)
{
    struct node *t=start,*last,*p=NULL;
    while(t->next!=NULL)
        t=t->next;
    last=t;

    while(1)
    {
        t=start;
        p=NULL;
        while(t->next!=NULL)
        {
            p=t;
            t=t->next;
        }
        if(start->next==NULL)
            break;
        t->next=p;
        p->next=NULL;
    }
    start=last;
    last=NULL;
    return(start);
}

main()
{
    int n,i,v;
    struct node *start=NULL;
    printf("how many item enter you = ");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        printf("Ente %d element = ",i);
        scanf("%d",&v);
        start=insert(start,v);
    }
    printf("\n original list ::: ");
    display(start);
    printf("\n reverse list ::: ");
    start=reverse(start);
    display(start);
}

