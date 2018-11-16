#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *head=NULL;
node *tail=NULL;

const int maxn=20;
int elem, numere[maxn] ;

void citire()
{
    cout<<"Cate elemente doriti sa contina lista: ";
    cin>>elem;
    cout<<endl;
    cout<<"Introduceti numerele de la tastatura: ";
    for(int i=0; i<elem;i++)
    {
        cout<<"v["<<i+1<<"]=";
        cin>>numere[i];
        cout<<endl;
    }

}

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

void afisList()
{
    node *tempc=new node;
    tempc=head;
    while(tempc!=NULL)
    {
        cout<<tempc->data<<" ";
        tempc=tempc->next;
    };
    cout<<endl;
}

node *newhead=NULL;
node *newtail=NULL;

void newlist()
{
    int sum;
    newhead=head;
    newtail=newhead;
    sum=newhead->data;
    node *i;
    for(i=head->next;i!=NULL;i=i->next)
    {
        node *temp=new node;
        sum=sum+i->data;
        temp->data=sum;
        newtail->next=temp;
        newtail=temp;
    }
}

void afisnewlist()
{
    node *temp=new node;
    temp=newhead;
    cout<<endl;
    cout<<"Noua lista: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    citire();
    for(int i=0; i<elem; i++)
        insertList(numere[i]);
    afisList();
    newlist();
    afisnewlist();
    return 0;
}
