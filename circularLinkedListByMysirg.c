#include<stdio.h>

struct nod
{
    int data;
    struct nod *next;
};

/*-----declaration of function-----*/

void display(struct nod *last);
struct nod* addtoempty(struct nod *last,int value);
struct nod* addatbig(struct nod *last,int value);
struct nod* addatend(struct nod *last,int value);
struct nod* addafter(struct nod *last,int n,int value);
struct nod* search(struct nod *last,int n);
struct nod* delete(struct nod *last,int value);
struct nod* createList(struct nod *last);

/*---------------------------------*/

struct nod* createList(struct nod *last)
{
    int n,v,i;
    struct nod *p;
    printf("\n\n\nenter how many values enter you = ");
    scanf("%d",&n);
    printf("\n\n\nenter first value of list = ");
    scanf("%d",&v);
    last=addtoempty(last,v);
    for(i=2; i<=n; i++)
    {
        printf("\n\n\nenter %d value = ",i);
        scanf("%d",&v);
        last=addatend(last,v);
    }
    return(last);
}

struct nod* delete(struct nod *last,int value)
{
    struct nod *t,*p;
    if(last==NULL) {
        printf("\n\nlist is empty\n\n");
        return(0);
    }
    if(last==last->next&&last->data==value)
    {
        free(last);
        last=NULL;
        return(last);
    }
    t=last->next;
    p=last;
    do
    {
        if(t->data==value)
            break;
        p=t;
        t=t->next;
    } while(t!=last->next);

    if(t==last->next) {
        printf("\n\nitem is not found\n\n");
        return(last);
    }
    p->next=t->next;
    if(t==last)
        last=p;
    free(t);
    t=NULL;
    return(last);
}

struct nod* search(struct nod *last,int n)
{
    struct nod *t;
    t=last->next;
    do
    {
        if(t->data==n)
            return(t);
        t=t->next;
    } while(t!=last->next);

    return(NULL);
}

struct nod* addafter(struct nod *last,int n,int value)
{
    struct nod *t,*p;
    t=search(last, n);
    p=(struct nod*) malloc(sizeof(struct nod));
    if(p==NULL) {
        printf("\n\nitem is not found\n\n");
        return(0);
    }
    p->data=value;
    p->next=t->next;
    t->next=p;
    if(t==last)
        last=p;
    return(last);
}

struct nod* addtoempty(struct nod *last,int value)
{
    struct nod *p;
    p=(struct nod*) malloc(sizeof(struct nod));
    p->data=value;
    last=p;
    last->next=last;
    return(last);
}

void display(struct nod *last)
{
    struct nod *t;
    if(last==NULL)
        printf("\n\nlist is empty-------->>\n\n");
    else
    {
        t=last->next;
        printf("\n\n");
        do
        {
            printf("%d ",t->data);
            t=t->next;
        } while(t!=last->next);
        printf("\n\n");
    }
}

struct nod* addatbig(struct nod *last,int value)
{
    struct nod *p;
    if(last==NULL)
    {
        last=addtoempty(last, value);
        return(last);
    }
    p=(struct nod*) malloc(sizeof(struct nod));
    p->data=value;
    p->next=last->next;
    last->next=p;
    return(last);
}

struct nod* addatend(struct nod *last,int value)
{
    struct nod *p;
    if(last==NULL)
        return(addtoempty(last, value));
    p=(struct nod*) malloc(sizeof(struct nod));
    p->data=value;
    p->next=last->next;
    last->next=p;
    last=p;
    return(last);
}

int menu()
{
    int ch;
    printf("\nEnter 1 :: add first nod in empty list");
    printf("\nEnter 2 :: display List");
    printf("\nEnter 3 :: insertion at beginning");
    printf("\nEnter 4 :: insertion at end");
    printf("\nEnter 5 :: insertion after a node");
    printf("\nEnter 6 :: delete nod");
    printf("\nEnter 7 :: create list");
    printf("\nEnter 8 :: exit");

    printf("\n\nEnter your choice = ");
    scanf("%d",&ch);
    return(ch);
}

main()
{
    int n,l;
    struct nod *last=NULL;
    while(1)
    {
        switch(menu())
        {
        case 1:
            printf("Enter first' value of List = ");
            scanf("%d",&n);
            last=addtoempty(last,n);
            break;
        case 2:
            display(last);
            break;
        case 3:
            printf("enter value = ");
            scanf("%d",&n);
            last=addatbig(last,n);
            break;
        case 4:
            printf("enter value = ");
            scanf("%d",&n);
            last=addatend(last,n);
            break;
        case 5:
            printf("which value after you insert value = ");
            scanf("%d",&n);
            printf("enter value = ");
            scanf("%d",&l);
            last=addafter(last,n,l);
            break;
        case 6:
            printf("enter which value delete you = ");
            scanf("%d",&n);
            last=delete(last,n);
            break;
        case 7:
            last=createList(last);
            break;
        case 8:
            exit(0);
            break;
        default :
            printf("chois  is not available ::----->");
        }
    }
}