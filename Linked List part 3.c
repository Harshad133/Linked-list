#include<stdio.h>
#include<conio.h>

typedef struct
{
    int info;
    struct nod *link;
} nod;

nod *START=NULL;

nod* createNod()
{
    nod *n;
    n=( nod *)malloc(sizeof( nod));
    return(n);
}

int countNod()
{
    nod *t;
    int n=1;
    t=START;
    while(t->link!=NULL) {
        t=t->link;
        n++;
    }
    return(n);
}
void insertNod()
{
    nod *temp,*t,*r;
    int n=0,p=3, count=1;
    t=START;
    temp=createNod();
    printf("\nenter number = ");
    scanf("%d",&temp->info);
    if(START==NULL) {
        START = temp;
        temp->link=NULL;
    }
    else
    {
        n=countNod();
        if(p<=n)
        {
            while(count!=p) {
                r=t;
                t=t->link;
                count++;
            }
            temp->link=r->link;
            r->link=temp;
        }
        else
        {
            while(t->link!=NULL)
                t=t->link;
            t->link=temp;
            temp->link=NULL;
        }
    }
}

void deleteNod()
{
    nod *r,*t;
    int n=0, count=1,p=3;
    t=START;
    if(START==NULL)
        printf("\nlist is empty ::: \n");
    else
    {
        n=countNod();
       // printf("\n\n%d",n);
        if(p<=n) {
            while(count!=p) {
                r=t;
                t=t->link;
                count++;
            }
            r->link=t->link;
            free(t);
            t=NULL;
        }
        if(p>n)
            printf("\n\nplace is empty------->>");
    }
}
/*void deleteNod()
{
    struct nod *r;
    if(START==NULL)
        printf("\nlist is empty ::: \n");
    else
    {
        r=START;
        START=START->link;
        free(r);
    }
}
*/

void viewList()
{
    nod *t;
    if(START==NULL)
        printf("\nlist is empty\n");
    else
    {
        t=START;
        while(t!=NULL)
        {
            printf("%d ",t->info);
            t=t->link;
        }
    }
}

int menu()
{
    int ch;
    printf("\nEnter 1 :: Insertion in list");
    printf("\nEnter 2 :: deletion in list");
    printf("\nEnter 3 :: view list");
    printf("\nEnter 4 :: exit");

    printf("\nEnter your choice = ");
    scanf("%d",&ch);
    return(ch);
}

main()
{
    while(1)
    {
        switch(menu())
        {
        case 1:
            insertNod();
            break;
        case 2:
            deleteNod();
            break;
        case 3:
            viewList();
            break;
        case 4:
            exit(0);
        default :
            printf("chois  is not available ::----->");
        }
    }
}