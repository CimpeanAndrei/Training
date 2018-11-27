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
    void reverseList();
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

void LinkedList::reverseList()
{
    cout<<endl<<"Lista reversata: "<<endl;
    node *current;
    current=head;
    node *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next=prev;
        prev=current;
        current = next;
    }
    head = prev;
}

int main()
{
    cout<<endl;
    LinkedList* list1 = new LinkedList();
    for (int i = 0; i < 10; ++i)
    {
        list1->add(rand() % 15);
    }
    list1->afisList();
    list1->reverseList();
    list1->afisList();
    return 0;
}
