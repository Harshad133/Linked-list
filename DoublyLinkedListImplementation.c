#include<stdio.h>
struct nod
{
    int info;
    struct nod *prev,*next;
};

struct nod *start=NULL;

struct nod* createNod()
{
    struct nod *n;
    n=(struct nod*) malloc(sizeof(struct nod));
    return(n);
}
void insertNod()
{
    struct  nod *temp,*t;
    t=start;
    temp=createNod();
    temp->next=NULL;
    printf("enter number = ");
    scanf("%d",&temp->info);

    if(start==NULL) {
        start=temp;
        temp->prev=NULL;
    }
    else
    {
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
        temp->prev=t;
    }

}

void insertion()
{
    struct nod *temp,*t,*r;
    t=start;
    int v;
    printf("which value after you insert Nod = ");
    scanf("%d",&v);

    temp=createNod();
    printf("enter number = ");
    scanf("%d",&temp->info);

    while(t->info!=v)
        t=t->next;
    r=t->next;
    t->next=temp;
    temp->prev=t;
    r->prev=temp;
    temp->next=r;
}

int  search(int s)
{
    int i,c=0;
    struct nod *t;
    t=start;
    for(i=1; t!=NULL; i++)
    {
        if(t->info==s)
            return(i);
        t=t->next;
    }
    if(c==0)
        printf("\nitem is not available ----->");
}

void deleteLastNod()
{
    struct nod *t,*r;
    t=start;
    if(start==NULL)
        printf("\n\nlist is empty ------>>\n\n");

    else
    {
        if(start->next==NULL) {
            free(start);
            start=NULL;
        }
        else {
            while(t->next!=NULL)
                t=t->next;
            t=t->prev;
            free(t->next);
            t->next=NULL;
        }
    }
}

void deletions()
{
    struct nod *t;
    t=start;
    int v,i;

    if(start==NULL)
        printf("\n\nList is empty\n\n");
    else
    {
        printf("\n\nenter value which you delete = ");
        scanf("%d",&v);
        for(i=1; t->info!=v; i++)
            t=t->next;
        t->prev->next=t->next;
        t->next->prev=t->prev;
        free(t);
        t=NULL;
    }
}
void viewList()
{
    struct  nod *r;
    r=start;
    printf("\n\n");
    if(start==NULL)
        printf("list is empty ----->>\n\n");
    else {
        while(r!=NULL) {
            printf(" %d",r->info);
            r=r->next;
        }
        printf("\n\n");
    }
}

int menu()
{
    int ch;
    printf("\nEnter 1 :: Insertion in list");
    printf("\nEnter 2 :: Insertion in any palase");
    printf("\nEnter 3 :: view list");
    printf("\nEnter 4 :: Search item");
    printf("\nEnter 5 :: delete Last node");
    printf("\nEnter 6 :: deletion at any palase");
    printf("\nEnter 7 :: exit");
    printf("\n\nEnter your choice = ");
    scanf("%d",&ch);
    return(ch);
}

main()
{
    int n;
    while(1)
    {
        switch(menu())
        {
        case 1:
            insertNod();
            break;
        case 2:
            insertion();
            break;
        case 3:
            viewList();
            break;
        case 4:
            printf("\n\nenter which value you search = ");
            scanf("%d",&n);
            printf("value found at node no =  %d",search(n));
            break;
        case 5:
            deleteLastNod();
            break;
        case 6:
            deletions();
            break;
        case 7:
            exit(0);
            break;
        default :
            printf("chois  is not available ::----->");
        }
    }
}