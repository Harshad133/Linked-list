#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
private:
    int data;
    Node *next,*prev;

public:
    Node* insert(Node *start,int v);
    Node* display(Node *start);
    Node* reverse(Node *start);
};
Node* Node:: insert(Node *start,int v)
{
    Node *t=start,*p;
    p=(Node*)malloc(sizeof(Node));
    p->data=v;
    p->next=NULL;
    if(start==NULL)
    {
        start=p;
        p->prev=NULL;
        return(start);
    }
    while(t->next!=NULL)
        t=t->next;

    t->next=p;
    p->prev=t;
    return(start);
}
Node* Node:: display(Node *start)
{
    Node *t=start;
    if(start==NULL)
    {
        cout<<"\n list is empty :::: ";
        //  cout<<"\nhewlo";
        return(0);
    }
    cout<<endl;
    while(t!=NULL)
    {
        //cout<<"\nhewlo";
        cout<<t->data<<" ";
        t=t->next;
    }
}
Node* Node:: reverse(Node *start)
{
    Node *last,*t=start,*r=start;
    int d;
    while(r->next!=NULL)
        r=r->next;

    for(t=start; t!=r; t=t->next,r=r->prev)
    {
        d=t->data;
        t->data=r->data;
        r->data=d;
    }
    return(start);
}

int main()
{
    Node *start=NULL;
    int i=1,data;
    while(i!=0)
    {
        cout<<"\n\nenetr value = ";
        cin>>data;
        start=start->insert(start,data);
        cout<<"\nDo you went enter further information [1/0]= ";
        cin>>i;
    }
    cout<<"\n\n original list :::: ";
    start->display(start);
    start=start->reverse(start);
    cout<<"\n\nafter reverse list :::: ";
    start->display(start);
    return 0;
}