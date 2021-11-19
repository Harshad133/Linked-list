#include<stdio.h>

typedef struct
{
    int info;
    struct nod *prev,*next;
} nod;
nod *start=NULL;

nod* createNod()
{
    nod *n;
    n=(nod*) malloc(sizeof(nod));
    return(n);
}

void insertNod()
{
    nod *temp;
    temp=createNod();
    printf("\n\n enter number = ");
    scanf(" %d",&temp->info);
    temp->prev=NULL;
    temp->next=NULL;

    if(start==NULL)
        start=temp;
    else
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
    }

}

void deleteNod()
{
    nod *r;

    if(start==NULL)
        printf("\n\nlist Is empty-------->\n\n");
    else
    {
        r=start;
        start=start->next;
        start->prev=NULL;
        free(r);
    }
}

void viewList()
{
    nod *r;
    r=start;
    printf("\n\n");
    while(r!=NULL) {
        printf(" %d",r->info);
        r=r->next;
    }
    printf("\n\n");
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