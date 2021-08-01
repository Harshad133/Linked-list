#include<stdio.h>
#include<conio.h>

struct nod
{
    int info;
    struct nod *link;
};
struct nod *START=NULL;

struct nod* createNod()
{
    struct nod *n;
    n=(struct nod *)malloc(sizeof(struct nod));
    return(n);
}

void insertNod()
{
    struct nod *temp,*t;
    temp=createNod();
    printf("\nenter number = ");
    scanf("%d",&temp->info);
    if(START==NULL) {
        START = temp;
        temp->link=NULL;
    }
    else
    {
        temp->link=START;
        START=temp;
    }
}

void deleteNod()
{
    struct nod *r,*t;
    t=START;
    if(START==NULL)
        printf("\nlist is empty ::: \n");
    if(START->link==NULL) {
        free(START);
        START=NULL;
    }
    else
    {
        while(t->link!=NULL) {
            r=t;
            t=t->link;
        }
        //printf("\n%d",r->info);
        free(r->link);
        t=NULL;
        r->link=NULL;
    }
}


void viewList()
{
    struct nod *t;
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