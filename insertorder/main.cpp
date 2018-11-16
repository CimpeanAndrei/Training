#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

node *head=NULL;
node *tail=NULL;

void insertList(int x)
{
    node *ins=new node;
    ins->data=x;
    ins->next=NULL;
    if(head==NULL)
    {
        head=ins;
        tail=ins;
        ins=NULL;
    }
    else
    {
        tail->next=ins;
        tail=ins;
    }
}

void orderList()
{
    cout<<"Ascending order: "<<endl;
    node *j, *k;
    j=head;
    k=head->next;
    node *temp=new node;
    for(j=head;j!=NULL;j=j->next)
        for(k=j->next;k!=NULL;k=k->next)
            if(j->data>k->data)
                {
                    temp->data=j->data;
                    j->data=k->data;
                    k->data=temp->data;
                }
}

void afisList()
{
    node *tempc=new node;
    tempc=head;
    while(tempc!=NULL)
    {
        cout<<tempc->data<<endl;
        tempc=tempc->next;
    }
    cout<<endl;
}
/*
void insertListorder(int x)
{

    node *temp=new node;
    temp->data=x;
    temp->next=NULL;
    if(temp->data<head->data)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        node *i=NULL;
        node *prev=NULL;
        i=head->next;
        while(i!=NULL && i->data>temp->data)
        {
            prev=i;
            i=i->next;
        }
        temp->next=i;
        prev->next=temp;
    }
    */
}
void insertInAscorder(int x)
{
    node *new1=new node;
    node *temp;
    node *previous;
    new1->data=x;
    new1->next=NULL;
    if(x<head->data)
    {
        new1->next=head;
        head=new1;
    }
    else
    {
        previous = head;
        temp = head->next;
        while(temp!=NULL&&x>temp->data)
        {
            previous=temp;
            temp=temp->next;
        }
        if(temp == NULL)
        {
            previous -> next = new1;
        }
        else
        {
            new1->next=temp;
            previous->next=new1;
        }
    }
}

int main()
{
    int nrv, val[100];
    cout<<"Dati nr de valori pe care doriti sa le introduceti: ";
    cin>>nrv;
    for(int i=0;i<nrv;i++)
    {
        cout<<"v["<<i+1<<"]= ";
        cin>>val[i];
        insertList(val[i]);
    }
    orderList();
    afisList();
    cout<<"Da-ti o valoare ce doriti sa o inserati: ";
    int nr;
    cin>>nr;
    cout<<endl;
    insertInAscorder(nr);
    afisList();
    return 0;
}
