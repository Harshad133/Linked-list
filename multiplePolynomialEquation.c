#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Poly
{
    int coff;
    int power;
};
struct node
{
    struct Poly *p;
    struct node *next;
};
struct node* delete(struct node *s, struct node *x)
{
   struct node *r=x->next;
   x->next=r->next;
   free(r->p);
   free(r);
 return(s);
}

struct node* formatPoly( struct node  *start )
{
    struct node *t=start,*r=t->next,*x;
    for(t=start ; t!=NULL ; t=t->next)
    {
        x=t;
        for(r=t->next; r!=NULL; r=r->next)
        {
            if(r->p->power==t->p->power)
            {
                t->p->coff= t->p->coff+r->p->coff;
                start=delete(start,x);
                r=x;
            }
            x=r;
        }
    }
    return(start);
}
struct node* insert(struct node *start,int c,int po)
{
    struct node *t=start,*temp;
    temp=(struct node*) malloc(sizeof(struct node));
    temp->p=(struct Poly*) malloc(sizeof(struct Poly));
    temp->p->coff=c;
    temp->p->power=po;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        return(start);
    }
    while(t->next!=NULL)
        t=t->next;
    t->next=temp;

    return(start);
}

void display(struct node *start)
{
    struct node *t;
    t=start;
    int i=-5;
    printf("\n");
    for(i=0; t->next!=NULL; t=t->next)
        printf(" %dx^%d +",t->p->coff,t->p->power);

    if(t->p->power==0)
        printf(" %d ",t->p->coff);
    else
        printf(" %dx^%d ",t->p->coff,t->p->power);

}

struct node* sum(struct node *start, struct node *s)
{
    struct node *t,*r,*m=NULL;
    int c,k;
    for(t=start; t!=NULL; t=t->next)
    {
        for(r=s; r!=NULL; r=r->next)
        {
            c=t->p->coff*r->p->coff;
            k=t->p->power+r->p->power;
            m=insert(m,c,k);
        }
    }
    return(formatPoly(m));
}

int main()
{
    struct node *start=NULL,*s=NULL,*su=NULL;
    int  i=1;
    int p,c;
    printf("\nenter your first polynomial equation ::::\n\n");

    while(i!=0)
    {
        printf("\nCoefficient and Power = ");
        scanf("%d %d",&c,&p);
        start=insert(start,c,p);
        printf("\n Do you went to add outher tearm [Y/N] = ");
        scanf("%d",&i);
    }

    printf("\n\nyour first polynomial equation is :::: \n");
    display(start);
    i=1;
    printf("\n\nenter your second polynomial equation ::::\n\n");


    while(i!=0)
    {
        printf("\nCoefficient and Power = ");
        scanf("%d %d",&c,&p);
        s=insert(s,c,p);
        printf("\n Do you went to add outher tearm [Y/N] = ");
        scanf("%d",&i);
    }
    printf("\n\nyour Second polynomial equation is :::: \n");
    display(s);
    printf("\n\n multiple of polynomial equation is ::: \n");
    su=sum(start,s);
    display(su);
    return 0;
}