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

void deletenode()
{
    if(head == NULL)
        return;
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    node* currNode = head;
    while (currNode->next && currNode->next->next != NULL)
    {
        currNode = currNode->next;
    }
    delete currNode->next;
    currNode->next = NULL;
}

int main()
{
    citire();
    for(int i=0; i<elem; i++)
        insertList(numere[i]);
    cout<<"Lista este formata din: ";
    afisList();
    cout<<"Stergerea ultimului element din lista: ";
    deletenode();
    afisList();
    return 0;
}
