#include <iostream>

class node
{
public:
    node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int lungime;
    node* head;
    node* tail;
    LinkedList();
    void add(int data);
    void afisList();
};

LinkedList::LinkedList()
{
    this->lungime = 0;
    this->head = NULL;
    this->tail=NULL;
}

void LinkedList::add(int data)
{
    node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        this->lungime++;
    }
    else
    {
        tail->next=temp;
        tail=tail->next;
        this->lungime++;
    }
}

void LinkedList::afisList()
{
    node* temp = new node;
    int i = 1;
    temp=head;
    while(temp!=NULL)
    {
        cout <<"elementul "<< i << ": " << temp->data << std::endl;
        temp = temp->next;
        i++;
    }
}

int main()
{
    cout<<endl;
    LinkedList* list1 = new LinkedList();
    for (int i = 0; i < 8; ++i)
    {
        list1->add(rand() % 9);
    }
    list1->afisList();
    cout<<endl;
    node* temp = new node;
    temp=list1->head;
    unsigned int sum=0;
    while(temp!=NULL)
    {
        sum=sum+temp->data;
        sum=sum*10;
        temp=temp->next;
    }
    sum=sum/10;
    cout<<"Nr format din lista: "<<sum;
    return 0;
}
